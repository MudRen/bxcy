//xiansheng.c

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

string ask_buy();
string ask_job();
int  do_copy(string arg);
int  working(object me);
int  halt_working(object me);

void create()
{
        set_name("编书先生", ({ "bianshu xiansheng", "xiansheng" ,"sheng" }));
        set("long", "编书先生饱读诗书，所以才可以担当起编书的重任。\n");
        set("gender", "男性");
        set("age", 65);
        set("no_get", 1);
        set_skill("literate", 300);
        set_skill("unarmed", 280);
        set_skill("dodge", 280);
        set_skill("parry", 280);
        set_temp("apply/attack", 280);
        set_temp("apply/defense", 280);
        set_temp("apply/damage", 220);

        set("combat_exp", 400000);
        set("shen_type", 1);
        set("inquiry", ([
            "工作" : (: ask_job :),
            "抄书" : (: ask_job :),
            "job"  : (: ask_job :),
            "书"   : "唉！书到用时方恨少。",
            "借书" : "借？你不还我到哪里找你？哼！",
        ]));
       
        setup();
        carry_object("/clone/misc/cloth")->wear();

        set("chat_chance", 1);
        set("chat_msg", ({
                "先生说道：普天之下，莫非王土；率土之滨，莫非王臣。\n",
                "先生说道：出家人，小过损益焉；无妄大过，未济咸困之。\n",
        }) );
}

void init()
{
        add_action("do_copy", "copy");
        }


string ask_job()
{
        object me;

        me = this_player();
        if (me->query_temp("job/copy"))
                return "让你抄的书你抄完了？";

        if (me->query("combat_exp") < 120)
                return "虽然我这里只是抄抄书，可是你战斗经验这么差，要"
                       "是有小流氓捣乱你怎么办？";

        if (me->query("combat_exp") > 5000000)
                return "大侠你也来抄书？真是屈就您了，慢走啊！";

        if (me->query("qi") < 20)
                return "我看你脸色不行啊，先歇会儿吧，我可不想抄书抄出人命来。";

        if (me->query("jing") < 10)
                return "我看你精神不行啊，能抄得了书么？";

        if (me->query_int() < 20 && me->query_skill("literate", 1) < 1)
                return "我说你脑子这么笨！也来抄书？";

        me->set_temp("job/copy", 1);
        return "好，你就帮我抄书(copy)吧！笔墨纸砚在这儿。";
}

int do_copy(string arg)
{
        object me;

        me = this_player();
        if (me->is_busy())
                return notify_fail("你正忙着呢，别着急。\n");

        if (! me->query_temp("job/copy"))
        {
                message_vision("$N摸起毛笔，刚想蘸墨，就听见$n大喝道："
                               "给我放下，别乱动文房四宝。\n",
                               me, this_object());
                return 1;
        }

        me->set_temp("job/step", 1);
	me->start_busy((: working :), (: halt_working :));
        tell_object(me, "你开始工作。\n");
        return 1;
}

int working(object me)
{
        string msg;
        int finish;
        int b;

        if (! me->query_temp("job/step"))
                me->set_temp("job/step", 1);

        if (! living(me))
        {
                me->delete_temp("job/copy");
                me->delete_temp("job/step");
                return 0;
        }

        finish = 0;
        me->receive_damage("jing", 1);
        me->receive_damage("qi", 2);
        switch (me->query_temp("job/step"))
        {
        case 1:
                msg = "$N拿过砚台，慢慢地研墨。";
                break;
        case 2:
                msg = "$N看看墨磨得差不多了，摸起毛笔，轻轻哈了两口气。";
                break;
        case 3:
                msg = "$N饱蘸墨汁，翻开四书，摊开纸张，开始誊写。";
                break;
        case 4:
        case 6:
                msg = "$N聚精会神的抄写书籍。";
                break;
        case 5:
                msg = "$N蘸了蘸墨，继续仔细地抄写。";
        case 7:
                msg = "$N不断翻动着书籍，纸张越来越厚。";
                break;
        default:
                msg = "$N把书籍抄好，将纸上墨吹干，装订成册，递给$n。";
                finish = 1;
                break;
        }
        msg += "\n";

        if (finish)
        {
                object ob;
                msg += "$n看了$N抄写的书，满意道：还行，儒子可教！\n";
                me->delete_temp("job/copy");
                me->delete_temp("job/step");

                b = 20 + random(10);
                me->add_temp("mark/朱", 20);
                me->add("combat_exp", b);
                me->add("potential", (b + 2) / 5);
                me->improve_skill("literate", (b + 1) * 10);
                ob = new("/clone/money/gold");
                ob->set_amount(random(2));
                ob->move(this_object());
        }

	msg = replace_string(msg, "$N", "你");
	msg = replace_string(msg, "$n", name());
	tell_object(me, msg);

        if (finish)
        {
                if (b > 0)
                {
                        tell_object(me, HIC "\n你获得了" +
                                    chinese_number(b) +
                                    "点经验和" +
                                    chinese_number((b + 2) / 5) +
                                    "点潜能。\n\n" NOR);
                }
                command("give gold to " + me->query("id"));
                return 0;
        }

        me->add_temp("job/step", 1);
        return 1;
}

int halt_working(object me)
{
        message_vision("$N把手中的笔墨纸砚丢到一旁，牢骚道："
                       "什么呀，根本就不是人干的活！\n", me);
        me->delete_temp("job/copy");
        me->delete_temp("job/step");
        return 1;
}

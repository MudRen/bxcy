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
        set_name("��������", ({ "bianshu xiansheng", "xiansheng" ,"sheng" }));
        set("long", "������������ʫ�飬���Բſ��Ե������������Ρ�\n");
        set("gender", "����");
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
            "����" : (: ask_job :),
            "����" : (: ask_job :),
            "job"  : (: ask_job :),
            "��"   : "�����鵽��ʱ�����١�",
            "����" : "�裿�㲻���ҵ��������㣿�ߣ�",
        ]));
       
        setup();
        carry_object("/clone/misc/cloth")->wear();

        set("chat_chance", 1);
        set("chat_msg", ({
                "����˵��������֮�£�Ī������������֮����Ī��������\n",
                "����˵���������ˣ�С�������ɣ����������δ������֮��\n",
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
                return "���㳭�����㳭���ˣ�";

        if (me->query("combat_exp") < 120)
                return "��Ȼ������ֻ�ǳ����飬������ս��������ô�Ҫ"
                       "����С��å��������ô�죿";

        if (me->query("combat_exp") > 5000000)
                return "������Ҳ�����飿�����������ˣ����߰���";

        if (me->query("qi") < 20)
                return "�ҿ�����ɫ���а�����Ъ����ɣ��ҿɲ��볭�鳭����������";

        if (me->query("jing") < 10)
                return "�ҿ��㾫���а����ܳ�������ô��";

        if (me->query_int() < 20 && me->query_skill("literate", 1) < 1)
                return "��˵��������ô����Ҳ�����飿";

        me->set_temp("job/copy", 1);
        return "�ã���Ͱ��ҳ���(copy)�ɣ���īֽ���������";
}

int do_copy(string arg)
{
        object me;

        me = this_player();
        if (me->is_busy())
                return notify_fail("����æ���أ����ż���\n");

        if (! me->query_temp("job/copy"))
        {
                message_vision("$N����ë�ʣ�����պī��������$n��ȵ���"
                               "���ҷ��£����Ҷ��ķ��ı���\n",
                               me, this_object());
                return 1;
        }

        me->set_temp("job/step", 1);
	me->start_busy((: working :), (: halt_working :));
        tell_object(me, "�㿪ʼ������\n");
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
                msg = "$N�ù���̨����������ī��";
                break;
        case 2:
                msg = "$N����īĥ�ò���ˣ�����ë�ʣ����������������";
                break;
        case 3:
                msg = "$N��պī֭���������飬̯��ֽ�ţ���ʼ��д��";
                break;
        case 4:
        case 6:
                msg = "$N�۾�����ĳ�д�鼮��";
                break;
        case 5:
                msg = "$Nպ��պī��������ϸ�س�д��";
        case 7:
                msg = "$N���Ϸ������鼮��ֽ��Խ��Խ��";
                break;
        default:
                msg = "$N���鼮���ã���ֽ��ī���ɣ�װ���ɲᣬ�ݸ�$n��";
                finish = 1;
                break;
        }
        msg += "\n";

        if (finish)
        {
                object ob;
                msg += "$n����$N��д���飬����������У����ӿɽ̣�\n";
                me->delete_temp("job/copy");
                me->delete_temp("job/step");

                b = 20 + random(10);
                me->add_temp("mark/��", 20);
                me->add("combat_exp", b);
                me->add("potential", (b + 2) / 5);
                me->improve_skill("literate", (b + 1) * 10);
                ob = new("/clone/money/gold");
                ob->set_amount(random(2));
                ob->move(this_object());
        }

	msg = replace_string(msg, "$N", "��");
	msg = replace_string(msg, "$n", name());
	tell_object(me, msg);

        if (finish)
        {
                if (b > 0)
                {
                        tell_object(me, HIC "\n������" +
                                    chinese_number(b) +
                                    "�㾭���" +
                                    chinese_number((b + 2) / 5) +
                                    "��Ǳ�ܡ�\n\n" NOR);
                }
                command("give gold to " + me->query("id"));
                return 0;
        }

        me->add_temp("job/step", 1);
        return 1;
}

int halt_working(object me)
{
        message_vision("$N�����еı�īֽ�ⶪ��һ�ԣ���ɧ����"
                       "ʲôѽ�������Ͳ����˸ɵĻ\n", me);
        me->delete_temp("job/copy");
        me->delete_temp("job/step");
        return 1;
}

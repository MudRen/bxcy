// yufu.c 老渔夫
#include <ansi.h>
inherit NPC;
inherit F_DEALER;
void goto_matou2(object ob);
void create()
{
        set_name("老渔夫", ({ "lao yufu","yufu" }));
        set("gender", "男性");
        set("age", 56);
        set("long",
                "这是一个老渔夫。饱经风霜的脸上什么也看不出来。\n",
        );
        set("combat_exp", 10000000);
        set("str",800);
        set("max_neili", 10000);
        set("neili", 1000000);
        set("jiali", 500);
        set("jing", 5000);
        set("max_jing", 5000);
        set("max_jingli", 20000);
        set("jingli", 20000);
        set_skill("force", 1000);
        set_skill("unarmed", 1000);
        set_skill("dodge", 1000);
        set_skill("parry", 1000);
        set_skill("whip", 1000);
        set_skill("yunlong-bian", 1000);
        set_skill("yunlong-shenfa", 1000);
        set_skill("yunlong-shengong", 1000);
        set_skill("houquan", 1000);
        map_skill("parry", "yunlong-bian");
        map_skill("whip", "yunlong-bian");
        map_skill("force", "yunlong-shengong");
        map_skill("dodge", "yunlong-shenfa");
        map_skill("unarmed", "houquan");

        set("chat_chance_combat", 60);
        set("inquiry", ([
        "过江" : "对岸很危险的，又有鳄鱼，又有火龙。太危险了。\n",
        "火龙" : "火龙的筋可以做成火龙鞭。不过听说还要几样东西才可以做成。\n",
      "火龙鞭" : "听上几辈的老人说，火龙鞭的柄是千年寒玉，鞭是由火龙筋和雪蚕丝绞成的。\n"+
                 "可厉害呐！不过我不会做。听说在川里有个人会做。\n",
        ]));
        set("chat_msg_combat", ({
           (: perform_action, "whip.chan" :),
           (: exert_function, "powerup" :),
        }) );
        set("vendor_goods", ({
                __DIR__"obj/liyu",
                __DIR__"obj/changyu",
        }));



        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/yugang")->wield();
}
void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_list", "list");
        add_action("do_buy", "buy");

}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
                        say( "老渔夫笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，想买鱼还是想过江啊？\n");
}
int accept_object(object who, object ob)
{
        int time;
    if (ob->query("money_id") && ob->value() >= 20000)
        {
        time = ob->value() / 100;
        time = 5000 / time;
        if(time < 6)
                time = 6;
        message_vision("老渔夫对$N说：好！这位" + RANK_D->query_respect(who) + "请上船吧。\n" , who);
        who->move ("/d/quanzhen/yangpifa");
                call_out("goto_matou2", time, who) ;
        return 1;
        }
    else  
                message_vision("老渔夫皱眉对$N说：您给的也太少了吧？\n", who);
        return 0;
}
void goto_matou2(object ob)
{
        if (!ob)        return;
        tell_object(ob, "羊皮筏子终于到岸了。你跳了下来。\n" ) ;
   ob->move ("/d/heimuya/zhaoze/huozhao.c") ;
}


// beggar.c

inherit NPC;

void create()
{
        set_name("水手", ({ "shuishou" }) );
        set("gender", "男性" );
        set("age", 23);
        set("long", "一个正在摆摆样子，以搏情调的千金楼家奴\n");
        set("combat_exp", 100);
        set("str", 27);
        set("neili", 200);
        set("attitude", "friendly");
        set("max_neili", 200);
        set("jiali", 2);
        setup();
        set("chat_chance", 5);
        set("chat_msg", ({
"水手向你笑了笑，又伸出手，象行礼，又象要赏钱．\n",
        }) );
        set("inquiry", ([
                "湖上八娇" : "哦，她们都住在荷花荡上\n",
        ]) );
        carry_object("/clone/misc/cloth")->wear();
}

int accept_object(object me, object obj)
{
        command("smile");
        command("say 多谢这位" + RANK_D->query_respect(me) + 
"，您一定会在这儿玩的开心的！");
        return 1;
}

void init()
{
        ::init();
        if( this_player()->query_temp("dalikill") )
        {
                 kill_ob(this_player());
        }
        add_action("do_kill","kill");
}

int do_kill(string arg)
{
        this_player()->set_temp("dalikill", 1);
        return 0;
}

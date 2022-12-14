// dizi2.c 弟子

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("黄衣弟子", ({ "di zi", "di", "zi" }));
        set("long", "这是三十多岁的壮汉，膀大腰圆，是岛主从中原招募来的。\n");

        set("gender", "男性");
        set("age", 30);
        set("shen_type",1);
        set("attitude", "peaceful");

        set("str", 200);
        set("int", 20);
        set("con", 20);
        set("dex", 200);

        set("qi", 50000);
        set("max_qi", 50000);
        set("jing", 2000);
        set("max_jing", 2000);
        set("neili", 300000);
        set("max_neili", 3000);
        set("jiali", 300);

        set("combat_exp", 30000000);
        set("score", 10);
        set_skill("force", 700);
        set_skill("unarmed", 700);
        set_skill("dodge", 700);
        set_skill("parry", 700);
        set_skill("hand", 700);
        set_skill("staff", 500);
        create_family("侠客岛", 2, "弟子");

        setup();
        carry_object(__DIR__"obj/ycloth")->wear();
}

void init()
{
        object ob;

        ::init();
        ob = this_player();
        if( interactive(ob) && !ob->is_fighting() )
        {
            remove_call_out("greeting");
            call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        object room;
        room = find_object("/d/xiakedao/shanmen");

        if( !ob || environment(ob) != environment()
                || environment() != room)
                return;

        switch( random(2) )
        {
                case 0:
                        say( "侠客岛弟子说道：这位" + RANK_D->query_respect(ob)
                                 + "，欢迎欢迎。\n");
                        break;
                case 1:
                        say( "侠客岛弟子恭手说道：这位" + RANK_D->query_respect(ob)
                                 + "，小弟这厢有礼了。\n");
                        break;
        }
}

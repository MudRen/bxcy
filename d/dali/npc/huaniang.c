// huaniang.c 花娘

#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void create()
{
        set_name(HIM"花娘"NOR, ({ "hua niang", "hua", "niang" }) );
        set("title", "飘香花店老板");
        set("gender", "女性");
        set("age",20);
        set("long",
                "这位姑娘是这间花店的老板，长得美丽而且温柔可人，难怪大理的小伙子都想娶她过门。 \n");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/damage", 15);
        set("combat_exp", 40000);
        set("attitude", "friendly");
        set("vendor_goods", ({
                __DIR__"obj/chahua1", 
                __DIR__"obj/chahua2", 
                __DIR__"obj/chahua3", 
                __DIR__"obj/chahua4", 
                __DIR__"obj/chahua5", 
                __DIR__"obj/chahua6", 
                __DIR__"obj/chahua7", 
                __DIR__"obj/chahua8", 
                __DIR__"obj/chahua9",
                __DIR__"obj/chahua10", 
                __DIR__"obj/chahua11", 
                __DIR__"obj/chahua12", 
                __DIR__"obj/chahua13", 
        }));
        setup();
        carry_object("/clone/misc/cloth")->wear();

}
void init()
{       
        object ob; 
        ob = this_player();

        ::init();
        if( interactive(ob) && !is_fighting() ) 
                    {
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
                    } 
        if( this_player()->query_temp("dalikill") )
        {
                 kill_ob(ob);
        }

        add_action("do_buy", "buy");
        add_action("do_list", "list");
        add_action("do_kill","kill");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
 say( HIM"花娘"NOR"笑咪咪地说道：这位" + RANK_D->query_respect(ob)
 + "，买枝茶花送给你的心上人吧。\n");
                        break;
                case 1:
say( HIM"花娘"NOR"自豪地说，方圆百里就数我这间花店的茶花最名贵，最好的了。\n");
                        break;
        }
}

int do_kill(string arg)
{
        this_player()->set_temp("dalikill", 1);
        return 0;
}
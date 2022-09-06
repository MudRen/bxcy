// waiter.c
inherit NPC;
void create()
{
        set_name("店小二", ({ "xiao er", "xiao", "waiter" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long",
                "这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("rank_info/respect", "小二哥");
        setup();
          carry_object("/clone/misc/cloth2")->wear();
}
void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，要住店吗？请进请进。\n");
                        break;
                case 1:
                        say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。小店还有几间上好的房间。\n");
                        break;
        }
}
int accept_object(object who, object ob)
{
        
        if (ob->query("money_id") && ob->value() >= 100) 
        {
                tell_object(who, "小二一哈腰，说道：多谢您老，客官请上楼歇息。\n");
                who->set_temp("rent_paid",1);
                return 1;
        }
        return 0;
}


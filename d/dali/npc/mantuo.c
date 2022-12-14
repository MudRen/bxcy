// mantuo.c 曼陀
//date 一天

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("曼陀", ({ "man tuo", "man", "waiter" }) );
        set("gender", "女性" );
        set("age", 22);
        set("long",
                "这位大理姑娘忙出忙入，招呼着来来往往的客人。\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("vendor_goods", ({
                "/d/city/obj/jitui",
                "/d/city/obj/jiudai",
                "/d/city/obj/baozi",
                "/d/city2/obj/mian",
        }));
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{       
    object ob,me; 
    mapping myfam; 
    ob = this_player();
    ::init();
    if( interactive(ob) && !is_fighting() ) {
                if ( (myfam = ob->query("family")) 
                && myfam["family_name"] == "丐帮" 
            && ob->query_skill("begging",1) > 60 ){
                        remove_call_out("saying");
                        call_out("saying", 0, ob);
                }else { 
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
        }
        if( this_player()->query_temp("dalikill") )
        {
                 kill_ob(this_player());
        }
        add_action("do_buy", "buy");
        add_action("do_list", "list");
        add_action("do_kill","kill");
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                        say( "曼陀笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来吃碗面，歇歇腿吧。\n");
                        break;
                case 1:
                        say( "曼陀用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
                case 2:
                        say("曼陀自言自语道：唉！真够忙的，生意越来越好。要请个帮手才行了.\n");
                        break;
        
}
}

void saying(object ob)
{
        if (!ob || environment(ob) != environment()) return;
        say("\n曼陀大喝一声：你这臭要饭的进来干什麽？ 给我滚出去！\n\n");
        remove_call_out("kicking");
        call_out("kicking", 1, ob);
        
}
void kicking(object ob)
{
        if (!ob || environment(ob) != environment()) return;
        ob->move("/d/dali/dbdajie1");
        message("vision","只听“乒”地一声，" +  ob->query("name") +
                "被人从小店里一脚踢了出来，狼狈万状的逃开了。\n", environment(ob), ob);
}


int do_kill(string arg)
{
        this_player()->set_temp("dalikill", 1);
        return 0;
}
// xiaoer2.c 酒店小二

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("小狗子", ({ "xiao gouzi", "gouzi", "waiter" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
	set("vendor_goods", ({
		__DIR__"obj/jitui",
		__DIR__"obj/jiudai",
		__DIR__"obj/baozi",
                __DIR__"obj/piang",
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{	
	object ob; 
	mapping myfam; 

	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() ) {
		if ( (myfam = ob->query("family")) 
		&& myfam["family_name"] == "丐帮" 
		&& ob->query_skill("begging",1) > 10 )
		{
			remove_call_out("saying");
			call_out("saying", 0, ob);
		}
		else
		{ 
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
                if ( this_object()->environment() == "/d/city3/jiulou2" && ob->query_temp("dian")){
                    say( "小狗子笑咪咪地说道：好的！这位" + RANK_D->query_respect(ob)+ "请稍等。菜马上就上。\n");
                    call_out("do_shangcai", 100,ob,this_object());
                    }
	}

	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
                        say( "小狗子笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，欢迎光临银杏酒楼。\n");
			break;
		case 1:
                        say( "小狗子用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
                                + "，请坐请坐。\n");
			break;
	}
}

void saying(object ob)
{
        if (!ob || environment(ob) != environment()) return;

        say("\n小狗子大喝一声：你这臭要饭的进来干什麽？ 给我滚出去！\n\n");
	remove_call_out("kicking");
	call_out("kicking", 1, ob);
	
}

void kicking(object ob)
{
        if (!ob || environment(ob) != environment()) return;

	ob->move("/d/city/beidajie2");
	message("vision","只听“乒”地一声，" +  ob->query("name") +
		"被人从银杏酒楼里一脚踢了出来，狼狈万状的逃开了。\n", environment(ob), ob);
}

// wangerniang.c 王二娘

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("王二娘", ({ "wang erniang", "wang", "erniang" }) );
	set("gender", "女性" );
	set("age", 53);
	set("long",
		"她看来有50多岁了，但是徐娘半老，风韵尤存。\n据说跟几个老光棍还不清不楚的。\n");
	set("combat_exp", 7000);
	set("attitude", "friendly");
	set("rank_info/respect", "王二娘");
	set("vendor_goods", ({
		__DIR__"obj/jiudai",
                "/d/city/obj/jiaohuaji",
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",20);
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
	}

	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "王二娘笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，你想要些什么？\n");
			break;
		case 1:
			say( "王二娘笑嘻嘻地看着你，说道：这位" + RANK_D->query_respect(ob)
				+ "，请进请进。\n");
			break;
	}
}

void saying(object ob)
{
        if (!ob || environment(ob) != environment()) return;

	say("\n王二娘恶狠狠地骂到；“滚，别来干扰老娘的好事。\n\n");
	remove_call_out("kicking");
	call_out("kicking", 1, ob);
	
}

void kicking(object ob)
{
        if (!ob || environment(ob) != environment()) return;

        ob->move("/d/city3/xiaojie3");
	message("vision","只听“乒”地一声，" +  ob->query("name") +
                "被人从酿酒屋一脚踢了出来，狼狈万状的逃开了。\n", environment(ob), ob);
}

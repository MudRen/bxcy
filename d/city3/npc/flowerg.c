inherit NPC;
inherit F_DEALER;
void create()
{
	set_name("卖花姑娘", ({ "flower girl","girl"}) );
	set("gender", "女性" );
	set("age", 18);
	set("long", "一个容貌清丽的小姑娘。\n");
	set("shen_type", 1);
	set("combat_exp", 5000);
	set("str", 20);
	set("dex", 18);
	set("con", 19);
	set("int", 20);
	set("attitude", "friendly");
	set("max_qi", 100);
	set("max_jing", 100);
	set("neili", 100);
	set("max_neili", 100);
	set("score", 1000);
	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 8);
	set_temp("apply/defense", 12);
	set_temp("apply/damage", 11);
	set_temp("apply/armor", 7);
        set("vendor_goods", ({
                __DIR__"obj/red_flower",
                __DIR__"obj/yellow_flower",
                __DIR__"obj/knq_flower",
        }) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_buy","buy");
	add_action("do_list","list");
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	     say("卖花姑娘说道：这位" + RANK_D->query_respect(ob)
	     + "，买一朵花吧。\n");
	return;
}

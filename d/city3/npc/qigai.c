// qigai.c 乞丐

inherit NPC;

void create()
{
        set_name("乞丐", ({ "qi gai", "qi" }));
	set("gender", "男性");
        set("age", 21);
        set("long", "他是一个成天东游西逛的乞丐，好象是丐帮的人。\n");
	
        set("combat_exp", 2000);
	set("shen_type", -1);

	set("attitude", "peaceful");
	
        set_skill("unarmed", 25);
        set_skill("dodge", 25);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",2);
}

// yiren.c  游方艺人

inherit NPC;

void create()
{
        set_name("游方艺人", ({ "Yi ren", "yi", "ren" }));
	set("gender", "男性");
        set("age", 25);
        set("long", "他是一个四海为家的游方艺人，每天辛苦地天南地北的外出献艺。\n");
	
        set("combat_exp", 1800);
        set("shen_type", 1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",2);
}

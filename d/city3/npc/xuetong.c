// xuetong.c 学童

inherit NPC;

void create()
{
        set_name("学童", ({ "xue tong", "xue", "tong" }));
	set("long", 
                "他是杜甫草堂的小学童。\n");
	set("gender", "男性");
	set("age", 16);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("str", 20);
	set("int", 20);
	set("con", 22);
	set("dex", 25);
	
        set("max_qi", 100);
        set("max_jing", 100);
        set("neili", 100);
        set("max_neili", 100);

        set("combat_exp", 1000);
        set("score", 50);

        set_skill("force", 5);
        set_skill("dodge", 5);
        set_skill("unarmed", 5);
        set_skill("parry", 5);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
	set_temp("apply/damage", 5);

	setup();
	
        carry_object("/clone/misc/cloth")->wear();
}

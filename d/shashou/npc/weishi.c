// menwei1.c



inherit NPC;

//string inquiry_dao();





void create()

{

        set_name("卫士", ({ "wei shi","wei" }) );

	set("gender", "男性" );



	set("age", 35);

       set("long", "杀手楼的卫士。\n");

	set("shen_type",1);

	set("combat_exp", 20000);



	set("attitude", "peaceful");



	set("apply/attack", 50);

	set("apply/defense", 50);





	set_skill("unarmed", 50);

//	set_skill("blade", 20);

	set_skill("parry", 40);

	set_skill("dodge", 50);



	setup();

	carry_object("/clone/misc/cloth")->wear();

//        carry_object("/d/mingjiao/obj/mutang")->wield();

	add_money("silver", 1);

}




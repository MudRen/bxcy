inherit NPC;

void create()
{
        set_name("杜二", ({ "Du er", "du" , "er" }));
        set("title","杜甫弟子");
        set("long", "杜二是杜甫的弟子，肚子里的墨水也不少。\n");
	set("gender", "男性");
        set("age", 45);

        set_skill("literate", 120);

        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
	set_temp("apply/damage", 20);

        set("combat_exp", 4000);
	set("shen_type", 1);
	setup();

	carry_object("/clone/misc/cloth")->wear();
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("mark/杜"))
		return 0; 
        ob->add_temp("mark/杜", -1);
	return 1;
}

int accept_object(object who, object ob)
{
        if (!(int)who->query_temp("mark/杜"))
                who->set_temp("mark/杜", 0);
        if (ob->query("money_id") && ob->value() >= 5000) {
                message_vision("杜二同意指点$N一些问题。\n", who);
                who->add_temp("mark/杜", ob->value() / 250);
		return 1;
	}
	return 0;
}

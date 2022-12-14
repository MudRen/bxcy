//cheng.c 陈明镜

inherit NPC;

void create()
{
 set_name("陈明镜", ({ "chen mingjing", "chen" }));
set("title", "大理知府");
	set("gender", "男性");
	set("age", 43);
	set("str", 20);
	set("dex", 20);
          set("long", "他就是陈明镜，大理城现任知府。\n");
	set("combat_exp", 30000);
	set("shen_type", 0);
	set("attitude", "heroism");

	set_skill("unarmed", 50);
	set_skill("force", 50);
	set_skill("sword", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 15);

	set("neili", 500); 
	set("max_neili", 500);
	set("jiali", 10);

	setup();
	carry_object(__DIR__"obj/gangjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        ::init();
        if( this_player()->query_temp("dalikill") )
        {
                 kill_ob(this_player());
        }
        add_action("do_kill","kill");
}

int do_kill(string arg)
{
        this_player()->set_temp("dalikill", 1);
        return 0;
}
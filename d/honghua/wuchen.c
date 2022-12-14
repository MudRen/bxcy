// wuchen.c 无尘道长

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	set_name("无尘道长", ({ "wuchen daozhang", "wuchen" }));
	set("long", 
		"他是红花会坐第二把交椅的无尘道长，\n"
		"红花会中数他剑法最好，\n"
		"他年纪好像在四十岁左右，身形瘦削，颌下胡须无风自动，脸上表情不怒自威。\n");
	set("gender", "男性");
	set("age", 44);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 25);
	set("int", 23);
	set("con", 26);
	set("dex", 27);
	set("max_qi", 2200);
	set("max_jing", 2000);
	set("neili", 2400);
	set("max_neili", 2400);
	set("jiali", 100);
        set("combat_exp", 3500000);
	set("score", 160000);
          set_skill("force", 300);
          set_skill("honghua-shengong",300);
          set_skill("dodge", 300);
          set_skill("youlong-shenfa", 300);
          set_skill("unarmed", 300);
          set_skill("parry",300);
          set_skill("sword",300);
          set_skill("luohua-jian",300);
        set_skill("literate",150);

	map_skill("force", "honghua-shengong");
	map_skill("dodge", "youlong-shenfa");
	map_skill("parry", "luohua-jian");
	map_skill("sword", "luohua-jian");

	create_family("红花会",2, "弟子");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();

}
/*
void init()
{
        object ob;

        ::init();

        ob = this_player();

        if((int)ob->query("shen") < -1000 && ob->query("family/master_id")=="wuchen daozhang")
        {
                command("chat "+ob->query("name")+"!你这等邪恶奸诈之徒，我岂能仍是你的师傅。\n");
                command("expell "+ ob->query("id"));
                this_player()->set("title","红花会" + RED + "弃徒" NOR);
        }
}
*/
void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") < 10000) {
		command("say 哼！");
		command("say 这位" + RANK_D->query_respect(ob) +
			"为人之道似乎不怎么样！");
		return;
	}
	command("say 不错，不错，我就收下你了！");
	command("recruit " + ob->query("id"));
        if( (string)ob->query("class") != "yishi")
                ob->set("class", "yishi");
}



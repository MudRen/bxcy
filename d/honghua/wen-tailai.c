// wen-tailai.c 文泰来

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
string ask_me();

void create()
{
	set_name("文泰来", ({ "wen tailai", "wen" }));
	set("nickname", HIM"奔雷手"NOR);
	set("long", 
                "他是红花会的四哥文泰来，\n"
		"身穿一件极为合体的青色长衫，\n"
		"他年纪好像在三十上下，身材十分槐梧，双手青筋突出，布满了老茧.\n");
	set("gender", "男性");
	set("age", 32);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
        set("max_qi", 2000);
        set("max_jing", 1500);
        set("neili", 2400);
	set("max_neili", 2400);
	set("jiali", 100);
                 set("combat_exp",800000);
	set("score", 100000);

        set_skill("force", 180);
        set_skill("honghua-shengong", 180);
        set_skill("dodge", 180);
        set_skill("youlong-shenfa", 180);
        set_skill("unarmed", 180);
        set_skill("baihuacuo-quan", 200);
        set_skill("parry", 180);
        set_skill("sword", 180);
        set_skill("luohua-jian", 180);
        set_skill("literate", 150);

	map_skill("force", "honghua-shengong");
	map_skill("dodge", "youlong-shenfa");
	map_skill("unarmed", "baihuacuo-quan");
	map_skill("parry", "luohua-jian");
	map_skill("sword", "luohua-jian");

	create_family("红花会", 2, "弟子");



	setup();
     this_player()->carry_object("/d/honghua/cloth")->wear();
}
/*
void init()
{
        object ob;

        ::init();

        ob = this_player();

        if((int)ob->query("shen") < -1000 && ob->query("family/master_id")=="wen tailai")
        {
                command("chat "+ob->query("name")+"!你这等邪恶奸诈之徒，我岂能仍是你的师傅。\n");
                command("expell "+ ob->query("id"));
                this_player()->set("title","红花会" + RED + "弃徒" NOR);
        }
}
*/
void attempt_apprentice(object ob)
{
        if ((int)ob->query("shen") < 5000) {
		command("say 我红花会收徒极严");
		command("say 这位" + RANK_D->query_respect(ob) +
			"平时还要多做一些行侠仗义之事！");
		return;
	}
	command("say 好，你这个年青人还不错，我收下你了！");
	command("recruit " + ob->query("id"));
        if( (string)ob->query("class") != "yishi")
                ob->set("class", "yishi");
}



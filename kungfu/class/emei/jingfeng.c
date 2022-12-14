// jingfeng.c 静风
// create by host dec,11
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_yao();
string ask_jian();
void create()
{
        set_name("静风", ({ "jing feng","jing","feng"}));
        set("long",
      "她是一位中年师太，只见她眉目底垂，手中握着一把长剑。自然而然的有股威严。\n");
        set("gender", "女性");
        set("age", 36);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 18);
        set("int", 22);
        set("con", 20);
        set("dex", 21);

        set("qi", 1000);
        set("max_qi", 1000);
        set("jing", 800);
        set("max_jing", 800);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 50);

        set("combat_exp", 4000000);
        set("score", 80000);

        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("parry", 205);
        set_skill("sword", 205);
        set_skill("linji-zhuang",200);
        set_skill("zhutian-bu",200);
        set_skill("huifeng-jian", 210);
        set_skill("yugalism", 250);
        set_skill("dushi-jiren", 250);
        set_skill("literate", 200);
        map_skill("dodge","zhutian-bu");
        map_skill("parry", "huifeng-jian");

        map_skill("sword", "huifeng-jian");
        map_skill("force","linji-zhuang");

	set("inquiry", ([
		"伤药" : (: ask_yao :),
              	"武器" : (: ask_jian :),
	]));

        set("gao_count",3);
        set("jian_count",2);
        create_family("峨嵋派", 4,"弟子");
        set("class","bonze");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
  }

string ask_yao()
{
	mapping fam; 
	object ob;
        
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "峨嵋派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
        if (this_player()->query("qi")>=this_player()->query("max_qi"))
                return "你未曾受伤，讨这药膏做什么？";
        if (ob = present("tianxiang gao", this_player()))
                return "你身上不是带着本门秘药？！";
        if (query("gao_count") < 1)
		return "你来晚了，本门秘药已尽数给了本派弟子。";
	add("gao_count", -1);
	ob = new("/d/emei/obj/tianxiang-gao");
	ob->move(this_player());
	return "我这里有本门秘药，你拿去疗伤吧。";
}

string ask_jian()
{
	mapping fam; 
	object ob;
        
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "峨嵋派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
        if (query("jian_count") < 1)
		return "我现在没有什么武器好给，你下次在来吧。";
        if (ob = present("ruanjian", this_player()))
                return "你身上不是带着武器吗？怎么还来要！";
	add("jian_count", -1);
	ob = new("/d/emei/obj/ruanjian");
	ob->move(this_player());
	return "我这里有一把软剑，你拿去用吧。";
}
// sunpopo.c 孙婆婆
// By Kayin @ CuteRabbit Studio 99-3-29 11:48 new 
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int ask_in();

void create()
{
	set_name("孙婆婆", ({ "sun popo", "sun" }));
	set("long",
		"她是一名和蔼可亲的老婆婆，一张生满鸡皮疙瘩的丑脸,但奇丑之中却含仁慈温柔之意.\n");
	set("gender", "女性");
	set("age", 56);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	
	set("max_qi", 800);
	set("max_jing", 300);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 25);

	set("combat_exp", 1500000);
	set("score", 8500);	
	
	set_skill("force",110);
	set_skill("yunu-xinfa",110);
	set_skill("literate",90);
	set_skill("meinu-quanfa",100);
	set_skill("tianluo-diwang",100);
	set_skill("sword",120);
	set_skill("yunu-jianfa",120);
	set_skill("unarmed",100);
	set_skill("dodge",150);
	set_skill("xianyun-bufa",150);
	set_skill("throwing",100);
	set_skill("parry",90);

	map_skill("force","yunu-xinfa");
	map_skill("unarmed","meinu-quanfa");
	map_skill("sword","yunu-jianfa");
	map_skill("dodge","xianyun-bufa");
	map_skill("parry","yunu-jianfa");
        set("inquiry", ([
	"进墓":(: ask_in :),
	"进古墓":(: ask_in :),
	"小龙女":"自从那次以后她就没有回来过，不过听说有人在终南山上见过她。\n",
	]));
	
	create_family("古墓派", 4, "弟子");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
          carry_object("/d/city/obj/cloth")->wear();

}
void attempt_apprentice(object ob)
{
        mapping myfam;
        if(ob->query_temp("gumu/吐1",1))
        {
        	command("say 好吧，我就收下你了。");
        	command("say 你以后可以用ask sun about 进墓，ask sun about 进古墓,来问我进入古墓。");
		command("recruit " + ob->query("id"));
		ob->delete_temp("gumu/吐1");
        }
        else
        {
	if ((int)ob->query("shen") < 0) {
		command("say 古墓派已经出过一个魔头，我不愿让古墓派再有这等事发生。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}
	if( (string)ob->query("gender") != "女性" )
	{
		command ("say 对不起，本派只收女弟子，你还是另投师们吧。");
		return;
	}
	if( (int)ob->query_kar()< 20){
		command("say 你我无缘，你还是另寻去处吧。");
		return;
	}
	if( (int)ob->query_dex()< 20){
		command("say 你的身法太差，不适合学古墓派的武功.");
		return;
	}
	if( (int)ob->query_int() < 25){
		command("say 你的悟性太差，不适合学古墓派的武功。");
		return;
	}
	if( (int)ob->query_int()< 25){
		command("say 你的相貌。。。我们姑娘是不会收你的。");
		return;
	}
	 myfam = (mapping)ob->query("family");
        if(myfam && myfam["family_name"] == "古墓派")
        if(ob->query("class")=="taoist")
		{
			command("say 你已经是那个叛徒的弟子了,还来这里干什么?");
			return;
		}
	command("say 你自己到里边去拜师祖婆婆的画像吧。");
	ob->set_temp("marks/拜师",1);
	ob->move("/d/gumu/xiaoss1");
}
}
int ask_in()
{
	object me=this_player(1);
	mapping myfam;
	 myfam = (mapping)me->query("family");
        if(myfam && myfam["family_name"] == "古墓派")
            {
            	if(me->query("class")==!"taoist")
            	{
            		command("say 你去吧.\n");
            		me->move("/d/gumu/dating");
            		return 1;
            	}
            	else
            	{
            		command("say 你已经不是古墓派的弟子了,不许你进去.\n");
            		return 1;
            	}
        }
        else
        {
        	command("say 你不是古墓派弟子,我不能让你进去.\n");
        }
}

            

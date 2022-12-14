// yingwang.c 白眉鹰王
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

object ob = this_object();
void create()
{
	set_name("殷天正",({"yin tianzheng","yin","yingwang"}));
	set("title","明教护教法王");
	set("long",
		"他就是明教的四大护教法王的老二。\n"
		"他一身白衫，红光满面，鹤发童颜，那一对长及双肩的白眉迎风一飘一飘，别有特色！\n");
	set("nickname",HIW"白眉鹰王"NOR);
	set("age", 64);
	set("attitude", "peaceful");
	set("shen_type", 0);
	set("str", 25);
	set("int", 25);
	set("con", 26);
	set("dex", 25);
	set("per", 22);

	set("max_qi",3000);
	set("max_jing", 1500);
	set("neili", 4500);
	set("max_neili", 4500);
	set("jiali", 65);
	set("combat_exp", 8000000);
	set("sword_count", 1);

	set_skill("sword",280);
	set_skill("dodge",280);
	set_skill("strike",280);
	set_skill("literate",300);
	set_skill("force",280);
	set_skill("shenghuo-shengong",280);
	set_skill("qingyunwu", 200);
	set_skill("shenghuo-jian",280);
	set_skill("blade",280);
	set_skill("parry",200);
set_skill("sougu",300);	


	map_skill("dodge", "qingyunwu");
	map_skill("force","shenghuo-shengong");
	map_skill("sword","shenghuo-jian");
	map_skill("unarmed","shenghuo-quan");
map_skill("parry","sougu");	

	create_family("明教",34,"弟子");

	set("inquiry", ([
	"张无忌" : "哈哈！！张无忌乃是明教的34代帮主，也是我的好外孙！\n",
	"白虹剑" : "哼，白虹剑乃是我的成名兵器，你想要白虹剑吗？那要回答我几句话。\n",
	]));
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}
/*
void init()
{
       object ob;
       ::init();

	ob = this_player();
	if( ((int)ob->query("score") < 120 || ob->query("shen") < 2000 ) && ob->query("family/master_id")=="yin tianzheng")
	{
		command("chat "+ob->query("name")+"！你为人不忠不义，我明教岂能留你？\n");
		command("expell "+ ob->query("id"));
		this_player()->set("title","明教" + RED + "弃徒" NOR);
	}
	add_action("do_answer", "answer");
}
*/
int do_answer(string arg)
{
	if( !arg ) return notify_fail("你说什么？\n");
	message_vision("$N正气凛然的说道：" + arg + "\n", this_player());
	if ((int)this_player()->query_temp("marks/白虹剑")) {
	       return notify_fail("鹰王皱着白眉，对你说：你也太贪心了吧！\n");
	}
	if( strsrch(arg, "怜我世人") >=0 && (strsrch(arg, "忧患实多") >=0
	|| strsrch(arg, "保护教主") >=0 && strsrch(arg, "同抗外敌") >=0 )) {
		if ( this_player()->query("combat_exp") < 400000 ) {
			command("say 虽然话说得很对，可是你的江湖经验还太少。再去磨练一下吧。");
			return notify_fail("");
		}
		command("smile");
		command("say 原来如此。\n");
		if ( query("sword_count") < 1 ) {
			command("say 不过我的这件贴身兵器已经送给一个出色的弟子了。");
			return notify_fail("");
		}
	       "/d/mj/obj/baihong-jian"->move(this_player());
		this_player()->set_temp("marks/白虹剑", 1);
		message_vision("白眉鹰王解下腰间的白虹剑，捧给$N。\n",this_player());
		add("sword_count", -1);
	} else {
		command("say 你这样说，我不会给你的！");
	}
	return 1;
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_int() < 30) {
		command("say " + RANK_D->query_respect(ob) +
			"天资欠聪，难学得我这一身武功。");
		return;
	}
	if ((int)ob->query_dex() < 25) {
		command("say " + RANK_D->query_respect(ob) +
			"身手不捷，还是另求高师吧。");
		return;

	  }
       if ((string)ob->query("family/family_name")!="明教" || (string)ob->query("class")!="shizhe") {
                command("say " + RANK_D->query_respect(ob) + "若想拜入我派，你可以先去拜徐达。");
                return;
        }        

	if ((int)ob->query("score") < 120) {
		command("say 这位" + RANK_D->query_respect(ob) +
			"似乎对本教还不够忠心，我还不能收你。");
		return;
	  }
	if ((int)ob->query("shen") < 5000) {
		command("say " + RANK_D->query_respect(ob) +
			"有所不知，我平生最恨奸诈之人，你正气太低，我不能让你用明教武功害人。");
		return;
	}
	command("say 哈哈！ 我明教又得一良材，望你日后康扶正义，把我明教发扬光大。");
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "shizhe")
	ob->set("class", "shizhe");
	ob->set("title","明教白眉鹰王属下教众");
}

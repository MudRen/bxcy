// zhangwuji.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();
object who = this_player();

void create()
{
    set_name("张无忌", ({ "zhang wuji", "zhang", "wuji"}));
	set("title",HIR"明教教主"NOR);
	set("long",
	"他，眼睛特别明亮！他，面容特别英俊！\n"
	"他满身充满了男性的阳刚之气！他就是明教的34代教主--张无忌。\n");
	set("gender", "男性");
	set("age", 25);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 32);
	set("per",28);
	set("int", 30);
	set("con", 30);
	set("dex", 32);

	set("max_qi", 40000);
	set("max_jing", 10000);
	set("neili", 300000);
	set("max_neili", 20000);
	set("jiali", 300);
	set("combat_exp", 70000000);
	set("shen",30000);
	set("score", 30000);



	set_skill("taiji-jian", 650);
	set_skill("qiankundanuoyi", 750);
set_skill("shenghuo-ling",700);	
	set_skill("sword",1000);
	set_skill("force", 900);
	set_skill("shenghuo-shengong", 750);
	set_skill("dodge", 1000);
	set_skill("tiyunzong", 750);
	set_skill("unarmed", 700);
	set_skill("jiuyang-force", 680);
	set_skill("parry", 700);
	set_skill("literate", 580);
//      set_skill("shenghuo-lingfa",220);
	set_skill("taoism",680);
	set_skill("taiji-quan",650);

	map_skill("force", "jiuyang-force");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "jiuyang-force");
	map_skill("parry", "jiuyang-force");
	map_skill("sword", "taiji-jian");
	map_skill("dodge", "qiankundanuoyi");


	create_family("明教", 34, "弟子");

	set("inquiry", ([
		"姓名" : "在下乃是这明教的34代帮主，张无忌。\n",
		"谢逊" : "此乃在下的义父，你如能替我找到他，我定重重谢你! \n",
		"秘籍" : "我本来最近写了一本九阳真气入门篇,却不知被我的书童弄哪儿去了.\n",
		"九阳秘籍" : (: ask_me :),
	]));

	set("no_get",1);
	set("book_count", 1);
	setup();
	carry_object("/clone/misc/cloth")->wear();
	set("chat_chance", 1);
	set("chat_msg", ({
		"张无忌仰天叹道：不知我那可怜的义父现在何处！！\n",
		"张无忌道：唉！赵敏！唉！芷若！\n",
	}) );

}

string ask_me()
{
	mapping fam;
	object ob;
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "明教")
		return RANK_D->query_respect(this_player()) +
		"与本教素无来往，不知此话从何谈起？";
	if (!this_player()->query_temp("marks/义父"))
	return "你如果能帮我找到我的义父谢逊，那还可以考虑！";
	if (query("book_count") < 1)
		return "你来晚了，现在我身上没有本教的镇教心法。";
	add("book_count", -1);
	ob = new(__DIR__"obj/jiuyang2");
	ob->move(this_player());
	return "好吧，看在你帮我找到了义父的份上，这本「九阳秘籍」你拿回去好好钻研吧。";
}
/*
void init()
{
       object ob;

       ::init();

	ob = this_player();
	if( ((int)ob->query("score") < 200 || ob->query("shen") < 2000 ) && ob->query("family/master_id")=="zhang wuji" )
	{
		    command("chat "+ob->query("name")+"！你为人不忠不义，我明教岂能留你？\n");
		    command("expell "+ ob->query("id"));
		    this_player()->set("title","明教" + RED + "弃徒" NOR);
	}

}
*/

void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") < 5000) {
		command("shake");
		command("say 你目露凶光，满脸阴鸷之气，非吾中意之人，你还是回去吧！");
		return;
	}
	if ((int)ob->query_skill("force", 1) < 100) {
		command("shake");
		command("say 我的九阳真气乃是以深厚的基本内功为基础的！");
		command("say 你的基本功还未练好，现在我没什么可以教你的！");
		command("sigh");
		return;
	}
	if ((int)ob->query_skill("taoism", 1) < 101) {
		command("shake");
		command("say 九阳真气是需要清心净意的！");
		command("say 你的基本功还未练好，现在我没什么可以教你的！");
		return;
	}
	if ((int)ob->query("max_neili", 1) < 500) {
		command("shake");
		command("say 九阳真气是需要深厚的内力！");
		command("say 你的内力不足，现在我没什么可以教你的！");
		return;
	}
	if ((int)ob->query_skill("parry", 1) < 90) {
		command("shake");
		command("say 我的武功神奇无比，你的招架不够！");
		command("say 你的基本功还未练好，现在我没什么可以教你的！");
		return;
	}
	if ((int)ob->query("score") < 2000 ) {
		command("say 你对本门的贡献还不够,还得努力呀！");
		return;
	}

	if (this_player()->query_temp("marks/义父")) {
		command("say 好吧，我就收下你了。");
		command("recruit " + ob->query("id"));
		ob->set("title","明教张教主得力弟子");
		this_player()->delete_temp("marks/义父");
		command("say 哈哈！ 我明教又得一良材，望你日后康扶正义，把我明教发扬光大。");
		command("recruit " + ob->query("id"));
		if((string)ob->query("class") != "shizhe")
			ob->set("class", "shizhe");
//              ob->set("title",HIW"明教光明正使"NOR);
	}
	else {
		command("say 我平生只有一个义父能够孝敬，你能帮我探知他的下落吗。");
	}
	return;
}

int prevent_learn(object me, string skill)
{
	if( skill == "jiuyang-force" && me->query_skill(skill, 1) < 100)
		return notify_fail("基本的九阳真气要从九阳秘籍上学习.\n");
}

int accept_object(object who, object ob)
{
	object obj,me = this_player();
	obj=this_object();
	if ( ob->query("id") != "jin mao" || userp(ob) )
		return 0;
	tell_object(who,GRN"张无忌激动地说道：你找到我的义父了。\n"NOR);
	if ( !me->query_temp("marks/义父") )
		me->set_temp("marks/义父", 1);
	remove_call_out("destrory");
	call_out("destrory",1,ob);
	return 1;
}

void destrory(object ob)
{
	destruct(ob);
}



void do_kill(string arg)
{
	object me = this_player();
	object obj;

	if (!arg || !objectp(obj = present(arg, environment(me))))
		return;

	if (arg == "zhang wuji" || arg == "zhang")
		obj->kill_ob(me);
	else obj->fight_ob(me);

	me->fight_ob(obj);
}


int accept_fight(object ob)
{
	object me  = this_object();

	me->set("eff_qi", me->query("max_qi"));
	me->set("qi",     me->query("max_qi"));
	me->set("jing",   me->query("max_jing"));
	me->set("neili",  me->query("max_neili"));

	if ( me->is_fighting()) return 0;

	if ( !present(ob, environment()) ) return 0;

	remove_call_out("checking");
	call_out("checking", 1, me, ob);

	return 1;
}

int checking(object me, object ob)
{
	int my_max_qi, his_max_qi;

	if ( !present(ob, environment()) ) return 1;

	my_max_qi  = me->query("max_qi");
	his_max_qi = ob->query("max_qi");

	if( me->is_fighting() )
	{
		if ( (int)me->query("qi")*100/my_max_qi <= 80 )
		{

			me->set("eff_qi", me->query("max_qi"));
			me->set("qi",     me->query("max_qi"));
			me->set("jing",   me->query("max_jing"));
			me->set("neili",  me->query("max_neili"));
		}
		       if ( present(ob, environment()) )
			call_out("checking", 1, me, ob);
	}

	return 1;
}


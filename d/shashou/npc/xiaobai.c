// xiaobai.c  小白

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();
void create()
{
	set_name("小白", ({ "xiao bai", "bai" }));
        set("nickname", HIW "笑苍天" NOR);
	set("long", 
		"这是个年约２０的青年，身披一淡灰素衣，整个人给人的感觉就如他那身衣服。\n"
		"给人一种淡淡的感觉，毫不显眼。\n");
	set("gender", "男性");
	set("age", 22);
	set("attitude", "heroism");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
set("max_qi", 1500000);	
set("max_jing", 1000000);
set("neili", 10000000);
	set("max_neili", 2000);
set("jiali", 15000);
set("combat_exp", 1000000000);
	set("score", 30000);

set_skill("force", 1500);
set_skill("unarmed",1000);
set_skill("wuji-shengong", 1000);
set_skill("dodge", 1000);
set_skill("bugui-bufa", 1000);
set_skill("parry",1000);
set_skill("sword", 1500);	
set_skill("qingyi-jian", 1500);
set_skill("literate", 900);
set_skill("strike",1000);
set_skill("fanyun-zhang",1000);

       map_skill("force", "wuji-shengong");
	map_skill("dodge", "bugui-bufa");
	map_skill("parry", "qingyi-jian");
	map_skill("sword", "qingyi-jian");
	map_skill("strike", "fanyun-zhang");
map_skill("unarmed", "fanyun-zhang");

	create_family("杀手楼", 3, "杀手");
	set("inquiry", ([
		"秘籍" : (: ask_me :),
	]));

	set("book_count", 1);


set("chat_chance_combat", 150);
	set("chat_msg_combat", ({
(: perform_action, "sword.qingyi" :),
(: perform_action, "unarmed.yunkai" :),   
		(: exert_function, "recover" :),
	}) );

            set("no_get",1);
	setup();
carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();

}

void attempt_apprentice(object ob)
{

/*string *prename =
	 ({ "云" });
	string name, new_name;*/


if ((int)ob->query("combat_exp") < 50000000) {
		command("say 杀手是提着脑袋过日子的事，所以江湖经验一定要丰富。");
		return;
	}
	command("say 好吧，我就收下你了。");
/*	       name = me->query("name");
	new_name = prename[random(sizeof(prename))] + name[0..1];
       command("say 做了杀手，就得忘掉原来得一切，师傅先帮你改个名字吧。\n");
	command("say 你是“云”字辈的，从今以后你的名字就叫做" + new_name + "。");
	command("smile");
	me->set("name", new_name);
	me->set("K_record", me->query("PKS") + me->query("MKS"));*/
       command("recruit " + ob->query("id"));
	if( (string)ob->query("class") != "shashou")
		ob->set("class", "shashou");

}


string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "杀手楼")
		return RANK_D->query_respect(this_player()) + 
		"不是本门弟子，秘籍怎能交给你？";
	if (query("book_count") < 1)
		return "你来晚了，情义剑谱已经被人拿走了。";
	add("book_count", -1);
	ob = new("/d/shashou/obj/qingyi-book");
	ob->move(this_player());
	return "好吧，这本「情义剑谱」你拿回去好好钻研。";
}

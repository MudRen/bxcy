//liuchuxuan.c 刘处玄

inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
	set_name("刘处玄", ({"liu chuxuan", "liu", "chuxuan"}));
	set("nickname", "长生子");
	set("gender", "男性");
	set("age", 51);
	set("long",
             "他身形矮小，面目宛似猿候，一身道袍破烂不堪。\n"
		"他就是全真七子中的“长生子”刘处玄。\n");
	set("attitude", "peaceful");
	set("class", "taoist");

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("chat_chance", 20);
	set("chat_msg", ({
		"刘处玄说道：“天将降大任与斯人也，必先劳其心智，饿其体肤......。”\n",
		(: random_move :),
	}));

	set("inquiry", ([
		"内园":"内园是掌教修练的地方，只有三代以上的第子才有资格拜见掌教。\n",
		]));

	set("qi", 1400);
	set("max_qi", 1400);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 100);
	
	set("combat_exp", 1700000);
	set("score", 50000);
 
	set_skill("force", 170);                // 基本内功
	set_skill("tiangang-zhengqi", 170);      //天罡正气
	set_skill("unarmed", 170);              // 基本拳脚
	set_skill("kongmingquan", 170);         //空明拳 
	set_skill("dodge",170);      	      // 基本躲闪
	set_skill("qixing-huanwei", 170);      //七星换位
	set_skill("parry", 170);              // 基本招架
	set_skill("sword", 170);              // 基本剑法
	set_skill("tiangang-jian", 170);      //天罡剑法 
	set_skill("taoism", 170);             //道学心法  
        set_skill("literate",170);          //读书写字  
  
	map_skill("force", "tiangang-zhengqi");
	map_skill("unarmed", "kongmingquan");
	map_skill("dodge", "qixing-huanwei");
	map_skill("parry", "tiangang-jian");
	map_skill("sword", "tiangang-jian");
	
	create_family("全真教",2,"长老");
	
	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: perform_action, "sword.qixinggongyue" :),
		(: exert_function, "recover" :),

	}) );
	
	setup();
	
	carry_object("/d/quanzhen/npc/obj/changjian")->wield();
	carry_object("/d/quanzhen/npc/obj/greyrobe")->wear();

}
void init()
{
	object me, ob;
	mapping fam;

	::init();

	ob = this_player();
	me = this_object();
	
	if (interactive(ob) 
	&& !environment(ob)->query("no_fight")
	&& !present("yingxiong ling", ob) 
	&& ( (fam = ob->query("family")) && fam["family_name"] != "全真教" ) )
	{
		if( !ob->query_temp("warned") ) {
			command("say 你是谁？  怎么闯到全真教内园里来了？！");
			command("say 快给我速速离开，下次看到决不轻饶！");
			ob->set_temp("warned", 1);
		}
		else if( ob->query_temp("stay") < 10 ) ob->add_temp("stay", 1);
		else {
			command("say 大胆狂徒，竟敢闯到全真教内园里来撒野！来人，给我那下。\n");
			me->set_leader(ob);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
		}
	}       

}



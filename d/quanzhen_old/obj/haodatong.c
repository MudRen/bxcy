inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
	set_name("郝大通", ({"hao datong", "hao", "datong"}));
	set("nickname", "广宁子");
	set("gender", "男性");
	set("age", 55);
	set("long",
             "他白发白眉，脸孔极长，身着灰色道袍，看模样是全真教的高手。\n"
		"他就是王重阳座下七大第子之一“广宁子”郝大通。\n");
	set("attitude", "peaceful");
	set("class", "taoist");

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("chat_chance", 1);
	set("chat_msg", ({
		"郝大通说道：“非本教第子不要乱走。”\n",
//	(: random_move :),
	}));

	set("qi", 1800);
	set("max_qi", 1800);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 1700);
	set("max_neili", 1700);
	set("jiali", 110);
	
	set("combat_exp", 1800000);
	set("score", 50000);
 
	set_skill("force", 180);             // 基本内功
	set_skill("tiangang-zhengqi", 180);    //天罡正气
	set_skill("unarmed", 180);           // 基本拳脚
	set_skill("kongmingquan", 180);    //空明拳 
	set_skill("dodge",180);      	     // 基本躲闪
	set_skill("qixing-huanwei", 180);        //七星换位
	set_skill("parry", 180);             // 基本招架
	set_skill("sword", 180);             // 基本剑法
	set_skill("tiangang-jian", 180);        //天罡剑法 
	set_skill("taoism", 180);            //道学心法  
       set_skill("literate",180);           //读书写字  
  
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

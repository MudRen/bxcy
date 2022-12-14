inherit NPC;
void consider();

void create()
{
	set_name("道童", ({"dao tong"}));
	set("gender", "男性");
	set("age", 16);
	set("long",
             "他是一位从小就在全真教出家的道童。\n");
	set("attitude", "peaceful");
	
	set("str", 21);
	set("int", 18);
	set("con", 21);
	set("dex", 18);

	set("chat_chance", 1);
	set("chat_msg", ({
		"道童说道：“前两天杨过和小龙女大闹全真教，就是从二楼逃跑的。”\n",
//		(: random_move :),
	}));

	set("qi", 450);
	set("max_qi", 450);
	set("jing", 450);
	set("max_jing", 450);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 40);
	
	set("combat_exp", 500000);
	set("score", 3000);
 
	set_skill("force", 90);             // 基本内功
	set_skill("tiangang-zhengqi", 90);    //天罡正气
	set_skill("unarmed", 80);           // 基本拳脚
	set_skill("kongmingquan", 80);    //空明拳 
	set_skill("dodge",80);      	     // 基本躲闪
	set_skill("qixing-huanwei", 80);        //七星换位
	set_skill("parry", 80);             // 基本招架
	set_skill("sword", 90);             // 基本剑法
	set_skill("tiangang-jian", 90);        //天罡剑法 
	set_skill("literate",70);           //读书写字  
  
	map_skill("force", "tiangang-zhengqi");
	map_skill("unarmed", "kongmingquan");
	map_skill("dodge", "qixing-huanwei");
	map_skill("parry", "tiangang-jian");
	map_skill("sword", "tiangang-jian");

	create_family("全真教",4, "第子");
	setup();
	
	carry_object("/d/quanzhen/npc/obj/changjian")->wield();
	carry_object("/d/quanzhen/npc/obj/greenrobe")->wear();
}



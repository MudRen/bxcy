// lengqian.c 
#include "/quest/quest.h"
inherit NPC;

void create()
{
        set_name("冷谦", ({ "leng qian", "leng" }) );
        set("nickname", YEL "冷面" NOR);
	set("long", 
"明教刑堂堂主，五散人之一，满脸的正气，看起来没有一个奸人能躲过他的眼睛。\n");
	set("gender", "男性");
	set("age", 40);
	set("attitude", "peaceful");
	set("str", 26);
	set("int", 30);
	set("con", 26);
	set("dex", 28);
        set("per", 20);
	
	set("max_qi", 1500);
	set("max_jing", 800);
	set("neili", 1700);
	set("max_neili", 1700);
	set("jiali", 50);
        set("combat_exp", 900000);
	set("score", 60000);

	set_skill("force", 80);
        set_skill("unarmed", 80);
        set_skill("dodge", 90);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("literate", 80);

        set_skill("shenghuo-jian", 90);
        set_skill("shenghuo-shengong", 80);
        set_skill("shenghuo-quan", 80);
        set_skill("qingyunwu", 90);
      
        map_skill("sword", "shenghuo-jian");
        map_skill("parry", "shenghuo-jian");
        map_skill("force", "shenghuo-shengong");
        map_skill("unarmed", "shenghuo-jian");
        map_skill("dodge", "qingyunwu");

        set("inquiry", ([
                "教主": "教主在圣火堂，你有关于本教的生死问题可以到那儿去找他。\n",
                "拜师": "我冷谦自来喜欢清净，并不喜收徒！ \n",
                      ]) );

        create_family("明教", 34, "刑堂堂主");


	setup();
	carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/city/obj/cloth")->wear();
}

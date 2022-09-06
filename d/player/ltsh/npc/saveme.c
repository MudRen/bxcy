//wizer.c
#include <ansi.h>
#include <login.h>

inherit NPC;
inherit F_MASTER;
 
void create()
{

           set_name("大魔道士--雅薇丝", ({ "wizer", "w","wiz" }) );
set("age", 3500);	
           set("long",@STORY
一个穿著玄甲,带著面纱看不清面貌的神秘女子,传说她已经活了数	
千年的岁月,而且从没有人见过她的真面目,在面纱之下的面孔究竟
是如何呢??这是许多人所好奇的,是天使??还是魔鬼??
不知何故,在多年前她来到这个寒潭,并就此定居了下来,她的善心是	
全江湖人所共知的,不论你有什堋病痛,只要来找她(saveme),她就会	
帮你医治,要记得多多利用喔!!
STORY
              );
           set("chat_chance", 15);
           exert_function(10);
	   set("chat_msg", ({
	    "大魔道士--雅薇丝闭上眼睛冥思．\n",
	    "大魔道士--雅薇丝说道:沉睡在时空中的神秘力量....\n",
            "大魔道士--雅薇丝说道:现在藉著最美丽的创世女神的能力....\n",
            "大魔道士--雅薇丝说道:给予所有黑暗,愚蠢的一切...,平等地毁灭吧!!...\n",
	    }));

        set("gender","女性");
set("combat_exp",15000000);	
set("max_neili", 1500);	
set("neili", 1500000);	
set("jingli", 1500000);	
set("max_jingli", 1500);	
set("max_qi", 150000);              	
set("max_jing", 350000);    	
set("jiali", 1500);	
        set("force",9999999);
set_skill("unarmed", 999);       	
set_skill("dodge", 999);       	
set_skill("kuihua-xinfa", 999);        	
set_skill("parry", 999);       	
set_skill("sword", 999);        	
set_skill("pixie-jian", 520);        	
set_skill("king-of-dragon", 999);	
        set_skill("force",999);
map_skill("force", "kuihua-xinfa");   	
map_skill("dodge", "pixie-jian");   	
map_skill("parry", "pixie-jian");   	
map_skill("sword", "pixie-jian");   	
map_skill("unarmed", "king-of-dragon");	
set("chat_chance", 350);                  
set("chat_msg", ({	
(: command, "exert sneaky" :),       
}) );	


	setup();
carry_object("clone/cloth/qiankun")->wear();		
carry_object("clone/weapon/longyin")->wield();            	
}

void init()
{
	add_action("do_save_me", "saveme");
}

int do_save_me(object ob, string arg)
{
           ob=this_player();     
if( ob->is_busy() )	
return notify_fail("你上一个动作都未完成,对你施用法术不太好吧!\n");    	
if( ob->is_fighting() )	
return notify_fail("战斗中也想让我施用法术帮你恢复?这可是作弊行为哦!\n");        	
else {	
	   ob->set("jing",ob->query("max_jing") );
	   ob->set("qi",ob->query("max_qi") );
	   ob->set("eff_qi",ob->query("max_qi") );
ob->set("shen",0);	
	   ob->set("food", (int)ob->max_food_capacity() );
          ob->set("water", (int)ob->max_water_capacity() );
ob->start_busy(15);	
message_vision(HIY"大魔道士--雅薇丝喃喃自语念道: 藉著水晶女神的力量...让这个受了伤的人回复吧!!\n"NOR,ob);	
message_vision(ob->query("name")+HIW"突然被一道光射中，觉的全身充满活力。\n"NOR,ob);                       	
	        return 1;    
	     	
}
}	






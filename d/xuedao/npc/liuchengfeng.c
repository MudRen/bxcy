// liuchengfeng.c

inherit NPC;
#include <ansi.h>;
void create()
{
       set_name("刘承风", ({ "liu chengfeng", "liu" }));
       set("long", 
       "他就是南四奇“落花流水”中的老三。\n"
       "南四奇横行江南，行侠仗义，刘承风一手太极剑，更是声震大江南北。\n");
       set("gender", "男性");
       set("nickname", HIY"柔云剑"NOR);
       set("age", 41);
       set("attitude", "peaceful");
       set("shen_type", 0);
       set("str", 35);
       set("int", 38);
       set("con", 35);
       set("dex", 35);

set("max_qi", 50000);
set("max_jing", 50000);	
set("neili", 2000000);
       set("max_neili", 2000);
set("jiali", 850);
set("combat_exp", 100000000);
       set("shen_type", 1);

set_skill("force", 1000);
set_skill("taiji-shengong", 1000);
set_skill("dodge", 1000);
set_skill("tiyunzong", 1000);
set_skill("unarmed", 1000);
set_skill("taiji-quan", 1000);
set_skill("parry", 1000);
set_skill("sword", 1000);
set_skill("taiji-jian", 1000);
set_skill("literate", 700);

       map_skill("force", "taiji-shengong");
       map_skill("dodge", "tiyunzong");
       map_skill("unarmed", "taiji-quan");
       map_skill("parry", "taiji-jian");
       map_skill("sword", "taiji-jian");
       set("chat_chance", 20);
       set("chat_msg", ({
              "刘乘风忽然纵声长啸：“落花流～～水……”中气充沛，远远传了出去。\n",
	}));
set("chat_chance_combat", 100);		
set("chat_msg_combat", ({	
(: perform_action, "sword.chan" :),	
(: perform_action, "sword.lian" :),	
(: perform_action, "sword.sui" :),	
(: perform_action, "unarmed.zhen" :),	
(: exert_function, "recover" :),	
}) );	
       setup();
       carry_object("/clone/weapon/changjian")->wield();
carry_object("/d/wudang/obj/greyrobe")->wear();	
}


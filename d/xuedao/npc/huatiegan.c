// huatiegan.c

inherit NPC;
#include <ansi.h>
void create()
{
set_name("花铁干", ({  "hua","Hua tiegan" }));
       set("long", 
       "他就是南四奇“落花流水”中的老二。\n"
       "南四奇横行江南，行侠仗义，花铁干一手中平枪，号称中平无敌。可是他的为人却不咋的。\n");
       set("gender", "男性");
       set("nickname", HIR"中平无敌"NOR);
       set("age", 45);
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
set("jiali", 900);
set("combat_exp", 100000000);
       set("shen_type", 0);

set_skill("force", 1000);
set_skill("zixia-shengong", 1000);
set_skill("dodge", 1000);
set_skill("huashan-shenfa", 1000);
set_skill("cuff", 1000);
set_skill("poyu-quan", 1000);
set_skill("parry", 1000);
set_skill("club", 1000);
set_skill("literate", 400);

       map_skill("force", "zixia-shengong");
       map_skill("dodge", "huashan-shenfa");
map_skill("unarmed", "poyu-quan");
map_skill("cuff", "poyu-quan");	
       set("chat_chance", 20);
       set("chat_msg", ({
              "花铁干缓缓提起中气，啸声如潮涌出：“落花～～流水……”震人耳馈。\n",
       }));
set("chat_chance_combat", 100);			
set("chat_msg_combat", ({		
(: perform_action, "unarmed.leidong" :),		
(: exert_function, "recover" :),		
}) );		
       setup();
}


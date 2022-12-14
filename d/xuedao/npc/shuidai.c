// shuidai.c

inherit NPC;
#include <ansi.h>;
void create()
{
       set_name("水岱", ({ "shui dai", "shui" }));
       set("long", 
       "他就是南四奇“落花流水”中的老四。\n"
       "南四奇横行江南，行侠仗义，水岱虽富甲东南，现在却深有忧色。\n");
       set("gender", "男性");
       set("nickname", HIC"冷月剑"NOR);
       set("age", 39);
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
set("jiali", 1030);
set("combat_exp", 120000000);
       set("shen_type", 1);

set_skill("force", 1300);
set_skill("zixia-shengong", 1000);
set_skill("dodge", 1300);
set_skill("huashan-shenfa", 1300);
set_skill("strike", 1000);
set_skill("huashan-zhangfa", 1000);
set_skill("parry", 1000);
set_skill("sword", 1300);
set_skill("huashan-jianfa", 1300);
set_skill("literate", 800);

       map_skill("force", "zixia-shengong");
       map_skill("dodge", "huashan-shenfa");
       map_skill("strike", "huashan-zhangfa");
       map_skill("parry", "huashan-jianfa");
       map_skill("sword", "huashan-jianfa");
map_skill("unarmed", "huashan-zhangfa");
       set("chat_chance", 20);
       set("chat_msg", ({
              "水岱急提中气，啸声如虹：“落花流水～～……”声势劲急，远远传开。\n",
	}));
set("chat_chance_combat", 100);			
set("chat_msg_combat", ({		
(: perform_action, "sword.jianzhang" :),		
(: perform_action, "sword.wushuang" :),		
(: exert_function, "recover" :),		
}) );		
       setup();
       carry_object("/clone/weapon/changjian")->wield();
}


// mmnz.c

inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;
#include <ansi.h>
#include "skills.h"
#include "mmnz.h"
void create()
{
        set_name("蒙面女子", ({ "mengmian nuzi", "mengmian", "nuzi" }) );
        set("gender", "女性");
        set("age", 25 );
        set("long", "一个风姿秀逸的女子，虽然蒙着面，但掩饰不了其咄咄的杀气。\n");
        set("combat_exp", 50000);
        set("shen", -15000);
        set("attitude", "aggressive");
        set("age", 25 + random(3));      
        set("str", 20+random(5));
        set("int",20+random(5));  
        set("con",20+random(5)); 
        set("dex",20+random(5));
        set("per", 30);
        set("shen_type", -1);
        set("max_qi",1000);
        set("max_jing",1000);
        set("neili",800);
        set("max_neili",800);
        set("score", 5000);

        
        set_skill("force", 80); 
        set_skill("unarmed", 100); 
        set_skill("poyu-quan",random(200));         set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("yunu-shenfa", 200); 
        set_skill("taiji-shengong",random(200));        map_skill("dodge", "yunu-shenfa");
        map_skill("force", "taiji-shengong");         map_skill("unarmed", "poyu-quan"); 
        map_skill("parry", "poyu-qua");
        setup();

        carry_object("/d/gumu/obj/qun1")->wear();

}



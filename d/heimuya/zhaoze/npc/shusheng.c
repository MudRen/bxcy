//shusheng.c
inherit NPC;
void create()
{
    set_name(HIY "书生" NOR, ({"shu sheng"}));
    set("gender", "男性");
    set("age", 42);
        set("per",28);
    set("long", 
        "他虽是满面书卷之气，但仍显得神威凛凛，气度不凡。\n");
    set("attitude", "peaceful");
    
    set("str", 71);
    set("int", 80);
    set("con", 86);
    set("dex", 140);
    set("chat_chance", 1);
    set("chat_msg", ({
        "书生手中拿着一卷书，不时拿起朗诵。\n",
    }));
    set("qi", 2000);
    set("max_qi", 2000);
    set("jing", 2000);
    set("max_jing", 2000);
    set("max_jingli", 1000);

    set("jingli", 1000);
    set("neili", 10000);
    set("max_neili", 1000);
    set("jiali", 300);
    
    set("combat_exp", 400000);
     
    set_skill("force", 200);             // 基本内功
    set_skill("yunlong-jian", 200);
    set_skill("yiyang-zhi", 200);
    set_skill("yunlong-shengong", 200);
    set_skill("yunlong-shenfa", 200);
    set_skill("unarmed", 200);           // 基本拳脚
    set_skill("dodge", 200);             // 基本躲闪
    set_skill("parry", 200);             // 基本招架
    set_skill("sword", 200);             // 基本剑法
    set_skill("literate",550);           // 读书识字
    
    map_skill("force"  , "yunlong-shengong");
    map_skill("unarmed", "yiyang-zhi");
    map_skill("dodge"  , "yunlong-shenfa");
    map_skill("parry"  , "yunlong-jian");
    map_skill("sword"  , "yunlong-jian");
    
    setup();
    carry_object("/clone/misc/changpao")->wear();
    carry_object("/clone/weapon/changjian")->wield();   
}

void die()
{
        object killer;
        if( objectp(killer = query_temp("last_damage_from")) )
                 killer->add_temp("kill_shi",1);
           ::die();
}


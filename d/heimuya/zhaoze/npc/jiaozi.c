//jiaozi.c
inherit NPC;
void create()
{
    set_name(WHT "樵子" NOR, ({"jiao zi"}));
    set("gender", "男性");
    set("age", 42);
    set("per", 21);
    set("long", 
        "他容色豪壮，神态虎虎，举手迈足间似大将军般八面威风。\n");
    set("attitude", "peaceful");
    
    set("str", 151);
    set("int", 80);
    set("con", 86);
    set("dex", 140);
    set("chat_chance", 5);

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
    set_skill("leiting-axe", 200);
    set_skill("yiyang-zhi", 200);
    set_skill("yunlong-shengong", 200);
    set_skill("yunlong-shenfa", 200);
    set_skill("axe", 200);
    set_skill("unarmed", 200);           // 基本拳脚
    set_skill("dodge", 200);             // 基本躲闪
    set_skill("parry", 200);             // 基本招架
    
    map_skill("force"  , "yunlong-shengong");
    map_skill("unarmed", "yiyang-zhi");
    map_skill("dodge"  , "yunlong-shenfa");
    map_skill("parry"  , "leiting-axe");
    map_skill("axe"  , "leiting-axe");
    
    setup();
    carry_object("/clone/misc/cloth")->wear();
    carry_object("/d/city/obj/gangaxe")->wield();   
}

void die()
{
        object killer;
        if( objectp(killer = query_temp("last_damage_from")) )
                 killer->add_temp("kill_shi",1);
           ::die();
}


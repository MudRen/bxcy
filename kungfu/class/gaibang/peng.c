// sample master.c code
// xiake island master.c
inherit NPC;
inherit F_MASTER;
void consider();
void create()
{
    set_name("彭有敬", ({"peng youjing", "peng", "youjing"}));
    set("title", "丐帮九袋长老");
    set("nickname", "掌钵龙头");
    set("gender", "男性");
    set("age", 50);
    set("long", 
        "彭有敬是丐帮中净衣派的首领，衣着干净华丽，不象叫化子。\n"
        "他脸上挂着慈祥的笑容，一双眼睛有摄人心魄的力量。\n");
    set("attitude", "peaceful");
    
    set("str", 24);
    set("int", 20);
    set("con", 24);
    set("dex", 20);
    set("qi", 900);
    set("max_qi", 900);
    set("jing", 100);
    set("max_jing", 100);
    set("neili", 1300);
    set("max_neili", 1200);
    set("jiali", 100);
    
    set("combat_exp", 220000);
    
    set_skill("force", 120);                // 基本内功
    set_skill("huntian-qigong", 120);   // 混天气功
    set_skill("unarmed", 120);          // 基本拳脚
    set_skill("xianglong-zhang", 120);  // 降龙十八掌
    set_skill("dodge", 120);            // 基本躲闪
    set_skill("xiaoyaoyou", 120);       // 逍遥游
    set_skill("parry", 120);                // 基本招架
    set_skill("club", 120);             // 基本棍杖
    
    map_skill("force", "huntian-qigong");
    map_skill("unarmed", "xianglong-zhang");
    map_skill("parry", "xianglong-zhang");
    map_skill("dodge", "xiaoyaoyou");
    
    create_family("丐帮", 18, "九袋长老");
    set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
        (: perform_action, "unarmed.xianglong" :),
        (: exert_function, "recover" :),
    }) );
    setup();
    carry_object("/clone/misc/pcloth")->wear();
}
void attempt_apprentice(object ob)
{
    command("say 老夫不收徒弟，" + RANK_D->query_respect(ob) + "还是请回吧。");
}

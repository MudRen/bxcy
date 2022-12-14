// sample master.c code
// xiake island master.c
inherit NPC;
inherit F_MASTER;
void consider();
void create()
{
    set_name("鲁有脚", ({"lu youjiao", "lu", "youjiao"}));
    set("title", "丐帮九袋长老");
    set("nickname", "掌棒龙头");
    set("gender", "男性");
    set("age", 45);
    set("long", 
        "鲁有脚虽然武功算不得顶尖高手，可是在江湖上却颇有声望。\n"
        "因为他在丐帮中有仁有义，行事光明磊落，深得洪七公的器重。\n");
    set("attitude", "peaceful");
    set("str", 25);
    set("int", 12);
    set("con", 25);
    set("dex", 20);
    set("qi", 900);
    set("max_qi", 900);
    set("jing", 100);
    set("max_jing", 100);
    set("neili", 1200);
    set("max_neili", 1200);
    set("jiali", 100);
    
    set("combat_exp", 700000);
    
    set_skill("force", 150);                // 基本内功
    set_skill("huntian-qigong", 150);   // 混天气功
    set_skill("unarmed", 150);          // 基本拳脚
    set_skill("xianglong-zhang", 150);  // 降龙十八掌
    set_skill("dodge", 150);                // 基本躲闪
    set_skill("xiaoyaoyou", 150);       // 逍遥游
    set_skill("parry", 150);                // 基本招架
    set_skill("club", 150);             // 基本棍杖
    set_skill("begging", 150);
    
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
    if ((int)ob->query("shen") < 5000) {
        command("say 我丐帮乃忠义之门，行事光明磊落。");
        command("say 在德行方面，" + RANK_D->query_respect(ob) +
            "是否还做得不够？");
        return;
    }
    command("say 好吧，希望" + RANK_D->query_respect(ob) +
    "能好好学习本门武功，将来在江湖中闯出一番作为。");
    command("recruit " + ob->query("id"));
    if((string)ob->query("class") != "beggar")
        ob->set("class", "beggar");
}

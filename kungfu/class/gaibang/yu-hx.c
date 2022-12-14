// gaibang npc code
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("余洪兴", ({"yu hongxing", "yu", "hongxing"}));
    set("title", "丐帮八袋弟子");
    set("gender", "男性");
    set("age", 30);
    set("long", 
        "这是位笑眯眯的丐帮八袋弟子，生性多智，外号小吴用。\n");
    set("attitude", "peaceful");
    set("str", 20);
    set("int", 30);
    set("con", 22);
    set("dex", 20);
    set("qi", 420);
    set("max_qi", 420);
    set("jing", 330);
    set("max_jing", 330);
    set("neili", 780);
    set("max_neili", 780);
    set("jiali", 42);
    
    set("combat_exp", 82000);
    
    set_skill("force", 148); 
    set_skill("huntian-qigong", 146); 
    set_skill("unarmed", 148); 
    set_skill("xianglong-zhang", 140); 
    set_skill("dodge", 140); 
    set_skill("xiaoyaoyou", 148); 
    set_skill("parry", 141); 
    set_skill("begging", 140); 
    set_skill("stealing", 140); 
    set_skill("checking", 140); 
    
    map_skill("force", "huntian-qigong");
    map_skill("unarmed", "xianglong-zhang");
    map_skill("dodge", "xiaoyaoyou");
    
    create_family("丐帮", 19, "弟子");
    setup();
    carry_object("/clone/misc/pcloth")->wear();
}
void attempt_apprentice(object ob)
{
    if( ob->query("int") < 25 ) return;
    command("say 唉，本帮诚信为本，只有七公他老人家和我才特别收些聪明徒儿，");
    command("say 大家都要为长远着想啊！");
    command("recruit " + ob->query("id"));
    if((string)ob->query("class") != "beggar")
        ob->set("class", "beggar");
}

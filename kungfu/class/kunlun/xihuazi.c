// xihuazic by wyz
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("西华子", ({ "xihua zi", "zi", "xihua" }) );
        set("gender", "男性");
        set("age", 29);
        set("long",
         "他就是昆仑派的大师兄，为人好打抱不平，嫉恶如仇。
他长得矮矮胖胖的。\n");        
        set("attitude", "peaceful");
        set("str", 25);
        set("shen",20000);
        set("int", 35);
        set("con", 50);
        set("per", 28);
        set("dex", 80);
        set("jingli",3000);
        set("max_jingli",2000);
        set("neili", 5500);
        set("max_neili", 3500);
        set("jiali",200);
        set("rank_info/respect", "大师兄");        
        set("combat_exp",685900);
 
           set_skill("force", 190);
           set_skill("dodge", 190);
           set_skill("parry", 190);
           set_skill("xuantian-force", 190);
           set_skill("sword", 190);
           set_skill("literate",190);
           set_skill("zhengliangyi-sword", 190);
           set_skill("yaoming-dodge", 190);
           set_skill("sanyin-unarmed",190);
           set_skill("unarmed",190);
           
           map_skill("dodge", "yaoming-dodge");
           map_skill("force", "xuantian-force");
           map_skill("parry", "zhengliangyi-sword");
           map_skill("sword", "zhengliangyi-sword");
           map_skill("unarmed","sanyin-unarmed");   
 

    create_family("昆仑派", 15, "大师兄");
    setup();
    carry_object("/clone/misc/long_cloth")->wear();
    carry_object("/clone/weapon/changjian")->wield();
}
void attempt_apprentice(object ob)
{
    command("say 好吧，我就收下你了，以后要多为昆仑派出力啊。");
    command("recruit " + ob->query("id"));
 }
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "swordsman");
}

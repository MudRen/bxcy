// masteryue.c
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("何足道", ({ "he zudao", "master","he" }) );
        set("title", "昆仑三圣");
        set("nickname", "何三圣");        
        set("gender", "男性");
        set("age", 162);
        set("long",
 "他就是昆仑派的开山祖师，江湖上人称“昆仑三圣”的何足道。\n");        
        set("attitude", "peaceful");
        set("str", 85);
        set("int", 85);
        set("con", 80);
        set("per", 25);
        set("dex", 140);
        set("jingli",8000);
        set("max_jingli",6000);
        set("neili", 81500);
        set("max_neili", 20000);
        set("jiali",300);
        set("rank_info/respect", "何师祖");        
        set("combat_exp",27500000);
 
           set_skill("force", 650);
           set_skill("dodge", 650);
           set_skill("parry", 650);
           set_skill("xuantian-force", 650);
           set_skill("sword", 650);
           set_skill("literate",600);
           set_skill("xunlei-sword", 650);
           set_skill("unarmed", 650);
           set_skill("sanyin-unarmed",650);
           set_skill("throwing",650);
           set_skill("yaoming-dodge", 650);
           set_skill("mantianhuayu", 650);
    
           map_skill("dodge", "yaoming-dodge");
           map_skill("force", "xuantian-force");
           map_skill("unarmed","sanyin-unarmed");
           map_skill("throwing","mantianhuayu");
           map_skill("parry", "xunlei-sword");
           map_skill("sword", "xunlei-sword");
    
    create_family("昆仑派", 13, "三圣");
    setup();
    carry_object("/clone/misc/long_cloth")->wear();
    carry_object("/d/kunlun/obj/qizi")->wield();
    carry_object("/clone/weapon/changjian")->wield();
}
void attempt_apprentice(object ob)
{   
        if ((int)ob->query_skill("xuantian-force", 1) < 276) 
           {
        command("say " + RANK_D->query_respect(ob) + "是否还应该多练练本门的内功心法？");
        return;
       }
    command("recruit " + ob->query("id"));
}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "swordsman");
}

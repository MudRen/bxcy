//master ban by wyz
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("卫四娘", ({"wei shiniang","wei","shiniang"}) );
        set("title", MAG "闪电手" NOR);
        set("gender", "女性");
        set("age", 25);
        set("long",
        "她就是昆仑派，被江湖上人称“闪电手”，的卫四娘。\n");        
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 35);
        set("con", 50);
        set("per", 28);
        set("dex", 80);
        set("jingli",1000);
        set("max_jingli",2000);
        set("neili", 5500);
        set("max_neili", 2500);
        set("jiali",100);
        set("combat_exp",1064800);
 
           set_skill("force", 190);
           set_skill("dodge", 190);
           set_skill("parry", 190);
           set_skill("xuantian-force", 190);
           set_skill("sword", 190);
           set_skill("literate",190);
           set_skill("zhengliangyi-sword", 190);
           set_skill("yaoming-dodge", 190);
           set_skill("sanyin-unarmed",220);
           set_skill("unarmed",220);
           
           map_skill("dodge", "yaoming-dodge");
           map_skill("force", "xuantian-force");
           map_skill("parry", "zhengliangyi-sword");
           map_skill("sword", "zhengliangyi-sword");
           map_skill("unarmed","sanyin-unarmed");   
 

    create_family("昆仑派", 15,"弟子");
    setup();
    carry_object("/clone/misc/long_cloth")->wear();
}
void attempt_apprentice(object ob)
{
        if( (string)ob->query("gender") != "女性" )
          {        
          command("say 男人都不是好东西，给我滚。");
            return;
                }

}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "swordsman");
}


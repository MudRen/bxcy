// youzong.c 
#include <ansi.h>
inherit NPC;

void create()
{
       set_name("教众", ({ "youshi jiaozong", "jiaozong" }) );
       set("title",RED"明教右使属下"NOR);
       set("long","一个明教的弟子，似得到明教的真传，看上去象个会家子。");
        set("gender", "男性");
        set("age", 20);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 23);
        set("int", 22);
        set("con", 22);
        set("dex", 23);

        set("max_qi", 800);
        set("max_jing", 200);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 20);
        set("combat_exp", 80000);
        set("shen",800);
        set("score", 100);

        set_skill("force", 40);
        set_skill("sword", 40);
        set_skill("dodge", 40);
        set_skill("unarmed",40);
        set_skill("parry", 40);
        set_skill("sword", 40);
        set_skill("shenghuo-shengong",50);
        set_skill("liehuo-jian",40);
        set_skill("qingyunwu",40);

       map_skill("dodge","qingyunwu");
       map_skill("unarmed","liehuo-jian");
       map_skill("parry","liehuo-jian");
       map_skill("force","shenghuo-shengong");
        
        create_family("明教", 35, "弟子");

        setup();
       carry_object("/clone/weapon/changjian")->wield();  
       carry_object("/clone/misc/cloth")->wear();
}


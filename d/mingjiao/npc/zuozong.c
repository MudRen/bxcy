// zuozong.c 
#include <ansi.h>
inherit NPC;

void create()
{
       set_name("教众", ({ "zuoshi jiaozong", "jiaozong" }) );
       set("title",RED"明教左使属下"NOR);
       set("long","一个明教的弟子，背上斜插长剑，满脸英武之气。");
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
       set_skill("shenghuo-shengong",40);
        set_skill("shenghuo-quan",40);
       set_skill("qingyunwu",40);

       map_skill("dodge","qingyunwu");
       map_skill("unarmed","shenghuo-quan");
       map_skill("parry","shenghuo-quan");
       map_skill("force","shenghuo-shengong");
        
        create_family("明教", 35, "弟子");

        setup();

       carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}


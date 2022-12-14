//LUCAS 2000-6-18
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("褚万春",({"zhu wanchun","zhu"}));
        set("gender", "男性");
        set("age", 20);
        set("long", 
              "他是凌霄城第六代弟子褚万春,和孙万年一样,贼眉鼠眼。\n"
              "也因为行止不端,被关在这里。\n");
        set("attitude", "peaceful");

        set("str", 25);
        set("con", 30);
        set("int", 24);
        set("dex", 30);
        set("neili", 800);
        set("max_neili", 800);
        set("jing", 500);
        set("max_jing", 500);
        set("qi", 800);
        set("max_qi", 800);

        set("combat_exp", 50000);
        set("shen_type", -1);
        set("score", 20000);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );

        set_skill("unarmed", 60);
        set_skill("sword", 60);
        set_skill("force", 60);
        set_skill("parry", 60);
        set_skill("dodge", 60);
        set_skill("literate", 40);

set_skill("lingxiao-jian", 60);	
        set_skill("bingxue-xinfa", 60);
        set_skill("snow-zhang", 60);
        set_skill("snowstep", 60);

map_skill("sword", "lingxiao-jian");	
map_skill("parry", "lingxiao-jian");	
        map_skill("force", "bingxue-xinfa");
        map_skill("unarmed", "snow-zhang");
        map_skill("dodge", "snowstep");

        create_family("凌霄城", 6, "弟子");
        setup();

        
        carry_object("/clone/cloth/cloth")->wear();
}


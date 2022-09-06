#include <ansi.h>

inherit NPC;

void create()
{
        set_name("������",({"liao zili","liao"}));
        set("gender", "����");
        set("age", 40);
        set("long", 
               "��������ѩɽ���������������������ڵ�ʦ��.\n");
        set("attitude", "peaceful");

        set("str", 30);
        set("con", 30);
        set("int", 30);
        set("dex", 30);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jing", 1500);
        set("max_jing", 1500);
        set("qi", 2000);
        set("max_qi", 2000);
        set("jiali", 50);

        set("combat_exp", 1000000);
        set("shen_type", 0);
        set("score", 50000);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );

        set_skill("unarmed", 180);
        set_skill("sword", 180);
        set_skill("force", 180);
        set_skill("parry", 180);
        set_skill("dodge", 180);
        set_skill("literate", 180);

set_skill("lingxiao-jian", 180);	
        set_skill("bingxue-xinfa", 180);
        set_skill("snow-zhang", 180);
        set_skill("snowstep", 180);
map_skill("sword", "lingxiao-jian");	
map_skill("parry", "lingxiao-jian");	
        map_skill("force", "bingxue-xinfa");
        map_skill("unarmed", "snow-zhang");
        map_skill("dodge", "snowstep");

        create_family("������", 5, "����");
        setup();

        
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/money/gold");
}

void attempt_apprentice(object ob)
{
        command("say ���ǲ���ͽ�ģ���ȥ������Щͽ�ܰɡ�");
}

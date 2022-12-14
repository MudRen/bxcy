
// /kungfu/class/xueshan/shanyong.c  善勇
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("善勇", ({ "shan yong", "shan", "yong" }));
        set("long",@LONG
一个胖胖的西藏僧人，面带笑容，却常干笑里藏刀的事。
LONG
        );
        set("title",HIR"血刀门第五代弟子"NOR);
        set("gender", "男性");
        set("age", 35);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
set("max_qi", 80000);
set("max_jing", 40000);
set("neili", 800000);
        set("max_neili", 800);
set("jiali", 750);
set("combat_exp", 80000000);
        set("score", 20000);

set_skill("lamaism", 750);
set_skill("literate", 600);
set_skill("force", 900);
set_skill("parry", 600);
set_skill("blade", 1000);
set_skill("dodge", 800);
set_skill("longxiang", 650);
set_skill("shenkong-xing", 600);
set_skill("hand", 600);
set_skill("dashou-yin", 800);
set_skill("xue-dao", 1000);

        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
map_skill("hand", "dashou-yin");
map_skill("unarmed", "dashou-yin");
        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");

        create_family("雪山寺", 5, "弟子");
        set("class", "bonze");
set("chat_chance_combat", 100);			
set("chat_msg_combat", ({		
(: perform_action, "blade.kuangdao" :),		
(: perform_action, "blade.shendao" :),		
(: exert_function, "recover" :),		
}) );		
        setup();
        carry_object("/d/xueshan/obj/y-jiasha")->wear();
        carry_object("/clone/weapon/gangdao")->wield();
}

/*
void init()
{
        object ob;

        ::init();

        ob = this_player();
             if((int)ob->query("score")<-51&&ob->query("family/master_id")=="shan yong")
        {
                      command("chat "+ob->query("name")+"! 装什么正道人士，从此以后你就不要再到雪山寺来了! \n");
                  command("expell "+ ob->query("id"));
                      this_player()->set("title","血刀门" + RED + "弃徒" NOR);   
        }
}

*/
void attempt_apprentice(object ob)
{
        if ((string)ob->query("gender") != "男性")
        {
                command("say 我不收女徒弟。\n");
                return;
        }
        command("haha");
        command("recruit " + ob->query("id"));

        ob->set("title", "血刀门第六代弟子");
}

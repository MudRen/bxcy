
// /kungfu/class/xueshan/shengdi.c  胜谛
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("胜谛", ({ "sheng di", "sheng", "di" }));
        set("long",@LONG
这是一个身形魁梧的西藏僧人，神色冷漠。武功是同门中最高的一人。
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
set("max_qi", 100000);
set("max_jing", 50000);
set("neili", 1000000);
set("max_neili", 1000);
set("jiali", 1250);
set("combat_exp", 120000000);
set("score", 50000);
set_skill("lamaism", 850);
set_skill("literate", 1000);
set_skill("force", 1000);
set_skill("parry", 1000);
set_skill("blade", 1300);
set_skill("dodge", 1000);	
set_skill("longxiang", 1000);
set_skill("shenkong-xing", 1000);
set_skill("hand", 1000);
set_skill("dashou-yin", 1000);
set_skill("xue-dao", 1300);

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

        add_money("gold",1);
}


/*
void init()
{
        object ob;
        ::init();

        ob = this_player();
             if((int)ob->query("score")<-51&&ob->query("family/master_id")=="sheng di")
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
        if (ob->query("shen") > -50000)
        {
                command("say 看来我还要先教你如何心狠杀人。\n");
                return;
        }
        if ((int)ob->query_skill("longxiang", 1) < 45)
        {
                command("say 入我血刀门，修习龙象功法是首要的。\n");
                return;
        }
        command("haha");
        command("recruit " + ob->query("id"));

        ob->set("title", "血刀门第六代弟子");
}

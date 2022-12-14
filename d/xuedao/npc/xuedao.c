
// /kungfu/class/xueshan/xuedao.c  血刀老祖
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("血刀老祖", ({ "xuedao laozu", "xue dao", "laozu" }));
        set("long",@LONG
这喇嘛身着黄袍，年纪极老，尖头削耳，脸上都是皱纹。他就是血刀门第四代掌门。
LONG
        );
        set("title",HIR"血刀门第四代掌门"NOR);
        set("gender", "男性");
        set("age", 85);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
set("max_qi", 300000);
set("max_jing", 100000);
set("neili", 10000000);
set("max_neili", 2000);
set("jiali", 5000);
set("combat_exp", 580000000);
        set("score", 180000);

set_skill("lamaism", 1500);
set_skill("literate", 800);
set_skill("force", 1800);
set_skill("parry", 1500);
        set_skill("blade", 200);
set_skill("sword", 1300);
set_skill("dodge", 1800);
set_skill("longxiang", 1800);
set_skill("shenkong-xing", 1800);
set_skill("hand", 1800);
set_skill("dashou-yin", 1800);
set_skill("mingwang-jian", 1800);
set_skill("xue-dao", 2000);

        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("hand", "dashou-yin");
map_skill("unarmed", "dashou-yin");
        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");
        map_skill("sword", "mingwang-jian");
        set("chat_chance_combat", 20);  
        set("chat_msg_combat", ({
                (: command("unwield flood blade") :),
                (: command("wield flood blade") :),
        }) );

        create_family("雪山寺", 4, "弟子");
        set("class", "bonze");
set("chat_chance_combat", 300);				
set("chat_msg_combat", ({			
(: perform_action, "blade.shendao" :),			
(: perform_action, "blade.kuangdao" :),		
(: exert_function, "recover" :),			
}) );			
        setup();
        carry_object("/d/xueshan/obj/y-jiasha")->wear();
        carry_object("/d/xueshan/obj/xblade")->wield();
//    carry_object("/d/xueshan/npc/obj/xblade")->wield();	

        add_money("gold",2);
}



/*
void init()
{
        object ob;

        ::init();

        ob = this_player();
             if((int)ob->query("score")<-51&&ob->query("family/master_id")=="xuedao laozu")
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
        if ((string)ob->query("family/family_name") != "雪山寺")
        {
                command("say 这位" + RANK_D->query_respect(ob) +
                        "既非本门弟子，还是请回吧！\n");
                return;
        }
if ((int)ob->query("shen") > -10000000)
        {
                command("say 你是不是向着侠义道，连杀人都不会！\n");
                return;
        }
if ((int)ob->query_skill("longxiang", 1) < 500)
        {
                command("say 入我血刀门，修习龙象功法是首要的。\n");
                return;
        }
        command("haha");
        command("nod");
        command("recruit " + ob->query("id"));

          ob->set("title","血刀门掌门大弟子");
}

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("王重阳", ({ "wang chongyang", "wang" }));
        set("nickname", HIC "中神通" NOR);
        set("long", 
                "他就是全真教开山祖师、中神通王重阳。\n"
                "身穿一件青灰色道袍，背一口七星剑。\n"
                "面色红润，看起来内功一定很高深。\n");
        set("gender", "男性");
        set("age", 70);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 80);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        
        set("max_qi", 8000);
      set("max_jing", 5000);
        set("neili", 5000);
        set("max_neili", 10000);
        set("jiali", 100);
        set("combat_exp", 80000000);
        set("score", 500000);

        set_skill("force", 750);
        set_skill("tiangang-zhengqi", 750);
        set_skill("dodge", 1300);
        set_skill("qixing-huanwei", 700);
        set_skill("unarmed", 650);
        set_skill("kongming-quan", 600);
        set_skill("parry", 800);
        set_skill("sword", 700);
        set_skill("quanzhen-jianfa", 720);
        set_skill("xiantian-gong", 700);
        set_skill("qixing-array", 700);
        set_skill("taoism", 700);
          set_skill("literate", 700);

     map_skill("force", "xiantian-gong");
        map_skill("dodge", "qixing-huanwei");
        map_skill("unarmed", "kongming-quan");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("sword", "quanzhen-jianfa");

        create_family("全真教", 1, "开山祖师");
        set("class", "taoist");

set("chat_chance_combat", 100);	
        set("chat_msg_combat", ({
                (: perform_action, "sword.qixing" :),
(: perform_action, "sword.jianzhen" :),	
                (: exert_function, "recover" :),
        }) );

        setup();
        carry_object("/d/quanzhen/obj/qixingjian")->wield();
        carry_object("/d/quanzhen/npc/obj/greenrobe")->wear();
}

void attempt_apprentice(object ob)
{
        if ((string)ob->query("family/family_name")!="全真教" || (string)ob->query("class")!="taoist") {
                command("say 我全真乃是道家门派。");
                command("say " + RANK_D->query_respect(ob) + "若想拜我派需先入我道。"); 
                return;
        }
        if ((int)ob->query_skill("tiangang-zhengqi", 1) < 300) {
                command("say 我全真教乃内家武功，最重视内功心法。"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "是否还应该在天罡正气上多下点功夫？");
                return;
        }
        if ((int)ob->query("shen") < 100000) {
                command("say 学武之人，德义为先，功夫次之。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return;
        }
        if (ob->query_int() < 60) {
                command("say 我全真教武功全从道中悟出。");
                command("say 要能达到炉火纯青之境，悟性低不得。");
                command("say " + RANK_D->query_respect(ob) + "的悟性还大有潜力可挖，还是请回吧。");
                return;
        }
        command("chat 好！好！！好！！！");
        command("chat 希望" + RANK_D->query_respect(ob) + "你能够学到我全真教的真髓！！");
        command("chat* pat " + ob->query("id"));
        
        command("recruit " + ob->query("id"));
        ob->set("title",HIC"全真教重阳真人传人"NOR);}


void init()
{

        object ob;

        ::init();

        ob = this_player();
        if ( (int)ob->query("shen") <-2000 && (string)ob->query("family/master_id") == "wang chongyang")
        {
                  command("chat "+ob->query("name")+"!你多次杀人越货，胡作非为，我岂能仍是你的师傅。\n");
                command("expell "+ ob->query("id"));
                this_player()->set("title","全真教" + RED + "弃徒" NOR);   
                
        }
}


void do_kill(string arg)
{
        object me = this_player();
        object obj;
        
        if (!arg || !objectp(obj = present(arg, environment(me))))
                return;

        if (arg == "zhang sanfeng" || arg == "zhang")
                obj->kill_ob(me);
        else obj->fight_ob(me);
        
        me->fight_ob(obj);
}

       
int accept_fight(object ob)
{
        object me  = this_object();
                
        me->set("eff_qi", me->query("max_qi"));
        me->set("qi",     me->query("max_qi"));
        me->set("jing",   me->query("max_jing"));
        me->set("neili",  me->query("max_neili"));

        if ( me->is_fighting()) return 0;

        if ( !present(ob, environment()) ) return 0;

        remove_call_out("checking");
        call_out("checking", 1, me, ob);
        
        return 1;
}

int checking(object me, object ob)
{
        int my_max_qi, his_max_qi;

        if ( !present(ob, environment()) ) return 1; 

        my_max_qi  = me->query("max_qi");
        his_max_qi = ob->query("max_qi");

        if( me->is_fighting() ) 
        {
                if ( (int)me->query("qi")*100/my_max_qi <= 80 )
                {
                   
                        me->set("eff_qi", me->query("max_qi"));
                        me->set("qi",     me->query("max_qi"));
                        me->set("jing",   me->query("max_jing"));
                        me->set("neili",  me->query("max_neili"));
                }
                       if ( present(ob, environment()) )
                        call_out("checking", 1, me, ob);
        }


        return 1;  
}

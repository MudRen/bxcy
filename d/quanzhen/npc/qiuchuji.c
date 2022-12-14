//qiuchuji.c  丘处机
// modified by snow@jhfy
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
        set_name("丘处机", ({"master qiu","qiu chuji", "qiu", "chuji"}));
        set("nickname", HIC"长春子"NOR);
        set("gender", "男性");
        set("age", 50);
        set("long",
             "他长须如漆，神采飞扬，双目炯炯有神。\n"
             "他就是闻名大江南北，疾恶如仇的长春子。\n");
        set("attitude", "peaceful");
        set("class", "taoist");

        set("str", 50);
        set("int", 31);
        set("con", 35);
        set("dex", 31);
        set("per", 25);

        set("chat_chance", 1);
        set("chat_msg", ({
                "丘处机说道：“没能教导好杨康，真对不起他的父亲。”\n",
                "丘处机叹了口气道：“杨过逃进了活死人墓，这叫我如何象靖儿交代？”\n",
             "丘处机喃喃道：“《九阴真经》是当年黄裳花了几十年心血写成的天下武功总集，
                             得者天下无敌 。” \n",
//              (: random_move :),
        }));
        set("inquiry", ([
                "活死人墓":"重阳宫东南面就是活死人墓，全真教第子不得入内，违者逐出师门。\n",
      "小龙女":"活死人墓当代主人，武功深不可测。\n",
        ]));

        set("qi", 5000);
        set("max_qi", 5000);
        set("jing", 2000);
        set("max_jing", 3000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 150);
        
        set("combat_exp", 5000000);
        set("score", 200000);
         
        set_skill("force", 350);                 // 基本内功
           set_skill("tiangang-zhengqi", 350);//天罡正气
        set_skill("unarmed", 350);             // 基本拳脚
         set_skill("kongming-quan", 350);       //空明拳 
         set_skill("dodge", 300);             // 基本躲闪
           set_skill("qixing-huanwei", 350);//七星换位
          set_skill("parry", 320);             // 基本招架
        set_skill("sword", 320);             // 基本剑法
         set_skill("quanzhen-jianfa", 320);//天罡剑法 
        set_skill("taoism", 330);            //道学心法  
        set_skill("literate",320);           //读书写字
        set_skill("qixing-array",340); 
        map_skill("force", "tiangang-zhengqi");
        map_skill("unarmed", "kongming-quan");
        map_skill("dodge", "qixing-huanwei");
      map_skill("parry", "quanzhen-jianfa");
      map_skill("sword", "quanzhen-jianfa");
        
                    set("no_get", 1);
        
        create_family("全真教", 2, "副掌教");
        
set("chat_chance_combat", 100);	
        set("chat_msg_combat", ({
                (: perform_action, "sword.qixing" :),
                (: exert_function, "recover" :),
        }) );

        
        setup();
        
        carry_object("/d/quanzhen/npc/obj/changjian")->wield();
        carry_object("/d/quanzhen/npc/obj/greyrobe")->wear();

}
void init()
{
        mapping mine;
        object me, room;

        me = this_player();

        if (!mapp(mine = me->query("family"))) 
                return;

        if(!( room = find_object("/d/quzanzhen/cangjingge1")) )
        room = load_object("/d/quanzhen/cangjingge1");
         if(me->query("family/master_id")=="master qiu"&&me->query_temp("warn_time")<time())
        if((me->query("PKS")>me->query("kar")&&(int)me->query("shen")<=-100)
        ||(me->query("PKS")<me->query("kar")&&(int)me->query("shen")<=-10000))
   
       { me->add("hao_warning",1);
         me->set_temp("warn_time",time()+300);
         command("heng "+me->query("id"));
         command("say 你如再在江湖杀人越货，胡作非为，莫怪为师没有警告于你！");         
       }
       else  if (me->query("family/master_id")=="master qiu")
                  command("say 好徒儿，你来了！\n");             
        if((int)me->query("hao_warning") > 3)
        {
                command("chat "+HIR+me->query("name")+"杀人越货胡作非为，有辱师门，从今以后不再是全真教的弟子。\n"NOR);
                command("expell "+ me->query("id"));
                this_player()->set("title","全真教" + RED + "弃徒" NOR);    
                me->delete("hao_warning");    
        }
             

        if( (mapp(mine = me->query("family")) && mine["family_name"] != "全真教")
 || (present("master qiu", room) && (!present("letter", me))&&me->query("family/master_id")!="master qiu")  )
        {
                  command("say 大胆狂徒，竟敢杀人闯入藏经阁，看招!\n");
                  call_out("kill_ob", 0, this_player()); 

                  COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));                
                  return;
        }
        return;
}

/*void init()
{
        object ob;
        add_action("do_decide", "decide");
        ::init();
        ob = this_player();
        if(ob->query("family/master_id")=="master qiu"&&ob->query_temp("warn_time")<time())
        if((ob->query("PKS")>ob->query("kar")&&(int)ob->query("shen")<=-100)
        ||(ob->query("PKS")<ob->query("kar")&&(int)ob->query("shen")<=-10000))
   
       { ob->add("hao_warning",1);
         ob->set_temp("warn_time",time()+300);
         command("heng "+ob->query("id"));
         command("say 你如再在江湖杀人越货，胡作非为，莫怪为师没有警告于你！");         
       }
        if((int)ob->query("hao_warning") > 3)
        {
                command("chat "+HIR+ob->query("name")+"杀人越货胡作非为，有辱师门，从今以后不再是全真教的弟子。\n"NOR);
                command("expell "+ ob->query("id"));
                this_player()->set("title","全真教" + RED + "弃徒" NOR);    
                ob->delete("hao_warning");    
        }
}          */     
void attempt_apprentice(object ob)
{
        object me  = this_object();
        mapping ob_fam  = ob->query("family");
        mapping my_fam  = me->query("family");

        
        if ( ob_fam["generation"] <= my_fam["generation"] )
        {
                command("say " + RANK_D->query_respect(ob) + "，贫道哪里敢当 !");
                return;
        }
        
        if ((int)ob->query_str() < 35 || (int)ob->query_con() < 35) {
                command("say 当道士需要能吃苦耐劳，六根清静依我看" + RANK_D->query_respect(ob) + "的资质似乎不适合当道士？");
                return;
        }
        if ((string)ob->query("family/family_name") != "" &&
            (string)ob->query("family/family_name") != "全真教") {
                command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜本真人呢？");
                return;
        }
       if ((int)ob->query_skill("tiangang-zhengqi", 1) < 120) {
                command("say 我全真教乃内家武功，最重视内功心法。"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "是否还应该在天罡正气上多下点功夫？");
                return;
       }
       if ((int)ob->query_skill("quanzhen-jianfa", 1) < 120) {
                command("say 我全真教剑法扬名天下，天下无双。"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "是否还应该在全真剑法上多下点功夫？");
                return;
       }
       command("smile");  
       command("say 好吧，贫道就收下你了。");
       command("recruit " + ob->query("id")); 
       ob->set("title","全真教长春真人爱徒");   
       ob->set("class","sworder");       
        
}



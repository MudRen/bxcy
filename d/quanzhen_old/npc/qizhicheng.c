//qizhicheng.c  祁志诚

#include <ansi.h> 
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
        set_name("祁志诚", ({"qi zhicheng","qi", "zhicheng"}));
        set("master", "刘处玄");
        set("gender", "男性");
        set("age", 26);
        set("long",
             "他容貌不算俊，但却十分英挺，高高的个子，体格很健壮。\n" );        set("attitude", "peaceful");
        set("class", "taoist");

        set("str", 21);
        set("int", 19);
        set("con", 21);
        set("dex", 19); 
        set("per", 20);
        set("chat_chance", 1);
        set("chat_msg", ({
            "祁志诚说道：“杨过这小王八蛋差点害死赵师哥，活死人墓的玉蜂真厉害。”\n",
            "祁志诚喃喃道：“尹师兄的那点心思，嘿嘿，当我不知道呀。。。”\n",
//        (: random_move :),
        }));

        set("qi", 850);
        set("max_qi", 850);
        set("jing", 850);
        set("max_jing",850);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 50);
        
        set("combat_exp", 800000);
        set("score", 80000);
 
        set_skill("force", 120);             // 基本内功
        set_skill("tiangang-zhengqi", 120);    //天罡正气
        set_skill("unarmed", 120);           // 基本拳脚
        set_skill("kongming-quan", 120);     //空明拳 
        set_skill("dodge",130);              // 基本躲闪
        set_skill("qixing-huanwei", 130);        //七星换位
        set_skill("parry", 120);             // 基本招架
        set_skill("sword", 120);             // 基本剑法
        set_skill("quanzhen-jianfa", 120);        //天罡剑法 
        set_skill("taoism",120);           //道学心法  
        set_skill("literate",120);           //读书写字
        set_skill("qixing-array",120);  

  
        map_skill("force", "tiangang-zhengqi");
        map_skill("unarmed", "tiangang-beidou");
        map_skill("dodge", "qixing-huanwei");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("sword", "quanzhen-jianfa");
        
        create_family("全真教", 3, "第子"); 
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "sword.qixing" :),
                (: exert_function, "recover" :),
        }) );
        setup();
        
        carry_object("/d/quanzhen/npc/obj/changjian")->wield();
        carry_object("/d/quanzhen/npc/obj/greenrobe")->wear();

}

void init()
{
        object ob;
        add_action("do_decide", "decide");
        ::init();
        ob = this_player();
        if(ob->query("family/master_id")=="qi zhicheng"&&ob->query_temp("warn_time")<time())
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
}               
              
              
void attempt_apprentice(object ob)
{
         if((int)ob->query("shen")<0){
         command("say 我全真教乃是堂堂名门正派，"+RANK_D->query_respect(ob)+
                                "的品德实在令人怀疑。");
         command("say "+RANK_D->query_respect(ob)+
                                "还是先回去多做点善事吧。");
         return;
         }
        command ("smile");
        command("say 好吧，我就收下你了，你可要好好光大我全真教！");
        command("recruit " + ob->query("id"));
        if( (string)ob->query("class") != "taoist")
                ob->set("class", "taoist"); 
        if (this_player()->query("age")<20)
        {
        if((string)this_player()->query("gender")!="女性")
                this_player()->set("title","全真教道童" );
        else
                this_player()->set("title","全真教小道姑");
        }
        else {
        if((string)this_player()->query("gender")!="女性")
                this_player()->set("title","全真教道士");
        else
                this_player()->set("title","全真教道姑");
        } 
}
/*                      
void unconcious()
{ 
      object me=this_player();       message_vision(HIW"\n$N冷笑一声：“叫你知道我全真剑阵的厉害。”说完头也不回的向上跑去。\n\n"NOR,this_object());        
       command("sneer");
       me->set_temp("qz/闯", 1);
       destruct(this_object());
}
*/
void do_kill(string arg)
{
        object me = this_player();
        object obj;
        
        if (!arg || !objectp(obj = present(arg, environment(me))))
                return;

        if (arg == "qi zhicheng" || arg == "qi")
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



// yinzhiping.c  尹志平

#include <ansi.h> 
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
        set_name("尹志平", ({"master yin","yin zhiping", "yin", "zhiping"}));
        set("gender", "男性");
        set("age", 28);
        set("long",
             "他羽衣星冠，眉清目秀，气度高华，脱俗出尘。\n"
                "他是全真教第三代第子中最出类拔翠的一个。\n");
        set("attitude", "peaceful");
        set("class", "taoist");

        set("str", 21);
        set("int", 19);
        set("con", 21);
        set("dex", 19);
        set("per", 28);

        set("chat_chance", 1);
        set("chat_msg", ({
             "尹志平说道：“活死人墓中不知有什么，真想去看看。”\n",
             " 尹志平喃喃道：“小龙女真是天下第一美女”。\n",
//            (: random_move :),
        }));

        
        set("qi", 800);
        set("max_qi", 800);
        set("jing", 1100);
        set("max_jing", 1100);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 80);
        
        set("combat_exp", 900000);
        set("score", 80000);
 
        set_skill("force", 120);             // 基本内功
        set_skill("tiangang-zhengqi", 120);    //天罡正气
        set_skill("unarmed", 120);           // 基本拳脚
         set_skill("kongming-quan", 120);     //空明拳 
        set_skill("dodge",120);              // 基本躲闪
        set_skill("qixing-huanwei", 120);        //七星换位
        set_skill("parry", 120);             // 基本招架
        set_skill("sword", 120);             // 基本剑法
        set_skill("quanzhen-jianfa", 120);        //天罡剑法 
        set_skill("taoism",120);           //道学心法  
        set_skill("literate",120);           //读书写字 
        set_skill("qixing-array",100);       //北斗七星阵

        map_skill("force", "tiangang-zhengqi");
        map_skill("unarmed", "kongming-quan");
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
        if(ob->query("family/master_id")=="master yin"&&ob->query_temp("warn_time")<time())
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
                this_player()->set("title","全真教道童");
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


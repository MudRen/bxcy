//sunbuer.c 孙不二
// modified by snow
#include <ansi.h> 
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
        set_name("孙不二", ({"sun buer", "sun", "buer"}));
        set("nickname", HIB"清静散人"NOR);
        set("gender", "女性");
        set("age", 39);
        set("long",
             "她明目皓齿，肤色白腻，虽穿一身灰色道袍，也掩盖不了她的姿色。\n"
             "她就是全真七子中唯一的女性“清静散人”孙不二。\n");
        set("attitude", "peaceful");
        set("class", "taoist");

        set("str", 29);
        set("int", 32);
        set("con", 30);
        set("dex", 32); 
        set("per", 25);
        set("chat_chance", 1);
        set("chat_msg", ({
                "孙不二说道：“非本教第子不要乱走。”\n",
//        (: random_move :),
        }));

        set("qi", 1200);
        set("max_qi", 1200);
        set("jing", 1250);
        set("max_jing", 1250);
        set("neili", 1200);
        set("max_neili", 1200);
        set("jiali", 100);
        
        set("combat_exp", 2500000);
        set("score", 50000);
 
        set_skill("force", 280);             // 基本内功
        set_skill("tiangang-zhengqi", 280);    //天罡正气
        set_skill("unarmed", 280);           // 基本拳脚
        set_skill("kongming-quan", 240);    //空明拳 
        set_skill("dodge",280);              // 基本躲闪
        set_skill("qixing-huanwei", 280);        //七星换位
        set_skill("parry", 280);             // 基本招架
        set_skill("sword", 280);             // 基本剑法
        set_skill("quanzhen-jianfa", 280);        //天罡剑法 
        set_skill("taoism", 280);            //道学心法  
       set_skill("literate",280);           //读书写字
        set_skill("qixing-array",300); 
  
        map_skill("force", "tiangang-zhengqi");
        map_skill("unarmed", "kongming-quan");
        map_skill("dodge", "qixing-huanwei");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("sword", "quanzhen-jianfa");
        
        create_family("全真教",2,"长老");
        
set("chat_chance_combat", 100);	
        set("chat_msg_combat", ({
                (: perform_action, "sword.qixing" :),
                (: exert_function, "recover" :),
        }) );


        
        setup();
     
       carry_object("/d/quanzhen/obj/changjian")->wield();
        carry_object("/d/quanzhen/obj/greyrobe")->wear();

}

void init()
{
        object ob;
        add_action("do_decide", "decide");
        ::init();
        ob = this_player();
        if(ob->query("family/master_id")=="sun buer"&&ob->query_temp("warn_time")<time())
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
     mapping fam = ob->query("family");
      if (!fam || fam["family_name"] != "全真教"){
                command("say "+RANK_D->query_respect(ob)+"与本派素无来往，不知此话从何谈起？");
                return;
                }       
      if((int)ob->query_skill("tiangang-zhengqi", 1) < 80) {
                command("say 我全真教武功内功是基础。"); 
                command("say " + RANK_D->query_respect(ob)+"是否还应该先在内功上多下点功夫？");
                return;
                }  
      if((int)ob->query_skill("sword", 1) < 80) {
                command("say 你剑法这么差，我教的你不一定学得会。"); 
                command("say "+RANK_D->query_respect(ob)+"是否还应该在剑法上多下点功夫？");
                return;
                }
      if(ob->query_int() < 23) {
                command("say 我的武功都要教高的悟性才能学会。");
                command("say 要能达到炉火纯青之境，体质什么的倒是无关紧要，悟性却是半点也马虎不得。");
                command("say 这位"+RANK_D->query_respect(ob)+"的悟性还大有潜力可挖，还是请回吧。");
                return;
                }
      if(ob->query("gender") != "女性") {
                command("say 我可只收女徒，你去找我师兄们试试吧。");
                return;
                }
        command("say 嗯，看你还是个学武的料，我就收下你吧！");
        command("recruit " + ob->query("id"));
        ob->set("title","全真教清静散人爱徒");
        ob->set("class","sworder");
}


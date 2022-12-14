//mayu.c 马钰
// modified by snow@jhfy
#include <ansi.h> 
inherit NPC;
inherit F_MASTER;

void consider();
string ask_me();

void create()
{
        set_name("马钰", ({"master ma","ma yu", "ma", "yu"}));
        set("nickname", HIC"丹阳子"NOR);
        set("gender", "男性");
        set("age", 60);
        set("long",
             "他白须垂胸，面色红润，眉慈目善，一身道袍一尘不染。\n"
             "他就是王重阳的首徒，全真教第二任掌教马钰。\n");
        set("attitude", "peaceful");
        set("class", "taoist");

        
        set("str", 33);
        set("int", 30);
        set("con", 33);
        set("dex", 30);

        set("chat_chance", 1);
        set("chat_msg", ({
                "马钰说道：“第一次华山论剑，我师傅拿了第一，得到了《九阴真经》。”\n",
                "马钰道：“《东邪西毒、南帝北丐、中神通》，这十一个字\n代表了上一代武林中的五位绝顶高手。”\n",
                "马钰喃喃道：“《东邪西狂、南僧北侠 中顽童》，描述了当今武林中的五位绝顶高手。” \n", 
                           
        }));
        set("inquiry", ([
                "九阴真经":"师傅死了以后，九阴真经落在了师叔“老玩童”周伯通的手上。\n",
                "周伯通":"听说师叔被“东邪”黄药师困在了桃花岛。\n",
                "手谕" : (: ask_me :),
        ]));


        set("letter_count", 1);


        set("qi", 4000);
        set("max_qi", 4000);
        set("jing", 1700);
        set("max_jing", 1700);
        set("neili",1000);
        set("max_neili",2000);
        set("jiali", 115);
        
        set("combat_exp",4500000);
        set("score", 200000);
 
        set_skill("force", 300);             // 基本内功
        set_skill("tiangang-zhengqi", 300);    //天罡正气
        set_skill("unarmed", 290);           // 基本拳脚
        set_skill("kongming-quan", 290);    //空明拳 
        set_skill("dodge",290);              // 基本躲闪
        set_skill("qixing-huanwei", 290);        //七星换位
        set_skill("parry", 300);             // 基本招架
        set_skill("sword", 300);             // 基本剑法
        set_skill("quanzhen-jianfa", 300);        //天罡剑法 
        set_skill("taoism", 300);             //道学心法
        set_skill("literate",300);           //读书写字
        set_skill("qixing-array",320);  
        map_skill("force", "tiangang-zhengqi");
        map_skill("unarmed", "kongming-quan");
        map_skill("dodge", "qixing-huanwei");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("sword", "quanzhen-jianfa");
        
        create_family("全真教", 2, "掌教");
        
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
        object ob;
        add_action("do_decide", "decide");
        ::init();
        ob = this_player();
        if(ob->query("family/master_id")=="master ma"&&ob->query_temp("warn_time")<time())
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

        object me  = this_object();
        mapping ob_fam  = ob->query("family");
        mapping my_fam  = me->query("family");

        
        if ( ob_fam["generation"] <= my_fam["generation"] )
        {
                command("say " + RANK_D->query_respect(ob) + "，贫道哪里敢当 !");
                return;
        }

        if ((int)ob->query_str() < 28 || (int)ob->query_con() < 28) {
                command("say 当道士需要能吃苦耐劳，六根清静，依我看" + RANK_D->query_respect(ob) + "的资质似乎不适合当道士？");
                return;
        }
        if ((string)ob->query("family/family_name") != "" &&
           (string)ob->query("family/family_name") != "全真教") {
                command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜本真人呢？");
                return;
        }
       if ((int)ob->query_skill("tiangang-zhengqi", 1) < 110) {
                command("say 我全真教乃内家武功，最重视内功心法。"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "是否还应该在天罡正气上多下点功夫？");
                return;
       }
       command("smile");  
       command("say 好吧，贫道就收下你了。");
       command("recruit " + ob->query("id")); 
       ob->set("title","全真教掌教真人爱徒");
       ob->set("class","sworder");       
}
        

string ask_me()
{
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "全真教")
                return RANK_D->query_respect(this_player()) + 
                "与本派素无来往，不知此话从何谈起？";

        if (  present("shou yu", this_player()) )
                return RANK_D->query_respect(this_player()) + 
                "你身上不是有了吗，怎麽又来要了？ 快去吧！";

        if (query("letter_count") < 1) return "对不起，你来晚了，以后再努力吧。";

        ob = new(__DIR__"obj/allow-letter");
        ob->move(this_player());

        add("letter_count", -1);

        message_vision("$N获得一张手谕。\n",this_player());
        return "进入藏经阁以后可要好好努力，为全真教争光，不要辜负了我的厚望。";

}


// jinmao-shiwang.c 金毛狮王
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

object ob = this_object();
void create()
{
        set_name("谢 逊",({"xie xun","xie","shiwang"}));
        set("title","明教护教法王");
        set("long", 
                "他就是明教的四大护教法王的老三。\n"
                "他一头金发随风飘摆，两只眼睛凹陷禁闭，明显是盲了！但宝刀未老，壮志未酬！\n");
        set("age", 56);
        set("nickname",HIY"金毛狮王"NOR);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 35);
        set("int", 20);
        set("con", 28);
        set("dex", 28);
        set("per", 28);
        
        set("max_qi",4000);
        set("max_jing", 4000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 75);
        set("combat_exp", 1880000);


        set_skill("sword",180);
        set_skill("dodge",180);
        set_skill("unarmed",180); 
        set_skill("literate",170);
        set_skill("force",190);
        set_skill("shenghuo-jian",180);
        set_skill("qingyunwu", 180);
        set_skill("blade",180);
         set_skill("qishang-quan",200);
        set_skill("parry",180);
        set_skill("shenghuo-quan",180);
        set_skill("hunyuan-yiqi",190);
        set_skill("shenghuo-shengong",180);
      

        map_skill("dodge", "qingyunwu");
        map_skill("force","hunyuan-yiqi");
        map_skill("sword","shenghuo-jian");
        map_skill("unarmed","qishang-quan");
        map_skill("parry","shenghuo-quan");

        create_family("明教",34,"弟子");
        set("inquiry", ([
"姓名" : "在下乃是圣火明教的34代金毛狮王，谢逊。\n",
"圆真" : "圆真这个狗贼，我恨不能喝他的血，吃他的肉! \n",
"张无忌" : "我很久没有见到我的孩儿了，他特别喜欢我的金头发。\n",
        ]));

        setup();
carry_object("/d/mingjiao/obj/guangmingjian")->wield();	
        carry_object("/clone/misc/cloth")->wear();
}




void init()
{
       object ob;

       ::init();

        ob = this_player();
        if( ((int)ob->query("score") < 50  || ob->query("shen") < 7000 ) && ob->query("family/master_id")=="xie xun" )
        {
                    command("chat "+ob->query("name")+"！你为人不忠不义，我明教岂能留你？\n");
                    command("expell "+ ob->query("id"));
                    this_player()->set("title","明教" + RED + "弃徒" NOR);   
        }

}



void attempt_apprentice(object ob)
{
        if ((int)ob->query_int() < 34) {
                command("say " + RANK_D->query_respect(ob) +
                        "天资欠聪，难学得我这一身武功。");
                return;
        }
        if ((int)ob->query_dex() < 30) {
                command("say " + RANK_D->query_respect(ob) +
                        "身手不捷，还是另求高师吧。");
                return;
        }
        if ((int)ob->query("shen") <10000) {
                command("say " + RANK_D->query_respect(ob) +
          "我最恨的就是奸险狡诈的恶棍,你的正气太低,不能做我的弟子.");
                return;
        }
       if ((string)ob->query("family/family_name")!="明教" || (string)ob->query("class")!="shizhe") {
                command("say " + RANK_D->query_respect(ob) + "若想拜入我派，你可以先去拜徐达。");
                return;
        }        

        if ((int)ob->query("score") <= 50) {
                command("say 这位" + RANK_D->query_respect(ob) +
          "似乎对我教还不够忠心，不能做我的弟子。");
                return;
        }
        command("say 哈哈！ 我明教又得一良材，望你日后康扶正义，把我明教发扬光大。");
        command("recruit " + ob->query("id"));
        if((string)ob->query("class") != "shizhe")

        ob->set("class", "shizhe");
        ob->set("title","明教金毛狮王爱徒");
}

int accept_object(object ob, object obj)
{
        object me = this_object();
        if (obj->query("id") == "ren tou" ) {
                command("say 能杀圆真就为我辈中人！这金毛你拿去看看我那孩儿吧！\n");
                remove_call_out("destroying");
                call_out("destroying", 1, me, obj);
                ob = new(__DIR__"obj/jinmao");
                ob->move(this_player());
        
                return 1;
        }
      
        command("smile");
        command("say 这东西给我可没有什麽用。");
        command("give " + obj->query("id") + " to " + me->query("id"));
        return 0;
}


// fuwang.c 青翼蝠王
#include <ansi.h>
inherit NPC;
object ob = this_object();
void create()
{
        set_name("韦一笑",({"wei yixiao","wei","fuwang"}));
        set("title","明教护教法王");
        set("long", 
           "他就是明教的四大护教法王的老幺，即老四。\n"
                "他一身青衫，精瘦干练，英气勃勃，满脸焕发出青春气息！\n");
        set("age", 34);
        set("nickname",GRN"青翼蝠王"NOR);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 25);
        set("int", 20);
        set("con", 25);
        set("dex", 35);
        set("per", 21);
        set("max_qi",3000);
        set("max_jing", 2000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 70);
        set("combat_exp", 1660000);
        set_skill("sword",170);
        set_skill("dodge",250);
        set_skill("unarmed",170);
        set_skill("literate",60);
        set_skill("force",170);
        set_skill("hunyuan-yiqi",170);
        set_skill("qingyunwu", 200);
        set_skill("blade",170);
        set_skill("shenghuo-quan",170);
        set_skill("hanbing-mianzhang",200);
        set_skill("qingyunwu",250); 
        map_skill("dodge", "qingyunwu");
        map_skill("force","shenghuo-shengong");
        map_skill("parry","hanbing-mianzhang");
        map_skill("unarmed","hanbing-mianzhang");

        create_family("明教",34,"弟子");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        set("chat_chance", 2);
        set("chat_msg", ({
                (: random_move :),
CYN"韦一笑激动的说：我已经跟过三代教主了，张教主是对我们最好的！\n这年头，这样的好人不多了！\n"NOR,
CYN"韦一笑翘起大拇指：咱明教张教主是有名的义薄云天，武功盖世的性情中人！\n也是武林中响当当的美男子！\n"NOR,
        }) );
        
}
/*
void init()
{
       object ob;

       ::init();

        ob = this_player();
        if( ((int)ob->query("score") < 50 || (int)ob->query("shen") < 100 )  && ob->query("family/master_id")=="wei yixiao" )
        {
                    command("chat "+ob->query("name")+"！你为人不忠不义，我明教岂能留你？\n");
                    command("expell "+ ob->query("id"));
                    this_player()->set("title","明教" + RED + "弃徒" NOR);   
        }
}
*/
void attempt_apprentice(object ob)
{
        if ((int)ob->query_int() < 35) {
                command("say " + RANK_D->query_respect(ob) +
                        "天资欠聪，难学得我这一身武功。");
                return;
        }
        if ((int)ob->query_dex() < 40) {
                command("say " + RANK_D->query_respect(ob) +
                        "身手不捷，还是另求高师吧。");
                return;

          }
       if ((string)ob->query("family/family_name")!="明教" || (string)ob->query("class")!="shizhe") {
                command("say " + RANK_D->query_respect(ob) + "若想拜入我派，你可以先去拜徐达。");
                return;
        }        

        if ((int)ob->query("score") <= 50) {
                command("say 这位" + RANK_D->query_respect(ob) +
                        "好象对我教不够衷心，还是另求高师吧。");
                return;
        }
        command("say 哈哈！ 我明教又得一良材，望你日后康扶正义，把我明教发扬光大。");
        command("recruit " + ob->query("id"));
        if((string)ob->query("class") != "shizhe")
        ob->set("class", "shizhe");
        ob->set("title","明教青翼蝠王属下教众");
}

int accept_object(object ob, object obj)
{
        object me = this_object();
        if (query("book_count") >=  80){
                if (obj->query("id") == "si huochan" )
                {
                        command("say " + ob->query("name") + "，太谢谢你了，你救了我一命，我该如何报答你呢？就指点你一下轻功吧！");
                        remove_call_out("destroying");
                        call_out("destroying", 1, me, obj);
                        add("book_count",-1);
                        this_player()->improve_skill("qingyunwu",200);
                        return 1;
                }
        }
        command("smile");
        command("say 这东西给我可没有什麽用。");
        command("give " + obj->query("id") + " to " + me->query("id"));
        return 0;
}

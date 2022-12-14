// yangxiao.c 杨逍

inherit NPC;
#include <ansi.h>
inherit F_MASTER;

object ob = this_object();
void create()
{
        set_name("杨逍",({"yang xiao","yang","xiao"}));
        set("title","明教光明左使");
         set("title",RED"明教光明左使"NOR);
        set("long", 
                "他就是明教的光明左使。\n"
                "白色长袍的中年书生,相貌俊雅.只是双眉下垂,\n"
                "嘴边露出几条深深皱纹,不免略带衰老凄苦之相.\n"
                "他不言不动,神色漠然,似乎心弛远处,正在想什么事情.\n");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 22);
        set("int", 28);
        set("con", 12);
        set("dex", 20);
        set("per", 28);
        
        set("max_qi",3500);
        set("max_jing", 1000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 80);
        set("combat_exp", 9000000);
        
        set_skill("sword",280);
        set_skill("dodge",280);
        set_skill("unarmed",280); 
        set_skill("literate",280);
        set_skill("force",280);
        set_skill("shenghuo-shengong",280);
        set_skill("qingyunwu", 280);
        set_skill("shenghuo-jian",280);
         set_skill("shenghuo-jian", 280);
        set_skill("parry", 280);
        
        map_skill("dodge", "qingyunwu");
        map_skill("force","shenghuo-shengong");
        map_skill("sword","shenghuo-jian");
        map_skill("parry","shenghuo-jian");
        
        create_family("明教",34,"使者");
        
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
        
}

/*
void init()
{
       object ob;

       ::init();

        ob = this_player();
        if( ((int)ob->query("score") < 100 || ob->query("shen") < 1000 ) && ob->query("family/master_id")=="yang xiao")
        {
                    command("chat "+ob->query("name")+"！你为人不忠不义，我明教岂能留你？\n");
                    command("expell "+ ob->query("id"));
                    this_player()->set("title","明教" + RED + "弃徒" NOR);   
        }

}

*/
void attempt_apprentice(object ob)
{
        if ((int)ob->query_int() < 32) {
                command("say " + RANK_D->query_respect(ob) +
                        "天资欠聪，难学得我这一身武功。");
                return;
        }
       if ((string)ob->query("family/family_name")!="明教" || (string)ob->query("class")!="shizhe") {
                command("say " + RANK_D->query_respect(ob) + "若想拜入我派，你可以先去拜徐达。");
                return;
        }        

        if ((int)ob->query_dex() < 27) {
                command("say " + RANK_D->query_respect(ob) +
                        "身手不捷，还是另求高师吧。");
                return;
        }
        if ((int)ob->query("shen") < 5000) {
                command("say " + RANK_D->query_respect(ob) +
                        "有所不知，我平生最恨奸诈之人，你正气太低，我不能让你用明教武功害人。");
                return;
        }
        if ((int)ob->query("score") <= 100) {
                command("say 这位" + RANK_D->query_respect(ob) +
                        "似乎对本教不够忠心，我还不能收你。");
                return;
        }
        command("say 哈哈！ 我明教又得一良材，望你日后康扶正义，把我明教发扬光大。");
        command("recruit " + ob->query("id"));
        if((string)ob->query("class") != "shizhe")
        ob->set("class", "shizhe");
        ob->set("title","明教光明左使属下教众");
}


// yang_ming.c 吴劲草
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

object ob = this_object();
void create()
{
        set_name("吴劲草",({"wu jingcao","wu","cao"}));
        set("title","锐金旗副使");
         set("title",HIY"锐金旗副使"NOR);
        set("long", 
                "他就是明教的洪水旗副使。\n"
                "他身才魁梧,武艺高强,铁面无私,一度为明教执法.\n");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 24);
        set("int", 16);
        set("con", 16);
        set("dex", 24);
        
        set("max_qi",600);
        set("max_jing", 300);
        set("neili", 1000);
        set("max_neili", 600);
        set("jiali", 40);
        set("combat_exp", 50000);
        
        set_skill("sword",60);
        set_skill("dodge",60);
        set_skill("unarmed",60); 
        set_skill("force",60);
        set_skill("shenghuo-shengong",60);
        set_skill("qingyunwu", 60);
        set_skill("liehuo-jian",60);
        set_skill("parry", 60);
        
        map_skill("dodge", "qingyunwu");
        map_skill("force","shenghuo-shengong");
        map_skill("sword","liehuo-jian");
        map_skill("parry","liehuo-jian");
        
        create_family("明教",35,"五行旗使");
        
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
        if((int)ob->query("score") < -10 && ob->query("family/master_id")=="wu jingcao")
        {
                    command("chat "+ob->query("name")+"！你为人不忠不义，我明教岂能留你？\n");
                    command("expell "+ ob->query("id"));
                    this_player()->set("title","明教" + RED + "弃徒" NOR);   
        }

}

*/
void attempt_apprentice(object ob)
{
       if ((string)ob->query("family/family_name")!="明教" || (string)ob->query("class")!="shizhe") {
                command("say " + RANK_D->query_respect(ob) + "若想拜入我派，你可以先去拜徐达。");
                return;
        }        

        command("say 哈哈！ 我明教又得一良材，望你日后康扶正义，把我明教发扬光大。");
        command("recruit " + ob->query("id"));
        if((string)ob->query("class") != "shizhe")

        ob->set("class", "shizhe");
        ob->set("title","明教锐金旗下教众");
}


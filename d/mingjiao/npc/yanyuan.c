// yanyuan.c 颜垣
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

object ob = this_object();
void create()
{
        set_name("颜垣",({"yan yuan","yan","yuan"}));
        set("title","厚土旗使");
         set("title",HIW"厚土旗使"NOR);
        set("long", 
                "他就是明教的厚土旗使。\n"
                "他身才魁梧,满脸横肉.腰粗臂圆,乃明教第一神力之士\n");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 30);
        set("int", 10);
        set("con", 16);
        set("dex", 24);
        

        set("max_qi",1000);
        set("max_jing", 500);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 40);
        set("combat_exp", 100000);
        
        set_skill("sword",100);
        set_skill("dodge",100);
        set_skill("unarmed",100); 
        set_skill("literate",100);
        set_skill("force",100);
        set_skill("shenghuo-shengong",100);
        set_skill("qingyunwu", 100);
        set_skill("liehuo-jian",100);
        set_skill("parry", 100);
        
        map_skill("dodge", "qingyunwu");
        map_skill("force","shenghuo-shengong");
        map_skill("sword","liehuo-jian");
        map_skill("parry","liehuo-jian");
        
        create_family("明教",35,"五行旗使");
        setup();
        carry_object("/d/city/obj/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
        
}

/*
void init()
{
       object ob;

       ::init();

        ob = this_player();
        if((int)ob->query("score") < -10 && ob->query("family/master_id")=="yan yuan")
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
        ob->set("title","明教厚土旗下教众");
}

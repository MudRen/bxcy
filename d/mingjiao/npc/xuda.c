// xuda.c 徐达
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
object ob = this_object();
void create()
{
        set_name("徐达",({"xu da","xu"}));
       set("nick",YEL"智多星"NOR);
            set("nickname", YEL "智多星" NOR);
        set("long", 
                "他是光明顶上的有名的智多星。\n"
                "他头戴一顶儒帽，身着一件青衫，让人一见就觉得他足智多谋。\n");
        set("age", 25);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 20);
        set("int", 38);
        set("con", 18);
        set("dex", 23);
        set("neili", 800);

        set("max_neili", 800);
        set("jiali", 10);
        set("combat_exp", 20000);
        set_skill("sword",50);
        set_skill("dodge",50);
        set_skill("unarmed",60); 
        set_skill("literate",80);
        set_skill("force",50);
        set_skill("shenghuo-shengong",60);
        set_skill("qingyunwu", 60);
        set_skill("shenghuo-jian",60);
        set_skill("shenghuo-quan",60);
        set_skill("parry", 60);
        map_skill("dodge", "qingyunwu");
        map_skill("force","shenghuo-shengong");
        map_skill("sword","shenghuo-jian");
        map_skill("parry","shenghuo-jian");
        map_skill("unarmed","shenghuo-quan");
        create_family("明教",35,"教众");
        setup();
         carry_object("/clone/misc/cloth")->wear();
}

/*
void init()
{
       object ob;

       ::init();

        ob = this_player();
        if((int)ob->query("score") < -50 &&ob->query("family/master_id")=="xu da")
        {
                    command("chat "+ob->query("name")+"！你为人不忠不义，我明教岂能留你？\n");
                    command("expell "+ ob->query("id"));
                    this_player()->set("title","明教" + RED + "弃徒" NOR);   
        }

}

*/
void attempt_apprentice(object ob)

{
        if ((int)ob->query("shen") < 0) {
        command("say 我只怕不适合做你的师傅，你还是另投高就吧。");
                return;
        }
        command("say 快快起来，我最喜欢你这样的侠义之士，哈哈......。");
        command("recruit " + ob->query("id"));
        if((string)ob->query("class") != "shizhe")

        ob->set("class", "shizhe");
}


// huqingniu.c 胡青牛

#include <ansi.h>
inherit NPC;

string ask_liao();
string ask_me();

void create()
{
        set_name("胡青牛", ({ "hu qingniu", "hu" }));
        set("nickname", YEL"蝶谷医仙"NOR);
        set("long", 
                "他就是明教的见死不救医仙胡青牛。\n"
                "全身仙气笼绕，真有些仙风道骨的味道。\n");
        set("gender", "男性");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 26);
        set("int", 30);
        set("con", 26);
        set("dex", 30);
        
        set("max_qi", 1200);
        set("max_jing", 800);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 50);
        set("combat_exp", 100000);
        set("shen",3000);
        set("score", 10);

        set_skill("force", 80);
        set_skill("shenghuo-shengong", 60);
        set_skill("dodge", 50);
        set_skill("qingyunwu", 40);
        set_skill("shenghuo-quan", 60);
        set_skill("parry", 60);
        set_skill("literate", 80);

        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "qingyunwu");
        map_skill("unarmed", "shenghuo-quan");
        map_skill("parry", "shenghuo-quan");
        create_family("明教", 35, "弟子");
        set("inquiry", ([
              "疗伤" : (: ask_liao :),
              "灵药" : (: ask_me :),
        ]));
	 set("yao_count", 1);
        setup();
        carry_object("/clone/weapon/dagger");        
        carry_object("/clone/misc/cloth")->wear();
}

string ask_liao()
{
       mapping fam; 

       object ob;
        ob=this_player();
      write( "胡青牛正盯著你看，不知道打些什么主意。\n"); 
      if (!(fam = this_player()->query("family")) || fam["family_name"] != "明教")
               return RANK_D->query_respect(this_player()) + 
               "与本派素无来往，不知此话从何谈起？";
      if ((int)this_player()->query("eff_qi") >= (int)this_player()->query("max_qi")) 
        return RANK_D->query_respect(this_player()) + "气血充足，不用医治啊。";
         
       ob->set("eff_jing", (int)ob->query("max_jing"));
       ob->set("jing", (int)ob->query("max_jing"));
       ob->set("eff_qi", (int)ob->query("max_qi"));
       ob->set("qi", (int)ob->query("max_qi"));
       write( HIW "胡青牛从百汇给你注入一股内力，你觉得浑身暖洋洋的，好象失去的气血都回到了身上 \n"NOR);

       return "好了你可以走了"; 

}

string ask_me()
{
        mapping fam; 
        object ob;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "明教")
                return RANK_D->query_respect(this_player()) + 
                "与本派素无来往，不知此话从何谈起？";
        if (query("yao_count") < 1)
                return "你来晚了，本派的疗伤圣药不在此处。";
        add("yao_count", -1);
        ob = new(__DIR__"obj/heiyu");
        ob->move(this_player());
        return "好吧，这瓶黑玉断续膏你拿回去好好疗伤。";
}

void unconcious()
{
    command("say 我胡青牛一生从来不受人协迫， 哼！想我让给你疗伤， 来阴间找我吧．");
        tell_room(environment(this_object()), "胡青牛说完，掏出一把匕首，就往自己胸膛一插．\n");
        ::die();
}

void die()
{
        unconcious();
}


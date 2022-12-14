// chuzi.c

inherit NPC;

string ask_me();

void create()
{
        set_name("厨子", ({ "chu zi", "chu" }));
        set("title", "明教");
        set("long", 
                "明教的一个厨子，笑眯眯地看着你，看来很和善的样子。\n");
        set("gender", "男性");
        set("age", 34);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 26);
        set("int", 30);
        set("con", 26);
        set("dex", 28);
        
        set("max_qi", 200);
        set("max_jing", 50);
        set("neili", 0);
        set("max_neili", 0);
        set("jiali", 0);
        set("combat_exp", 500);
        set("shen",0);
        set("score", 0);
        set("no_get",1);
        set_skill("force", 10);
        set_skill("dodge", 10);
        set_skill("cuff", 10);
        set_skill("parry", 10);

        create_family("明教", 36, "弟子");
        set("inquiry", ([
                "进餐" : (: ask_me :),
        ]));

        setup();
       carry_object("/d/city/obj/cloth")->wear();
        
}

string ask_me()
{       mapping fam; 

       object me=this_player();
      if (!(fam = this_player()->query("family")) || fam["family_name"] != "明教")
                return RANK_D->query_respect(this_player()) + 
                "与本派素无来往，不知此话从何谈起？";

       me->set("food", (int)me->max_food_capacity());
       me->set("water", (int)me->max_water_capacity());
  
        return "慢慢吃！别噎住了。";
}



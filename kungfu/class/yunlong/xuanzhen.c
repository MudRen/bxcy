// xuanzhen.c 
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
int ask_weiwang();
string ask_me();
void create()
{
    set_name("玄真道长", ({ "xuan zhen", "xuan", "zhen" }));
    set("gender", "男性");
    set("long", "\n这位沉默寡言的道人，便是天地会青木堂护法。\n"+
        "他是青木堂数一数二的好手，一柄长剑使得出神入化。\n");
    set("age", 55);
    set("int", 30);
    
    set("qi", 1500);
    set("max_qi", 1500);
    set("jing", 500);
    set("max_jing", 500);
    set("shen_type", 1);
    set("combat_exp", 200000);
    set("attitude", "peaceful");
    set_skill("force", 200);
    set_skill("unarmed", 200);
    set_skill("parry", 200);
    set_skill("dodge", 200);
    set_skill("sword", 200);
    set_skill("whip", 200);
    set_skill("yunlong-shengong", 200);
    set_skill("yunlong-shenfa", 200);
    set_skill("yunlong-xinfa", 200);
    set_skill("yunlong-bian", 200);
    set_skill("yunlong-jian", 200);
    set_skill("yunlong-shou", 200);
    set_skill("yunlong-zhua", 200);
    set_temp("apply/attack", 80);
    set_temp("apply/defense", 70);
    set_temp("apply/damage", 60);
    map_skill("force", "yunlong-shengong");
    map_skill("dodge", "yunlong-shenfa");
    map_skill("parry", "yunlong-jian");
    map_skill("sword", "yunlong-jian");
    map_skill("unarmed", "yunlong-zhua");
    map_skill("whip", "yunlong-bian");
    create_family("云龙门",2, "弟子");
    set("class", "yunlong-xinfa");
    set("book_count", 1);
        set("inquiry", ([
        "陈近南" :  "\n江湖威望值达到70就可以拜总舵主为师。\n",
        "天地会" :  "\n只要是英雄好汉，都可以入我天地会(join tiandihui)。\n",
        "入会" :  "\n只要入了我天地会，可以向会中各位好手学武功。\n",
                "反清复明" : "去药铺和棺材店仔细瞧瞧吧！\n",
                "威望" :  (: ask_weiwang :),
                "江湖威望" : (: ask_weiwang :),
        "云龙经" : (: ask_me :),
       ]) );
    set("chat_chance_combat", 50);  
    set("chat_msg_combat", ({
        (: command("smile") :),
        (: command("haha") :),
        (: command("chat 这位" + RANK_D->query_respect(this_player())+",你我无冤无仇，何必如此?\n") :),
        (: command("unwield changjian") :),
        (: command("unwield changjian") :),
        (: command("unwield changjian") :),
        (: command("unwield changjian") :),
        (: command("unwield changjian") :),
        (: command("unwield changjian") :),
        (: command("unwield changjian") :),
        (: command("unwield changjian") :),
        (: command("wield changjian") :),
        (: command("wield changjian") :),
        (: command("wield changjian") :),
        (: command("wield changjian") :),
        (: command("wield changjian") :),
        (: command("wield changjian") :),
        (: command("wield bian") :),
        (: command("wield bian") :),
        (: command("wield bian") :),
        (: command("wield bian") :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "whip.chan" :),
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
        (: command("unwield bian") :),
        (: command("unwield bian") :),
        (: command("unwield bian") :),
        (: command("unwield bian") :),
                      }) );
    setup();
    carry_object("/clone/weapon/changjian")->wield();
    carry_object("/clone/misc/cloth")->wear();
        add_money("gold",3);
}
void init()
{
::init();
add_action("do_join","join");
remove_call_out("greeting");
call_out("greeting", 1, this_player());
}

int ask_weiwang()
{
command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
say("\n玄真说道：如果你威望值很高，有些人见了你不但不会杀你，还会教你武功，送你宝贝。\n"
+"而且你还可以加入帮会，率领会众去攻打目标，就连去钱庄取钱也会有利息 。。。。。\n");
say("玄真又说：杀某些坏人或救某些好人可以提高江湖威望。\n");
return 1;
}
string ask_me()
{
        mapping fam; 
        object ob;
        if (!(fam = this_player()->query("family")) 
        || fam["family_name"] != "云龙门")
                return RANK_D->query_respect(this_player()) + 
                "与本派素无来往，不知此话从何谈起？";
        if (query("book_count") < 1)
                return "你来晚了，本派的云龙真经不在此处。";
        add("book_count", -1);
        ob = new("/d/city2/obj/yljing2");
        ob->move(this_player());
        return "好吧，这本「云龙经」你拿回去好好钻研。";
}
void attempt_apprentice(object ob)
{
    if ((int)ob->query("weiwang") < 50) {
        command("say 我云龙门武功盖世，对弟子要求也是极高。");
        command("say " + RANK_D->query_respect(ob) + "若能先" +
            "加入我天地会，或许我可以考虑收你为徒。");
        return;
    }
    command("say 好吧，既然" + RANK_D->query_respect(ob) + "也是" +
        "我辈中人，今天就收下你吧。");
    command("recruit " + ob->query("id"));
    if((!(string)ob->query("class")) || ((string)ob->query("class") != "fighter"))
        ob->set("class","fighter");
}
int do_join(string arg)
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="tiandihui" )
    return notify_fail("你要加入什么组织？\n"); 
   if (ob->query("weiwang")<20)
        {
    command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
    message_vision(HIC "玄真对$N摇了摇头说：你的江湖威望值太低。\n" NOR,this_player());
    return 1;
    }
    if(ob->query("weiwang")<50)
    {
    ob->set("weiwang",50);
    message_vision(HIC "$N的江湖威望提高了！\n" NOR,this_player());
    command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
    return 1;
    }
   else return notify_fail("你已经加入天地会了！\n"); 
}
void greeting(object ob)
{
    if( !ob || environment(ob) != environment() ) return;
        if(ob->query("weiwang")>=50)
    switch( random(3)){
        case 1:
            say( "玄真笑道：这位" + RANK_D->query_respect(ob)
                + "，我带你去香堂吧。\n");
            ob->move("/d/city2/dating");
            message_vision("$N来到了大厅。\n",ob);
            break;
        default:
            say( "玄真说道：这位" + RANK_D->query_respect(ob)
                + "，请自便。\n");
            break;
    }
    else say( "玄真笑道：这位" + RANK_D->query_respect(ob)
                + "，到这儿来干什么？\n");
 
}
int do_skills(string arg)
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="chen" )
     return 0;
   if(wizardp(ob))  return 0;
   if (ob->query("weiwang")<50)
  {
   message_vision("$N摇了摇头。\n",this_object());
   command("tell "+ob->query("id")+" 不是天地会弟子不能察看。\n"); 
   return 1;
   }
   command("tell "+ob->query("id")+" 我所有的基本武功如下：\n"+
"  基本招架 (parry)                         - 深不可测 200/   \n"+
"  基本鞭法 (whip)                          - 深不可测 200/   \n"+
"  基本剑法 (sword)                         - 深不可测 200/   \n"+
"  基本拳脚 (unarmed)                       - 深不可测 200/   \n"+
"□云龙鞭法 (yunlong-bian)                  - 深不可测 200/   \n"+
"□云龙剑法 (yunlong-jian)                  - 深不可测 200/   \n"+
"□云龙身法 (yunlong-shenfa)                - 深不可测 200/   \n"+
"□云龙心法 (yunlong-xinfa)                 - 深不可测 200/   \n"+
"□云龙神功 (yunlong-shengong)              - 深不可测 200/   \n"+
"□云龙手 (yunlong-shou)                    - 深不可测 200/   \n"+
"□云龙爪 (yunlong-zhua)                    - 深不可测 200/   \n");
 return 1;
}
int recognize_apprentice(object ob)
{
    if (ob->query("weiwang")<50)
    {
    message_vision("$N摇了摇头。\n",this_object());
    command("tell "+ob->query("id")+" 不是天地会弟子我不教。\n"); 
    return 0;
    }
    return 1;
}

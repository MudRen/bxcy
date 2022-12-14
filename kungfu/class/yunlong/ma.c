
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
int ask_weiwang();
string ask_me();
void create()
{
    set_name("马超兴", ({ "ma chaoxing", "ma"}));
    set("gender", "男性");
    set("long", "\n他就是天地会洪顺堂堂主，善使一柄大刀。\n");
    set("attitude", "peaceful");
    set("age", 45);
    set("int", 30);
   
    set("qi", 1500);
    set("max_qi", 1500);
    set("jing", 500);
    set("neili",2000);
    set("max_neili",1000);
    set("shen_type", 1);
    set("combat_exp", 250000);
    set_skill("force", 120);
    set_skill("unarmed",120);
    set_skill("parry", 120);
    set_skill("dodge", 120);
    set_skill("sword", 120);
    set_skill("blade", 120);
    set_skill("whip", 120);
    set_skill("yunlong-shengong", 120);
    set_skill("yunlong-shenfa", 120);
    set_skill("wuhu-duanmendao", 120);
    set_skill("houquan", 120);
    set_skill("yunlong-jian", 120);
    set_skill("yunlong-bian", 120);
    set_temp("apply/attack", 25);
    set_temp("apply/defense", 25);
    set_temp("apply/damage", 25);
    map_skill("force", "yunlong-shengong");
    map_skill("dodge", "yunlong-shenfa");
    map_skill("parry", "wuhu-duanmendao");
        map_skill("blade","wuhu-duanmendao");
    map_skill("sword", "yunlong-jian");
    map_skill("whip", "yunlong-bian");
        map_skill("unarmed","houquan");
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
        (: command("wield bian") :),
        (: command("wield bian") :),
        (: command("wield bian") :),
        (: command("wield bian") :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "blade.duan" :),
                (: perform_action, "blade.duan" :),
                (: perform_action, "blade.duan" :),
                (: perform_action, "unarmed.zhen" :),
                (: perform_action, "unarmed.zhen" :),
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
        (: command("unwield bian") :),
        (: command("unwield bian") :),
        (: command("unwield bian") :),
        (: command("unwield bian") :),
        (: command("wield blade") :),
        (: command("wield blade") :),
        (: command("wield blade") :),
        (: command("wield blade") :),
        (: command("unwield blade") :),
        (: command("unwield blade") :),
        (: command("unwield blade") :),
        (: command("unwield blade") :),
        (: command("unwield blade") :),
        (: command("unwield blade") :),
                      }) );
    setup();
    carry_object("/d/shaolin/obj/changbian")->wield();
    carry_object("/clone/weapon/changjian")->wield();
    carry_object("/d/city2/obj/dadao")->wield();
    carry_object("/clone/misc/cloth")->wear();
        add_money("silver",20);
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
say("\n马超兴说道：如果你威望值很高，有些人见了你不但不会杀你，还会教你武功，送你宝贝。\n"
+"而且你还可以加入帮会，率领会众去攻打目标，就连去钱庄取钱也会有利息 。。。。。\n");
say("马超兴又说：杀某些坏人或救某些好人可以提高江湖威望。\n");
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
        ob = new("/d/city2/obj/yljing1");
        ob->move(this_player());
        return "好吧，这本「云龙经」你拿回去好好钻研。";
}
void attempt_apprentice(object ob)
{
if((string)ob->query("gender")=="无性")
           {
        command("say 云龙门顶天立地，怎会收你这样的废人？！");
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
    message_vision(HIC "马超兴对$N摇了摇头说：你的江湖威望值太低。\n" NOR,this_player());
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
               if(random(5)<2) say( "马超兴笑道：这位" + RANK_D->query_respect(ob)
                + "，可有什么不平之事么？\n");
 
}
int do_skills(string arg)
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="ma" )
     return 0;
   if(wizardp(ob))  return 0;
   if (ob->query("weiwang")<50)
  {
   message_vision("$N摇了摇头。\n",this_object());
   command("tell "+ob->query("id")+" 不是天地会弟子不能察看。\n"); 
   return 1;
   }
   command("tell "+ob->query("id")+" 我所有的基本武功如下：\n"+
"  基本刀法 (blade)                         - 深不可测 120/    \n"+
"  基本轻功 (dodge)                         - 深不可测 120/    \n"+
"  基本内功 (force)                         - 深不可测 120/    \n"+
"  基本招架 (parry)                         - 深不可测 120/    \n"+
"  基本剑法 (sword)                         - 深不可测 120/    \n"+
"  基本拳脚 (unarmed)                       - 深不可测 120/    \n"+
"  基本鞭法 (whip)                          - 深不可测 120/    \n"+
"□五虎断门刀 (wuhu-duanmendao)             - 深不可测 120/    \n"+
"□猴拳 (houquan)                           - 深不可测 120/    \n"+
"□云龙鞭 (yunlong-bian)                    - 深不可测 120/    \n"+
"□云龙剑法 (yunlong-jian)                  - 深不可测 120/    \n"+
"□云龙身法 (yunlong-shenfa)                - 深不可测 120/    \n"+
"□云龙神功 (yunlong-shengong)              - 深不可测 120/    \n");
 return 1;
}


#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_skills(string arg);
int do_join(string arg);
void create()
{
    set_name("陆高轩", ({ "lu gaoxuan", "lu" ,"gaoxuan"}));
    set("title", "神龙教军师");
    set("nickname",HIC "神机妙算" NOR);
    set("long", "他天庭饱满,地阔方圆,容貌颇为英俊.\n然而满面愁容,恰似顷刻间便有杀身之祸一般.\n" );
    set("gender", "男性");
    set("age", 37);
    set("str", 35);
    set("dex", 20);
    set("max_qi",2000);
        set("qi",2000);
    set("max_jing",500);
        set("jing",500);
    set("combat_exp", 300000);

    set("shen_type", -1);
    set("attitude", "peaceful");
    set_skill("force", 150);
    set_skill("unarmed", 100);
    set_skill("staff", 100);
    set_skill("sword", 100);
    set_skill("parry", 100);
    set_skill("dodge", 100);
    set_skill("hamagong", 90);
    set_skill("yixingbu", 90);
    set_skill("shenlong-bashi", 100);
    set_skill("shedao-qigong", 80);
    set_skill("hamagong", 90);
    set_skill("shexing-diaoshou", 80);
    set_skill("tianshan-zhang", 80);
    map_skill("dodge", "yixingbu");
    map_skill("force", "hamagong");
    map_skill("sword", "shedao-qigong");
    map_skill("unarmed", "shexing-diaoshou");
    map_skill("parry", "shexing-diaoshou");
    map_skill("staff", "tianshan-zhang");
    set_temp("apply/attack", 60);
    set_temp("apply/defense", 60);
    set_temp("apply/armor", 30);
    set_temp("apply/damage", 60);
    set("neili", 2000); 
    set("max_neili", 2000);
    set("jiali", 75);
        set("inquiry", ([
        "神龙教" :  "一般人是入不了我神龙教的(join shenlongjiao).\n",
        "入教" :  "一般人是入不了我神龙教的(join shenlongjiao).\n",
        "洪安通" :  "教主脾气不好,要讨他欢心才好。\n",
        "教主" :  "教主脾气不好,要讨他欢心才好。\n",
        "口号" : "万年不老!永享仙福!寿与天齐!文武仁圣!\n",
       ]) );
       
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: command("wield sword") :),
        (: perform_action, "sword.chang" :),
        (: perform_action, "sword.chang2" :),
        (: perform_action, "sword.chang3" :),
        
    }) );


    setup();
    carry_object("/clone/misc/cloth")->wear();
    carry_object("/d/city/obj/changjian");
    add_money("silver", 10);
}
void init()
{
add_action("do_skills","skills");
add_action("do_skills","cha");
add_action("do_join","join");
}
int recognize_apprentice(object ob)
{
    if (!ob->query("shenlongjiao"))
    {
    message_vision("$N摇了摇头。\n",this_object());
    command("tell "+ob->query("id")+"你我素不相识，我赁什么要教你呢？ \n"); 
    return 0;
    }
    return 1;   
}
int do_skills(string arg)
{
   object ob ;
   ob = this_player () ;
    if( !arg || arg!="pang" )
     return 0;
   if(wizardp(ob)) return 0;
  if (!ob->query("shenlongjiao"))
  {
   message_vision("$N摇了摇头。\n",this_object());
   write("陆高轩说道：你怎么能看我的武功呢？\n");
   return 1;
  }
   command("tell "+ob->query("id")+" 我所有的武功如下：\n"+
"  基本轻功 (dodge)                         - 深不可测 100/    \n"+
"  基本内功 (force)                         - 深不可测 150/    \n"+
"  基本招架 (parry)                         - 深不可测 100/    \n"+
"□蛇岛奇功 (shedao-qigong)                 - 登峰造极  80/    \n"+
"  神龙八式 (shenlong-bashi)                - 深不可测 100/    \n"+
"  基本剑法 (sword)                         - 深不可测 100/    \n"+
"  基本杖法 (staff)                         - 深不可测 100/    \n"+
"  基本拳脚 (unarmed)                       - 深不可测 100/    \n"+
"□蛤蟆功 (hamagong)                        - 一代宗师  90/    \n"+
"□蛇形刁手 (shexing-diaoshou)              - 登峰造极  80/    \n"+
"□天山杖法 (tianshan-zhang)                - 登峰造极  80/    \n"+
"□意形步 (yixingbu)                        - 一代宗师  90/    \n");
 return 1;
}
int do_join(string arg)
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="shenlongjiao" )
    return notify_fail("你要加入什么组织？\n"); 
   if(ob->query("shenlongjiao")) 
    {
    message_vision(HIC "陆高轩说道：你已经是神龙教弟子了。\n" NOR,this_player());
    return 1;
    }
   if ((int)ob->query("shen")>-1000)
        {
    message_vision(HIC "陆高轩对$N大怒道：还想入教?一看你就不是好人!\n" NOR,this_player());
    set_leader(this_player());
    remove_call_out("kill_ob");
    call_out("kill_ob", 1, this_player()); 
    return 1;
    }
   if (ob->query("combat_exp")<20000)
        {
    message_vision(HIC "陆高轩对$N摇头道：你的实战经验太低。\n" NOR,this_player());
    return 1;
    }
  if ( ob->query_skill("bibo-shengong",1)
    || ob->query_skill("hamagong",1)
    || ob->query_skill("huagong-dafa",1))
   {
    ob->set("shenlongjiao",1);
    command("tell "+this_player()->query("id")+" 你现在就是神龙教弟子了.\n");
    return 1;   
   }
   else 
   {
   message_vision(HIC "陆高轩对$N大怒道：还想入教?一看你就不是好人!\n" NOR,this_player());
    set_leader(this_player());
    remove_call_out("kill_ob");
    call_out("kill_ob", 1, this_player()); 
    return 1;
    }
}

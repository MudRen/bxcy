// pal 1997.05.28
#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
int ask_news();
int ask_meeting();
int hai_tu();
void create()
{
        set_name("游讯", ({ "you xun", "you", "xun" }) );
        set("nickname", "滑不留手");
        set("gender", "男性" );
        set("age", 42);
        set("long",
                "他就是专门打探、贩卖消息的游讯。\n");
        set("combat_exp", 100000);
        set("attitude", "friendly");
        set("max_jing",500);
        set("max_qi",500);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 30);
        set("inquiry", ([
        "name" : "小的就是游讯，不知您要打听点什么？",
        "欧冶子"  : "您问可以帮玩家造兵器的欧冶老爷子呀！据说他现在带着徒弟到西域去\n居住了，有人说他现在本事更大了，也不知真假。\n",
        "波斯人"  : "听说是什么劳什子圣使。",
          "海图"  : (: hai_tu :),
          "翻船"  : "听说是因为丢了一张什么海图。",
        "news" : (: ask_news :),
        "meeting" : (: ask_meeting :),
        "新闻" : (: ask_news :),
        "比武大会" : (: ask_meeting :),
        ]) );
        set_skill("literate", 100);
        set_skill("dodge", 100);
        set_skill("unarmed", 100);
        setup();
        add_money("gold", 5);
    carry_object("d/city/obj/cloth")->wear();
}
void init()
{
    object ob;
    ::init();
    if( interactive(ob = this_player()) && !is_fighting() ) {
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
    }
}
void greeting(object ob)
{
    if( !ob || (environment(ob) != environment()) ) return;
    command("hi "+ob->query("id"));
    say("游讯左右看了看，小声说到：这位" + RANK_D->query_respect(ob) + "，可听说了前些日子\n"
                 "在这出海的波斯人一出海就翻船了。\n");
}
int ask_news()
{
    int rows;
    string temp;
    temp = read_file(__DIR__"news.txt", 2, 1);
    rows = atoi(temp);
    temp = read_file(__DIR__"news.txt", 3, rows);
    temp = "游讯说道：\n"+temp+"\n";
    write(temp);
    return 1 ;
}
int ask_meeting()
{
    int rows;
    string temp;
    temp = read_file(__DIR__"meeting.txt", 2, 1);
    rows = atoi(temp);
    temp = read_file(__DIR__"meeting.txt", 3, rows);
    temp = "游讯说道：\n"+temp+"\n";
    write(temp);
    return 1 ;
}
int hai_tu()
{
  object ob ;
  ob = this_player ( ) ;
  message_vision("游讯上上下下打量了$N一下：什么！海图？你不要命了？那里很危险的呀！\n"
                 "游讯又想了一下：嘿、嘿！不过...如果给我一百两金子，或许可以考虑。\n"
                 ,ob);
  ob->set_temp ("tmark/图" , 1 );
  return 1;
}
int accept_object(object who, object ob)
{
    object myenv ;
    if ((int)who->query_temp("tmark/图"))
    {
    if (ob->query("money_id") && ob->value() >= 1000000) {
        message_vision("游讯对$N说：好！既然这位" + RANK_D->query_respect(who) +
        "如此看得起我，\n那我也就告诉你了吧！\n" , who);
        command("whisper " +who->query("id")+ " 那海图好象是在沼泽里。\n");        
        this_player()->delete_temp("海图" );
        myenv = environment (who) ;
        tell_room(myenv,
        "游讯掂着手里的金子笑道：去沼泽？送死的事情我可不干。\n"
        "只可惜了好一位" + RANK_D->query_respect(who) +"。嘿嘿，哈哈！\n") ;
        return 1;
    }
    else { 
    message_vision("游讯笑着对$N说：无功不受禄，您还是自己留着吧！\n", who);
    return 0 ;
         }
    }
    return 0 ;    
}


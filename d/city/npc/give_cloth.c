// /d/city/npc/give_clotht.c 负责送衣服的npc
#define LAST_PAR "sorry"
#define THIS_PAR "sorrysf"
inherit NPC;
string give_cloth();
string ask_shen();
string ask_du();
int ask_mask(string str);	
void create()
{
set_name(MAG"阿凯哥哥"NOR, ({ "akaigege", "akai gege","akais"}));    	
set("title", HIY"战龙王"NOR);	
set("nickname", HIC"新手使者"NOR);	
    set("str", 37);
    set("gender", "男性");
    set("age", 20);
set("per",10);
    set("long",
        "他是战龙堂的堂主，一个可以和神较量的人，和AKAI是朋友，\n 今天被AKAI骗到这里当新手使者的。现在主要是给新手发礼物的T_T\n");
    set("combat_exp", 1500);
set("no_get",1);
    set("attitude", "friendly");
    set("inquiry", ([
        "衣服" : (: give_cloth :),
//"cloth"  :(: give_cloth :),	
"礼物":"桌子(table)上就有呀，新人可以拿哦~：）\n",      	
"面具"  :(: ask_mask :),
"清毒"  :(: ask_du :),
"清神" : (: ask_shen :),
"你是谁":"AKAI这个家伙，居然骗我说：在这里会有很多美眉来找我，可是来的人全部是男的，\n好不容易看的一个像是女人的，可是一查，既然是变性的人妖T_T! 该死的家伙，看我下次遇到他不杀死他！\n”妈的，FUCK，干，我 do run！“突然捂着嘴，又跟AKAI说脏话了。哦，对了，你刚才说什么？你可以去找AKAI吗，他的QQ是21787070，我现在忙，叫他回答你的问题\n"
	]));
    
    setup();
carry_object("/clone/misc/changpao")->wear();	
//  carry_object("/d/shaolin/obj/qimeigun")->wield();
}

string give_cloth()
{
    
    object me,obj;
       me = this_player();
if (me->query("gender")=="女性") obj=new("/clone/cloth/female1-cloth");
	   else obj=new("/clone/cloth/cloth");
	   obj->move(me);
	   command("xixi");
return "赶快穿上吧：）";
}
int ask_mask(string arg)	
{
object me,obj;	
object zi;	
me = this_player();	
zi=this_object();	
if(present("mian ju", me) || present("mian ju", environment()))   	
{
command("say 已经有了还想拿,你怎么如此贪得无厌呢?"); 	
return 1;       	
}
if (me->query("age",1) >=18)
{
command("say 老大不小的了,还只会饭来张口,衣来伸手,该学学独立生活了!");	
return 1;	
}
else {  	
message_vision(CYN "阿凯微笑着拿出个面具，送了给$N \n" NOR,me);	
obj=new("/clone/misc/mianju");      	
obj->move(me);	
command("love");  	
return 1;	
}
}
string ask_shen()
 {
        object me = this_player();
if (me->query("age",1) >=18)
{
return "老大不小的了,还只会饭来张口,衣来伸手,该学学独立生活了!";	
}else{
               me->set("shen", 0);
   me->start_busy(3);
                return "天神啊！让这个心灵受伤害的人重生吧！\n"
HIW"突然天空中一道"HIY"金光"HIW"笼罩四方，转瞬即逝！"NOR;
}
}
string ask_du()
 {
        object me = this_player();
if (me->query("age",1) >=18)
{
return "老大不小的了,还只会饭来张口,衣来伸手,该学学独立生活了!";	
}else{

               me->clear_condition();
   me->start_busy(3);
                return "天神啊！就让这弱小的生灵重生吧！\n"
HIW"突然天空中一道"HIY"金光"HIW"笼罩四方，转瞬即逝！"NOR;
}
}

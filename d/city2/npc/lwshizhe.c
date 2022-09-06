// lwshizhe.c 送礼使者
inherit NPC;
inherit F_MASTER;
int ask_gift(string str);	
void create()
{
set_name(HIC"送礼特使"NOR, ({ "gift shizhe", "shizhe","teshi"}));      	
set("title", HIM"小天使"NOR);     	
set("nickname", HIM"紫衣神女"NOR);      	
    set("str", 37);
    set("gender", "女性");
    set("age", 14);
set("per",30);
    set("long",
"这是一个美丽动人的小姑娘，大大的眼睛里闪着无限的热情。\n 她在这里专门给大家发送节日礼物。\n");	
set("combat_exp", 15000000);   	
set("max_qi", 3000000);   	
set("max_jing", 3000000);   	
set("neili", 15000000);   	
set("jiali", 50000);   	
set("no_get", 1);	
    set("attitude", "friendly");
    set("inquiry", ([
"礼物": (: ask_gift :),
	]));
    
    setup();
carry_object("/clone/cloth/female1-cloth")->wear();	
//  carry_object("/d/shaolin/obj/qimeigun")->wield();
}

int ask_gift(string arg)	
{
    
object me;
object shizhe;	
object gift;
       me = this_player();
shizhe=this_object(); 	
//if ( !wizardp(me) )
//return notify_fail("今天好象没什么特别的礼物哦!");
if (me->query("1230_gift",1))     	
{
command("say 对不起哦，你已经拿过礼物了不能再给你了。");
return 1;
}
else {
message_vision(CYN "送礼特使拿出一个礼物包送给了$N \n" NOR,me);
gift=new("/clone/misc/gift");	
gift->move(me);	
me->delete("11_gift");         	
me->set("1230_gift",1);           	
return 1;
}
}

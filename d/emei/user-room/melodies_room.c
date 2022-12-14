// marry_room.c

#include <room.h>
#include <ansi.h>

inherit ROOM;

string look_duilian();
int do_sing(string stage);
void create()
{
        set("short", "麦芽儿和雪儿的新居");
        set("long", @LONG
这儿是麦芽儿(melodies)和雪儿(xuer)的新居，正厅墙壁之上挂着
一付对联（duilian）。这对璧人将于今夜在此迈向新的旅途，为了答谢
各位朋友的厚爱，雪儿同麦芽儿设酒宴款待各位朋友。四下里宾客如云，
热闹非凡，不时传来道喜之声。
LONG
        );
        set("exits", ([
                "south": "/d/shaolin/marry_room", 
                "west":"/d/emei/sroad1",
         ]) );
//           "/d/shaolin/marry_room"->set("exits/north","/d/emei/user-room/melodies_room");	
	set("no_die", 1);
	set("no_roar", 1);
	set("no_steal", 1);
	set("no_fight", 1);
	set("item_desc",([
		"duilian"	:	(: look_duilian :),
	]));

       setup();

}
void init()
{
	add_action("do_sing","sings");
}
int do_sing(string stage)
{
	object me,ob1,ob2;
	object* userall;
	object sweets,wine,cigarette;
	int i;
	me=this_player();
	userall=users();
	//if(!stage||stage>4||stage<0)return 0;
	if(!objectp(ob1=present("melodies",environment(me))))
		return notify_fail("麦芽儿还不在呢。\n");
	if(!objectp(ob2=present("xuer",environment(me))))
		return notify_fail("雪儿还不在呢。\n");
if((me->query("id")!="hop")&&(me->query("id")!="host")&&(me->query("id")!="aman"))
		return notify_fail("你又不是主婚人！\n");
	switch(stage){
	case "1":if(me->query_temp("marks/1"))return 1;
		 message_vision(MAG "$N高声唱道：一拜天地！\n" NOR,me);
		 message_vision(HIG "$N和$n恭恭敬敬地跪拜下去。\n" NOR,ob1,ob2);
		 me->set_temp("marks/1",1);
		 break;
	case "2":if(!me->query_temp("marks/1"))return 1;
		 if(me->query_temp("marks/2"))return 1;
		 message_vision(MAG "$N高声唱道：二拜高朋！\n" NOR,me);
		 message_vision(HIG "$N和$n向各位巫师和玩家朋友拜了一拜，大家纷纷还礼。\n" NOR,ob1,ob2);
		 me->set_temp("marks/2",1);
		 break;
	case "3":if(!me->query_temp("marks/2"))return 1;
		 if(me->query_temp("marks/3"))return 1;
		 message_vision(MAG "$N高声唱道：夫妻对拜！\n" NOR,me);
		 message_vision(HIG "$N和$n转过身来，互相对拜。\n" NOR,ob1,ob2);
		 me->set_temp("marks/3",1);

		 break;
	case "4":if(!me->query_temp("marks/3"))return 1;
		 message_vision(MAG "$N高声唱道：送入洞房！\n" NOR,me);
		 message_vision(HIG "$N和$n缓缓步入洞房。\n" NOR,ob1,ob2);
     		 ob1->set("couple/couple_name",(string)ob2->name());
	       ob1->set("couple/couple_id",ob2->query("id"));
     		 ob2->set("couple/couple_name",(string)ob1->name());
	       ob2->set("couple/couple_id",ob1->query("id"));
		 ob1->set("couple/couple_gender","丈夫");
		 ob2->set("couple/couple_gender","妻子");
		 ob1->add("married",1);
		 ob1->set("couple/have_couple",1);
		 ob2->add("married",1);
		 ob2->set("couple/have_couple",1);
             for ( i=1;i<sizeof(userall); i++ )
             {
	         sweets = new("/d/shaolin/obj/marry_sweets");
	         wine = new("/d/shaolin/obj/marry_wine");
		 cigarette = new ("/d/emei/user-room/smoke");
	         sweets->move(userall[i-1]);
	         wine->move(userall[i-1]);
		 cigarette->move(userall[i-1]);
	         if ( i>=sizeof(userall) )
	         {
		      i=1;
	            break;
	         }
             }
  		 CHANNEL_D->do_channel(me, "chat",
		     sprintf( "恭喜%s和%s，一对璧人喜结良缘。\n", ob1->name(), ob2->name()));
             CHANNEL_D->do_channel(me, "chat",
   		     sprintf( "为了庆祝这对新人的结合，每人赠送一包喜糖。\n"));
		 ob1->move("/d/emei/user-room/home");
		 ob2->move("/d/emei/user-room/home");
		 environment(me)->set("exits/east","/d/emei/user-room/home");
		 message_vision(HIR "闹洞房去喽！\n" NOR,me);
		 break;
	default :break;
	}
	return 1;
}
string look_duilian()
{
       string duilian;
       duilian = read_file("/d/emei/user-room/duilian.txt", 1, 14);
//       write(duilian);
       return duilian; 
}

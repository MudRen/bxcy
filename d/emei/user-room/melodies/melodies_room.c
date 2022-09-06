// marry_room.c

#include <room.h>
#include <ansi.h>

inherit ROOM;

string look_duilian();
int do_sing(string stage);
void create()
{
        set("short", "��ѿ����ѩ�����¾�");
        set("long", @LONG
�������ѿ��(melodies)��ѩ��(xuer)���¾ӣ�����ǽ��֮�Ϲ���
һ��������duilian���������˽��ڽ�ҹ�ڴ������µ���;��Ϊ�˴�л
��λ���ѵĺ񰮣�ѩ��ͬ��ѿ�����������λ���ѡ�������������ƣ�
���ַǷ�����ʱ������ϲ֮����
LONG
        );
        set("exits", ([
                "south": "/d/shaolin/marry_room", 
                 "west":"/d/emei/sroad2",
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
		return notify_fail("��ѿ���������ء�\n");
	if(!objectp(ob2=present("xuer",environment(me))))
		return notify_fail("ѩ���������ء�\n");
if((me->query("id")!="hop")&&(me->query("id")!="host")&&(me->query("id")!="aman"))
		return notify_fail("���ֲ��������ˣ�\n");
	switch(stage){
	case "1":if(me->query_temp("marks/1"))return 1;
		 message_vision(MAG "$N����������һ����أ�\n" NOR,me);
		 message_vision(HIG "$N��$n���������ع����ȥ��\n" NOR,ob1,ob2);
		 me->set_temp("marks/1",1);
		 break;
	case "2":if(!me->query_temp("marks/1"))return 1;
		 if(me->query_temp("marks/2"))return 1;
		 message_vision(MAG "$N�������������ݸ���\n" NOR,me);
		 message_vision(HIG "$N��$n���λ��ʦ��������Ѱ���һ�ݣ���ҷ׷׻���\n" NOR,ob1,ob2);
		 me->set_temp("marks/2",1);
		 break;
	case "3":if(!me->query_temp("marks/2"))return 1;
		 if(me->query_temp("marks/3"))return 1;
		 message_vision(MAG "$N�������������޶԰ݣ�\n" NOR,me);
		 message_vision(HIG "$N��$nת������������԰ݡ�\n" NOR,ob1,ob2);
		 me->set_temp("marks/3",1);

		 break;
	case "4":if(!me->query_temp("marks/3"))return 1;
		 message_vision(MAG "$N�������������붴����\n" NOR,me);
		 message_vision(HIG "$N��$n�������붴����\n" NOR,ob1,ob2);
     		 ob1->set("couple/couple_name",(string)ob2->name());
	       ob1->set("couple/couple_id",ob2->query("id"));
     		 ob2->set("couple/couple_name",(string)ob1->name());
	       ob2->set("couple/couple_id",ob1->query("id"));
		 ob1->set("couple/couple_gender","�ɷ�");
		 ob2->set("couple/couple_gender","����");
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
		     sprintf( "��ϲ%s��%s��һ�����ϲ����Ե��\n", ob1->name(), ob2->name()));
             CHANNEL_D->do_channel(me, "chat",
   		     sprintf( "Ϊ����ף������˵Ľ�ϣ�ÿ������һ��ϲ�ǡ�\n"));
		 ob1->move("/d/emei/user-room/home");
		 ob2->move("/d/emei/user-room/home");
		 environment(me)->set("exits/east","/d/emei/user-room/home");
		 message_vision(HIR "�ֶ���ȥඣ�\n" NOR,me);
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

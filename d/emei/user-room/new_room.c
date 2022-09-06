// marry_room.c
 
#include <room.h>
#include <ansi.h>
 
inherit ROOM;
 
string look_duilian();
int do_sing(string stage);
int wedding(string arg);
string newshort;
string newlong;

string home; //新人的新房的位置
//int flag=0; //是否有人结婚？有则＝ non-zero
string wife, husband;

//int set_flag(int f);

void create()
{
//	if(flag==0)
//	{
        set("short", "教堂");
        set("long", @LONG
这是一间深沉肃穆的教堂，专门为有情人作新婚典礼。
因为现在没有婚礼(wedding)举行，四周空荡荡的，
隐约能够听到唱诗(sings)的声音。
LONG
        );
        set("exits", ([
                "south": "/d/shaolin/marry_room",
         ]) );
//     }
      set("item_desc",([
              "duilian"       :       (: look_duilian :),
      ]));
//     }

//        set("no_roar", 1);
        set("no_steal", 1);
        set("no_fight", 1);
 
       setup();
 
}
void init()
{
        add_action("do_sing","sings");
        add_action("do_wed","wedding");
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
        if(!objectp(ob1=present(wife,environment(me))))
                return notify_fail(find_player(wife)->name()+
                    "还不在呢。\n");
        if(!objectp(ob2=present(husband,environment(me))))
                return notify_fail(find_player(husband)->name()+
                  "还不在呢。\n");
if((me->query("id")!="hop")&&(me->query("id")!="melodies")&&(me->query("id")!="xinyue" ))
       return notify_fail("你又不是主婚人！瞎嚷嚷什麽？\n");
        switch(stage){
        case "1":if(me->query_temp("marks/1"))return 1;
                 message_vision(
                     MAG "\n$N高声唱道：一拜天地！\n\n" NOR,me);
      message_vision(HIG "$N和$n恭恭敬敬地跪拜下去。\n" 
                                NOR,ob1,ob2);
                 me->set_temp("marks/1",1);
                 break;
        case "2":if(!me->query_temp("marks/1"))return 1;
                 if(me->query_temp("marks/2"))return 1;
                 message_vision(
                      MAG "\n$N高声唱道：二拜高朋！\n\n" NOR,me);
                 message_vision(
HIG"$N和$n向各位巫师和玩家朋友拜了一拜，大家纷纷还礼。\n"NOR,
                               ob1,ob2);
                 me->set_temp("marks/2",1);
                 break;
        case "3":if(!me->query_temp("marks/2"))return 1;
                 if(me->query_temp("marks/3"))return 1;
                 message_vision(
               MAG "\n$N高声唱道：夫妻对拜！\n\n" NOR,me);
                 message_vision(
             HIG "$N和$n转过身来，互相对拜。\n" NOR,ob1,ob2);
                 me->set_temp("marks/3",1);
 
                 break;
        case "4":if(!me->query_temp("marks/3"))return 1;
                 message_vision(
                      MAG "\n$N高声唱道：送入洞房！\n\n" NOR,me);
                 message_vision(
                  HIG "$N和$n缓缓步入洞房。\n" NOR,ob1,ob2);
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
                     sprintf( "恭喜%s和%s，一对璧人喜结良缘。\n",
                  ob1->name(),ob2->name()));
             CHANNEL_D->do_channel(me, "chat",
                     sprintf( 
"为了庆祝这对新人的结合，每人赠送一包喜糖，一包喜烟，一瓶喜酒\n"));
                 ob1->command("go north");
                 ob2->command("go north");
                 message_vision(HIR "闹洞房去喽！\n" NOR,me);
                 break;
        default :break;
        }
        return 1;
}
string look_duilian()
{
       string duilian;
       duilian = read_file("/d/emei/user-room/duilian.txt");
//       write(duilian);
       return duilian;
}

//int set_flag(int f)
//{
//flag=f;
//create(); //更新房间描述；
//return flag;
//}

int do_wed(string who)
{
object me,obj1,obj2;
me=this_player();
if((me->query("id")!="hop")&&(me->query("id")!="melodies")&&(me->query("id")!="xinyue" ))
   return notify_fail("你又不是主婚人！瞎嚷嚷什麽？\n");

if(!who)
  {
//  set_flag(1); //开始婚礼；
      newshort=read_file(__DIR__"short.txt");
      newlong =read_file(__DIR__"long.txt");
//      home    =read_file(__DIR__"config.txt",1,1); //读入第一行。
//      husband =read_file(__DIR__"config.txt",2,1); //读入第二行
//      wife    =read_file(__DIR__"config.txt",3,1); //读入第三行。

husband = "yjz";
wife    = "sunrise";

set("short",newshort);
set("long", newlong);
      set("exits", ([
              "south": "/d/shaolin/marry_room",
              "north": "/d/emei/user-room/sunrise/home",
//              "north": home,
      ]) );


  return  message_vision(
MAG "\n $N  说 道：婚 礼 开 始！！！\n\n" NOR,me);
  }
else {
        sscanf(who,"%s %s",husband,wife);
       if((!husband)||(!wife))
                return notify_fail("谁要进行结婚典礼呀？\n");
        if(!objectp(obj1 = present(husband, environment(me))))
                return notify_fail("这里没有"+husband+"。\n");
        if(!objectp(obj2 = present(wife, environment(me))))
                return notify_fail("这里没有"+wife+"。\n");
        if( obj1->query("gender") == obj2->query("gender") )
      return notify_fail("你没问题吧，喜欢搞同性恋!?\n");
  return  message_vision(
MAG "\n $N 说 道： 新 人 开 始 拜 堂！\n\n" NOR,me);

      }
}

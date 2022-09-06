// marry_room.c
 
#include <room.h>
#include <ansi.h>
 
inherit ROOM;
 
string look_duilian();
int do_sing(string stage);
int wedding(string arg);
string newshort;
string newlong;

string home; //���˵��·���λ��
//int flag=0; //�Ƿ����˽�飿���� non-zero
string wife, husband;

//int set_flag(int f);

void create()
{
//	if(flag==0)
//	{
        set("short", "����");
        set("long", @LONG
����һ��������µĽ��ã�ר��Ϊ���������»����
��Ϊ����û�л���(wedding)���У����ܿյ����ģ�
��Լ�ܹ�������ʫ(sings)��������
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
                    "�������ء�\n");
        if(!objectp(ob2=present(husband,environment(me))))
                return notify_fail(find_player(husband)->name()+
                  "�������ء�\n");
if((me->query("id")!="hop")&&(me->query("id")!="melodies")&&(me->query("id")!="xinyue" ))
       return notify_fail("���ֲ��������ˣ�Ϲ����ʲ�᣿\n");
        switch(stage){
        case "1":if(me->query_temp("marks/1"))return 1;
                 message_vision(
                     MAG "\n$N����������һ����أ�\n\n" NOR,me);
      message_vision(HIG "$N��$n���������ع����ȥ��\n" 
                                NOR,ob1,ob2);
                 me->set_temp("marks/1",1);
                 break;
        case "2":if(!me->query_temp("marks/1"))return 1;
                 if(me->query_temp("marks/2"))return 1;
                 message_vision(
                      MAG "\n$N�������������ݸ���\n\n" NOR,me);
                 message_vision(
HIG"$N��$n���λ��ʦ��������Ѱ���һ�ݣ���ҷ׷׻���\n"NOR,
                               ob1,ob2);
                 me->set_temp("marks/2",1);
                 break;
        case "3":if(!me->query_temp("marks/2"))return 1;
                 if(me->query_temp("marks/3"))return 1;
                 message_vision(
               MAG "\n$N�������������޶԰ݣ�\n\n" NOR,me);
                 message_vision(
             HIG "$N��$nת������������԰ݡ�\n" NOR,ob1,ob2);
                 me->set_temp("marks/3",1);
 
                 break;
        case "4":if(!me->query_temp("marks/3"))return 1;
                 message_vision(
                      MAG "\n$N�������������붴����\n\n" NOR,me);
                 message_vision(
                  HIG "$N��$n�������붴����\n" NOR,ob1,ob2);
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
                     sprintf( "��ϲ%s��%s��һ�����ϲ����Ե��\n",
                  ob1->name(),ob2->name()));
             CHANNEL_D->do_channel(me, "chat",
                     sprintf( 
"Ϊ����ף������˵Ľ�ϣ�ÿ������һ��ϲ�ǣ�һ��ϲ�̣�һƿϲ��\n"));
                 ob1->command("go north");
                 ob2->command("go north");
                 message_vision(HIR "�ֶ���ȥඣ�\n" NOR,me);
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
//create(); //���·���������
//return flag;
//}

int do_wed(string who)
{
object me,obj1,obj2;
me=this_player();
if((me->query("id")!="hop")&&(me->query("id")!="melodies")&&(me->query("id")!="xinyue" ))
   return notify_fail("���ֲ��������ˣ�Ϲ����ʲ�᣿\n");

if(!who)
  {
//  set_flag(1); //��ʼ����
      newshort=read_file(__DIR__"short.txt");
      newlong =read_file(__DIR__"long.txt");
//      home    =read_file(__DIR__"config.txt",1,1); //�����һ�С�
//      husband =read_file(__DIR__"config.txt",2,1); //����ڶ���
//      wife    =read_file(__DIR__"config.txt",3,1); //��������С�

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
MAG "\n $N  ˵ ������ �� �� ʼ������\n\n" NOR,me);
  }
else {
        sscanf(who,"%s %s",husband,wife);
       if((!husband)||(!wife))
                return notify_fail("˭Ҫ���н�����ѽ��\n");
        if(!objectp(obj1 = present(husband, environment(me))))
                return notify_fail("����û��"+husband+"��\n");
        if(!objectp(obj2 = present(wife, environment(me))))
                return notify_fail("����û��"+wife+"��\n");
        if( obj1->query("gender") == obj2->query("gender") )
      return notify_fail("��û����ɣ�ϲ����ͬ����!?\n");
  return  message_vision(
MAG "\n $N ˵ ���� �� �� �� ʼ �� �ã�\n\n" NOR,me);

      }
}
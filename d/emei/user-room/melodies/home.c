// Room: home.c
#include "ansi.h"

inherit ROOM;
string short;
string long;

void create()
{
short=read_file(__DIR__"short.txt");
long =read_file(__DIR__"long.txt");
set("wiz_only",1);
            set("short",short);
set("long",long);

//        set("no_die", 1);

        set("exits", ([
              "west":  "/d/emei/sroad1",
                "ct" : "/d/city/guangchang",
        ]));
        setup();
}

void init()
{
object me,ob;
        me=this_player();
     if( (me->query("id")=="melodies"))
        {
        write(WHT"\n��ӭ���˻ؼң�\n"NOR);
                if( (me->query("id")=="xuer")&&
					present("melodies",environment(me)) )
                        {
                        if(!(ob=find_player("melodies")) )
                                return;
                        else
                                {
                                ob->command("kiss xuer");
                                ob->command("ce ��ӭѩ���ؼ�");
                                }
                        }
        } else
        {
        write(HIR"��ӭ"+me->query("name")+"��ѩ������ѿ���ļ�������\n"NOR);
        if(!present("melodies",environment(me))&&
                          (ob=find_player("melodies")) )
                {
            tell_object(ob, query("short") + "�����㣺�������ˣ���" +
                                                  me->query("short")+
                                               "("+me->query("id")+")\n");
                write("��ѿ�������й䣬һ���������ģ�����������\n");
                if(present("xuer",environment(me)) )
                        {
                        message_vision(
           "\n��ѿ����$N���˸��绰������$N�����ú��д�����Ӵ...\n",
                                                  find_player("xuer"));
                        }
                }
        else if(!find_player("melodies"))
                {
                write("��ѿ�����ڼң�����㡣\n");
                }


        }
}

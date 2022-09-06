// Room: /dream/damen.c
// HEM 1998/10/14

#include <ansi.h>
#define SHIP_TO __DIR__"fufeng"
inherit ROOM;

void check_trigger();
void on_board();
void arrive();
void close_passage();
int do_yell(string arg);
void reset();

void create()
{
        set("short", HIW "�Ƽұ�" NOR);
        set("long", 
    "���˻�����̧ͷһ������Ȼ����"+ HIY"���Ƽұ���"NOR + "�������֡����Ѿ����������ض������Ժ�\n"+
"�����Ժյ����š��ߴ�������㲻�ɵò����ӣ����ſ�������������׳��ͭʨ�������Ǳ�\n"+
"���پ��Ķ���(distich)��\n"
    );
    set("no_steal", "1");
    set("exits", ([
        "south" : __DIR__"zhaobi",
    ]));
    set("objects", ([
		__DIR__"npc/tang_buping" : 1,
                __DIR__"npc/dizi" : 2,
    ]));
     set("item_desc", ([
		"distich" : HIY "\n��			һ\n" 
                                "\n��			ǻ\n"		
                                "\n��			��\n"
				"\n��			Ѫ\n"
				"\n��			��\n"
				"\nǧ			��\n"
				"\n��			��\n"
				"\n��			��\n"
				"\n��			��\n" NOR,  
    ]));

    set("outdoors", "tangmen");
    setup();
    
}
void init()
{
    add_action("do_yell", "yell");
}

void check_trigger()
{
    object room;

    if(!query("exits/enter") ) {
        if( !(room = find_object(__DIR__"huafang")) )
            room = load_object(__DIR__"huafang");
        if( room = find_object(__DIR__"huafang") ) {
            if((int)room->query("yell_trigger")==0 ) {
                room->set("yell_trigger", 1);
                set("exits/enter", __DIR__"huafang");
                room->set("exits/out", __FILE__);
                message("vision", "һ������������ʻ�˹��������⽫һ��̤��"
                    "����ϵ̰����Ա�˿�\n���¡�\n", this_object() );
                message("vision", "���⽫һ��̤�Ű���ϵ̰����γ�һ������"
                    "�Ľ��ݡ�\n", room);
                remove_call_out("on_board");
                call_out("on_board", 15);
            }
            else
                message("vision", "ֻ���ý��������������������"
                    "�����æ���š�����\n",this_object() );
        }
        else
            message("vision", "ERROR: boat not found\n", this_object() );
    }
    else 
        message("vision", "��������������һЦ���������أ����ϴ��ɡ�\n",
            this_object() );
}


void on_board()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "�����̤�Ű��������������һ�㣬���������ʻȥ��\n",
        this_object() );

    if( room = find_object(__DIR__"huafang") )
    {
        room->delete("exits/out");
        message("vision", "�����̤�Ű���������˵��һ��������ඡ���"
            "���һ�㣬������\n����ʻȥ��\n", room );
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 20);
}

void arrive()
{
    object room;
    if( room = find_object(__DIR__"huafang") )
    {
        room->set("exits/out", __DIR__"fufeng");
        message("vision", "����˵�����������ϰ��ɡ����漴��һ��̤�Ű�"
            "���ϵ̰���\n",room );
    }
    remove_call_out("close_passage");
    call_out("close_passage", 10);
}

void close_passage()
{
        object room, *ob;
        int i;

        if( room = find_object(__DIR__"huafang") ) {
                room->delete("exits/out");

                tell_room(room, "��������˵���������´��ɣ���ҲҪ��ȥ�ˡ���\n", ({}));
                ob = all_inventory(room);
                for(i = 0; i < sizeof(ob); i++) {
                        if (userp(ob[i])) {
                                if (!living(ob[i])) tell_room(room, "�����$Ņ���˴���\n", ob[i]);
                                else tell_room(room, "��������Ļ����ԹԵ����˴���\n", ob[i]);
                                ob[i]->move(SHIP_TO);
                                if (!living(ob[i])) tell_room(SHIP_TO, ob[i]->name() + "��̧���˴���\n", ({ob[i]}));
                                else tell_room(SHIP_TO, ob[i]->name() + "�����˴���\n", ({ob[i]}));
                        }
                }
                message("vision", "�����̤�Ű����������ѱ���ʻ���ġ�\n", room);
                room->delete("yell_trigger"); 
        }
}
int do_yell(string arg)
{
    string dir;

    if( !arg || arg=="" ) return 0;

    if( arg=="boat" ) arg = "����";
    if( (int)this_player()->query("neili") < 300 )
        message_vision("$Nʹ�����̵���������һ������" + arg + "��\n",
            this_player());
    else if( (int)this_player()->query("neili") > 600 )
        message_vision("$N���˿�����һ����" + arg + "������������ƽ�͵�ԶԶ��"
            "�˳�ȥ��\n", this_player());
    else
        message_vision("$N������������Хһ������" + arg + "����\n",
            this_player());
    if( arg=="����")
    {
        check_trigger();
        return 1;
    }
    else
        message_vision("������ԶԶ����һ���������" + arg +
            "��������\n", this_player());
    return 1;
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"huafang") )
        room->delete("yell_trigger"); 
}
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "����") && dir == "south" &&
                objectp(present("tang buping", environment(me))))
           return notify_fail("�Ʋ�ƽ�ȵ����㲻�����ŵ��ӣ��������ڡ�\n");
                
        return ::valid_leave(me, dir);
}

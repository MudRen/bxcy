// shishi2.c
// by shilling 97.2
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
����һ��ʯͷ���ɵķ��䣬��Ϊ�þ�û����������ɢ����һЩ�����ŵ�
��ζ�������е������Կ�����˿�ͳ漣�������и�ʯ�š�
LONG
        );
       set("exits", ([
               "north" : __DIR__"shiji3",
               "west" : __DIR__"shiji2",
       ]));
       create_door("north", "ʯ��", "south", DOOR_CLOSED);
       setup();
    replace_program(ROOM);
}
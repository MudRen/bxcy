#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{ 
       set("short", RED"���Ҷ�"NOR);
	set("long", RED @LONG
    �����ҽ�����ɢ�������������˴�����������һЩǰ��
δ���ľ޴������������߶��š� 
LONG NOR);
    
	set("exits", ([
		"east" : __DIR__"dong4",
		"west" : __DIR__"dong46",
                	]));
       set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 1,
             __DIR__"npc/lev"+(random(9)+1) : 1,
              "/clone/box/gbox" : random(3),
                ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
// fanchuan.c 樊川 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "樊川");
	set("long", @LONG
这里已是终南山的所在，汉初开国大将军樊哙曾邑于此，因而得名。
沿途冈峦回绕，松柏森映，水田蔬圃连绵其间，宛然有江南的景色。大道
二边都是庄稼地。往西有一条上岗小路。
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"westup" : __DIR__"sgroad1",
          ]));
	setup();
	replace_program(ROOM);
}




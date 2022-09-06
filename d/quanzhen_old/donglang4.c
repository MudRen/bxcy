// donglang4.c 东厢走廊
// by kyd

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "东厢走廊");
	set("long", @LONG
你走在一条走廊上，人来人往很热闹。房顶一侧支在南面的三皇殿上，
另一侧则与西北边雷祖殿的屋顶相连。走廊二边的墙上刻着的是二十四孝
的图形，每一幅图案都有一个生动的故事。往北是雷祖殿，往南是三皇殿。
LONG
	);

	set("exits", ([
		"south" : __DIR__"sanhuangdian",
		"northwest" : __DIR__"leizudian",
	]));
	
	setup();
       replace_program(ROOM);

}



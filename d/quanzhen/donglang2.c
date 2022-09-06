// donglang2.c 东厢走廊

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "东厢走廊");
	set("long", @LONG
你走在一条长廊上，人来人往很热闹。房顶一侧支在北面的三皇殿上，
另一侧则与西南边灵官殿的屋顶相连。走廊二边的墙上刻着的是二十四孝
的图形，每一幅图案都有一个生动的故事。往南是灵官殿，往北是三官殿。
LONG
	);

	set("exits", ([
             "southwest" : __DIR__"lingguandian",
		"north" : __DIR__"sanhuangdian",
	]));
				
	setup();
       replace_program(ROOM);

}


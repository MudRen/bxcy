// Room: /u/mei/zhaoze/lczb.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "澜沧江畔");
	set("long", @LONG
下山后走了一段路，只见前面怒涛汹涌，水流湍急，竟是一条大江。江
岸山石壁立，嶙峋巍峨，看这情势，已是到了澜沧江畔。江岸尽是山石，小
路也没一条，七高八低的走出七八里地，才见到一株野生桃树，树上结实累
累。
LONG
);
	set("outdoors", "lczb");
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"pubu",
  "south" : __DIR__"lczb1",
]));

	setup();
	replace_program(ROOM);
}

// Room: /u/wyz/jingzhou/room26.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "空房间");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"room1",
]));

	setup();
	replace_program(ROOM);
}

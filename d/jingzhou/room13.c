// Room: /u/wyz/jingzhou/room13.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "城墙");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room14",
  "north" : __DIR__"room12",
]));

	setup();
	replace_program(ROOM);
}

// Room: /u/wyz/jingzhou/room25.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "城墙");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"room24",
  "north" : __DIR__"room5",
  "down" : __DIR__"room1",
]));

	setup();
	replace_program(ROOM);
}

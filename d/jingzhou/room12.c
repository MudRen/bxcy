// Room: /u/wyz/jingzhou/room12.c
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
  "south" : __DIR__"room13",
  "east" : __DIR__"room11",
]));

	setup();
	replace_program(ROOM);
}

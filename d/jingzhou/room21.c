// Room: /u/wyz/jingzhou/room21.c
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
  "east" : __DIR__"room22",
  "west" : __DIR__"room20",
]));

	setup();
	replace_program(ROOM);
}

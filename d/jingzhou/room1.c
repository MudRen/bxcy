// Room: /u/wyz/jingzhou/room1.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "东城门");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room26",
  "up" : __DIR__"room5",
]));

	setup();
	replace_program(ROOM);
}

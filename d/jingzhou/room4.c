// Room: /u/wyz/jingzhou/room4.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "北城门");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"room10",
]));

	setup();
	replace_program(ROOM);
}

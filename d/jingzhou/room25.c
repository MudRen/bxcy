// Room: /u/wyz/jingzhou/room25.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "��ǽ");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
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

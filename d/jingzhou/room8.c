// Room: /u/wyz/jingzhou/room8.c
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
  "east" : __DIR__"room7",
  "west" : __DIR__"room10",
  "down" : __DIR__"room4",
]));

	setup();
	replace_program(ROOM);
}

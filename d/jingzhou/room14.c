// Room: /u/wyz/jingzhou/room14.c
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
  "south" : __DIR__"room15",
  "north" : __DIR__"room13",
  "down" : __DIR__"room3",
]));

	setup();
	replace_program(ROOM);
}

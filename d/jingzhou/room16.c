// Room: /u/wyz/jingzhou/room16.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "��ǽ");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room17",
  "north" : __DIR__"room15",
]));

	setup();
	replace_program(ROOM);
}

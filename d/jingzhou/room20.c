// Room: /u/wyz/jingzhou/room20.c
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
  "east" : __DIR__"room21",
  "west" : __DIR__"room19",
  "down" : __DIR__"room2",
]));

	setup();
	replace_program(ROOM);
}

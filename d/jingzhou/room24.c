// Room: /u/wyz/jingzhou/room24.c
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
  "south" : __DIR__"room23",
  "north" : __DIR__"room25",
]));

	setup();
	replace_program(ROOM);
}

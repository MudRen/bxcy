// Room: /u/wyz/jingzhou/room23.c
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
  "north" : __DIR__"room24",
  "west" : __DIR__"room22",
]));

	setup();
	replace_program(ROOM);
}

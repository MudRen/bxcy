// Room: /u/wyz/jingzhou/room4.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"room10",
]));

	setup();
	replace_program(ROOM);
}

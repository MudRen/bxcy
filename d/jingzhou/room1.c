// Room: /u/wyz/jingzhou/room1.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room26",
  "up" : __DIR__"room5",
]));

	setup();
	replace_program(ROOM);
}

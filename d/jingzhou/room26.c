// Room: /u/wyz/jingzhou/room26.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "�շ���");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"room1",
]));

	setup();
	replace_program(ROOM);
}

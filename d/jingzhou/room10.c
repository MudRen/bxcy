// Room: /u/wyz/jingzhou/room10.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
   set("short","����¥");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room8",
  "west" : __DIR__"room11",
]));

	setup();
	replace_program(ROOM);
}

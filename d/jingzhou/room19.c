// Room: /u/wyz/jingzhou/room19.c
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
  "east" : __DIR__"room20",
  "west" : __DIR__"room18",
]));

	setup();
	replace_program(ROOM);
}

// Room: /u/cass/hg/ningshougong.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "宁寿宫");
	set("long", @LONG
只见墙壁上、桌椅上，都是刀剑皮鞭之类的兵器，便如是个武人的居室，
哪里像是金枝玉叶的公主寝宫。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"huangjidian",
]));

	setup();
	replace_program(ROOM);
}

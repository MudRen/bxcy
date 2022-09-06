// Room: /d/quanzhen/mengjin/hulao.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "虎牢关");
	set("long", @LONG
这里本来是自古有名的险关，关口位于两座高山之间的峡谷中，
但由于年久失修，城墙已变得破烂不堪，朝廷也不再派兵驻守这里。
周围的百姓全都搬走了，只剩下一片残砖烂瓦和风的叹息。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shanlu",
  "east" : __DIR__"guandao4",
]));
	set("outdoors", "mengjin");

	setup();
	replace_program(ROOM);
}

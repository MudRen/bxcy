// Room: /u/cass/hg/zhonglou.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "钟楼");
	set("long", @LONG
一座直立耸起、灰墙绿瓦的阁楼。楼上有一口特大铜钟。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wumen",
]));

	setup();
	replace_program(ROOM);
}

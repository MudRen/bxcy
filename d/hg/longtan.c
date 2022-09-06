// Room: /u/cass/hg/longtan.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "龙潭");
	set("long", @LONG
一股晶莹的泉水从龙头中汩汩涌出，沿南北两侧石槽缓缓流出，水随山
转，潺潺有声，宛如琴音。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"quqiao",
  "west" : __DIR__"pubu",
]));

	setup();
	replace_program(ROOM);
}

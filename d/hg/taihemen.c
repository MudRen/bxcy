// Room: /u/cass/hg/taihemen.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "太和门广场");
	set("long", @LONG
映入眼帘的是一个广宽的广场，广场北端有座宏大壮美的三层露台，
台上安放着铜炉、门海、青铜制的仙鹤、龙头龟，以及古代的计时器日
晷、量器嘉量。站在这里，你可以看到不远处，有三座大殿建筑在用汉
白玉砌成的三层平台之上，每层都围有汉白玉石栏杆。
LONG
);
	set("no_new_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"jinshuiqiao",
  "north" : __DIR__"taihedian",
  "northwest" : __DIR__"wuyingdian",
]));

	setup();
	replace_program(ROOM);
}

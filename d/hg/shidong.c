// Room: /u/cass/hg/shidong.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "石洞");
	set("long", @LONG
进入石洞，只见佳木茏葱，奇花闪灼，一带清充，从花木深处曲折泻于
石隙之下。再行得数步，但见平坦宽豁，两边飞流插空，雕萝绣槛，皆隐于
山坳树杪之间，俯而视之，则清溪泻雪，石磴穿云，白石为栏，环抱池沿。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"jiashan",
  "southeast" : __DIR__"pubu",
]));

	setup();
	replace_program(ROOM);
}

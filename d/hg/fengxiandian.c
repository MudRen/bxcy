// Room: /u/cass/hg/fengxiandian.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "奉先殿");
	set("long", @LONG
大殿为重檐庑殿顶，中脊两端有两个巨型琉璃螭吻，特别引人注目。
殿内豁敞明亮，从内柱、梁枋到平基，全部金碧彩绘，给人以富丽、典
雅的感觉。
LONG
);
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"taihemen",
  "west" : __DIR__"qianqingmen",
  "northeast" : __DIR__"huangjidian",
]));

	setup();
	replace_program(ROOM);
}

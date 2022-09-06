// Room: /u/cass/hg/jiulongbi.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "九龙壁");
	set("long", @LONG
全壁以五色琉璃砌成，双面有龙，各有九条，戏珠于波涛骇浪之中，
姿态各异，栩栩如生。此上，正脊两面、垂脊两侧及盖筒瓦、龙砖上还
有龙。九龙壁东端山面嵌有海水、流云、日出图案；西端山面嵌有海水、
流云、明月图案，别具特色。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"huangjidian",
]));

	setup();
	replace_program(ROOM);
}

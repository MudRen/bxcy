// Room: /u/cass/hg/wuyingdian.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "武英殿");
	set("long", @LONG
殿内梁枋、斗拱及梁架底面上，保留着飞天、荷花、牡丹等彩绘数十
幅，这些彩绘不仅笔法细腻，而且形象生动；殿内柱础为石造，其四周雕
以牡丹、莲花等图案。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"taihemen",
]));

	setup();
	replace_program(ROOM);
}

// Room: /u/cass/hg/hualang.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "长廊");
	set("long", @LONG
长廊的每根栋梁上都绘有彩画，彩画取材于历史故事、神话传说、戏剧
曲艺等，还有山水、花鸟、虫鱼等写意画，内容不一，形态各异，栩栩如生，
故有“画廊”之称。
LONG
);

	setup();
	replace_program(ROOM);
}

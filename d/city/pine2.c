// Room: /d/city/pine2.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "大榕树顶");
	set("long", @LONG
哇....你终于爬上这株榕树的树顶了，一阵阵凉风从四面八方吹来，使你
觉得心旷神怡，虽然你的经验告诉你在这种地方往下看是十分不智的，但是你
还是忍不住看了一眼，这里离地面至少也有十五、六丈高，一阵晕眩警告你最
好在跌下去以前离开这个地方。
LONG
);

	setup();
	replace_program(ROOM);
}

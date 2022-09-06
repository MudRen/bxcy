// Room: /d/quanzhen/mengjin/shanlu.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
沿途确是胜景无穷。际此夏日炎炎之际，翠树争荣、野花吐艳、
景色幽丽。侧面是郦山、竹山等大山脉，远处则是华山，地势开始起
伏不平。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"hulao",
  "south" : __DIR__"qiandao",
]));
	set("outdoors", "mengjin");

	setup();
	replace_program(ROOM);
}

// Room: /d/city3/shudao3.c
// This is a room made by roommaker. write by zhm/silversand.

inherit ROOM;

void create()
{
	set("short", "蜀道");
	set("long", @LONG
这是一条较难行的崎岖山道，周围都是峭壁，一不小心就会掉下去，尸骨无存，
前面隐约见到一条大道，可能快到成都城了。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"yidao2",
  "west" : __DIR__"shudao2",
]));

	setup();
	replace_program(ROOM);
}

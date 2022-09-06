// Room: /d/city3/shudao1.c
// This is a room made by roommaker. write by zhm/silversand.

inherit ROOM;

void create()
{
	set("short", "蜀道");
	set("long", @LONG
这是一条较难行的崎岖山道，周围都是峭壁，一不小心就会掉下去，尸骨无存，
难怪俗话说“蜀道之难，难于上青天”，看来你已经来到大理和天府之国的交界之
处了。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"shudao2",
  "southwest" : "/d/heimuya/zhaoze/room16",
]));

	setup();
	replace_program(ROOM);
}

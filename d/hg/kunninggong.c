// Room: /u/cass/hg/kunninggong.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "坤宁宫");
	set("long", @LONG
宫内花斑石墁地，方石板上都有紫色花纹，光彩夺目，如满堂宝石，熠
熠生辉。更妙的是每当黄昏时，晃动门窗，光线若明若暗，像无数条春蚕和
紫色绒球，在黄色地板上滚动。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"jiaotaidian",
  "north" : __DIR__"yuhuayuan",
]));

	setup();
	replace_program(ROOM);
}

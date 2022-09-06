// Room: /d/quanzhen/nanjie1.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "南街");
	set("long", @LONG
这里是荆州的南街，说是街，不过是一条小胡同而已。路上一个
人也没有。街的南端有一小拱门，透过拱门，可见滚滚的江流。
LONG
);
	set("outdoors", "quanzhen");
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"jiangbmt",
  "north" : __DIR__"nanjie",
]));

	setup();
	replace_program(ROOM);
}

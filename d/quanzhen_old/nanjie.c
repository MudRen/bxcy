// Room: /d/quanzhen/nanjie.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "南街");
	set("long", @LONG
这里是荆州的南街，说是街，不过是一条小胡同而已。路上一个
人也没有。街的南面有一扇小门。从这里往北，就是武功镇的中心了。
LONG
);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"nanjie1",
  "southeast" : __DIR__"fu-cemen",
  "north" : __DIR__"zhongxin",
]));
	set("outdoors", "quanzhen");

	setup();
	replace_program(ROOM);
}

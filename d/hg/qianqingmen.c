// Room: /u/cass/hg/qianqingmen.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "乾清门");
	set("long", @LONG
乾清门是内廷的正门，皇帝有时在此听政，称“御门听政”，门内就
是后三宫了。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"yangxindian",
  "east" : __DIR__"fengxiandian",
  "southeast" : __DIR__"guangchang",
  "north" : __DIR__"qianqinggong",
]));

	setup();
	replace_program(ROOM);
}

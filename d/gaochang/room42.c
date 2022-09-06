// Room: /u/mei/room42.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "小溪");
	set("long", @LONG
冰块闪耀之中，忽见夹杂有花瓣飘流，溪水芳香，当是上游有花之故，沿溪
水向上游行去。渐行溪流渐大。沙漠中的河流大都上游水大，到下游时水流逐渐
被沙漠吸干，终于消失。但见溪旁树木也渐渐多了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room43",
  "south" : __DIR__"room41",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room42");

	setup();
	replace_program(ROOM);
}

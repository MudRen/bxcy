// Room: /u/mei/room55.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "昆仑山");
	set("long", @LONG
这里的灌木更高了些，几乎使你分不清前方的道路。一不小心就被树枝挂到
了手脚，往前走又不知通往哪里，你不禁产生了退缩之心。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"room56",
  "northdown" : __DIR__"room54",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room55");

	setup();
	replace_program(ROOM);
}

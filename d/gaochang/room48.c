// Room: /u/mei/room48.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "丛林");
	set("long", @LONG
这是往西的一条道路，曲折地通向一坐阴森黝暗的丛林，道路崎岖坎坷，
林中随风吹出阵阵阴湿的臭气。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room49",
  "east" : __DIR__"room47",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room48");

	setup();
	replace_program(ROOM);
}

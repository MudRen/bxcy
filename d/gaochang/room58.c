// Room: /u/mei/room58.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "昆仑山");
	set("long", @LONG
只见已处身在一座雪岭的丛林之内。只见一望无际的雪地中留着长长的一行
足印。西域苦寒，山岭间积雪未融。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"room59",
  "southdown" : __DIR__"room57",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room58");

	setup();
	replace_program(ROOM);
}

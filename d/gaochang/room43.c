// Room: /u/mei/room43.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "银瀑");
	set("long", @LONG
溪水转弯绕过一块高地，忽然眼前一片银瀑，水声轰轰不绝，匹练有如自天
而降，飞珠溅玉，顿成奇观。在这荒凉的大漠之中突然见此美景，不觉身神俱爽，
好奇心起，想看看瀑布之上更有甚么景色。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room44",
  "south" : __DIR__"room42",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room43");

	setup();
	replace_program(ROOM);
}

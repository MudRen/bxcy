// Room: /u/mei/room17.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "石砾小径");
	set("long", @LONG
此处地势与大漠的其余地方截然不同，遍地黄沙中混着粗大石砾，丘壑处
处，乱岩嶙嶙，山峰虽似触手可及，路竟是十分的崎岖难行。
LONG
	);
	set("no_new_clean_up", 0);
	set("outdoors", "room17");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room15",
  "north" : __DIR__"room18",
]));

	setup();
	replace_program(ROOM);
}

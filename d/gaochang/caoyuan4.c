// Room: /u/mei/caoyuan4.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "戈壁");
	set("long", @LONG
此处地势与大漠的其余地方截然不同，遍地黄沙中混着粗大石砾，丘壑处
处，乱岩嶙嶙，路十分的崎岖难行。
LONG
	);
	set("outdoors", "caoyuan4");
	set("no_new_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"caoyuan5",
  "east" : __DIR__"caoyuan3",
]));

	setup();
	replace_program(ROOM);
}

// Room: /d/city3/wenzai/wuchang.c
// This is a room made by roommaker. write by zhm/silversand.

inherit ROOM;

void create()
{
	set("short", "温家练武场");
	set("long", @LONG
这里是温家后院的一个别院，但四周放着许多练武用的道具，似乎是温家
的练武场，但却没人在练功。
LONG
);
	set("objects", ([ /* sizeof() == 1 */
  "/d/shaolin/obj/mu-ren" : 3,
]));
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"houyuan",
]));

	setup();
	replace_program(ROOM);
}

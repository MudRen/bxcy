// Room: /u/mei/zhaoze/room2.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "小道");
	set("long", @LONG
你走在一条阴暗的林间小道上，两旁是阴森森的树林。一阵阵风吹过
树梢, 发出沙沙的响声, 令你不寒而栗。
LONG
	);
	set("outdoors", "room2");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room3",
  "east" : __DIR__"room1",
]));

	setup();
	replace_program(ROOM);
}

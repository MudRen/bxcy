// Room: /d/huashan/liangong3.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", @LONG
这是一间摆放铜人的地方，华山弟子都在这里练习。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"liangong1",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tong-ren" : 4,
]));
	set("no_new_clean_up", 0);

	setup();
	replace_program(ROOM);
}

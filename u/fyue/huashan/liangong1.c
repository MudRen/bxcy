// Room: /d/huashan/liangong1.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", @LONG
这里是华山弟子们练功的地方，房子里什么也没有。
LONG
);
	set("no_new_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"bingqifang",
  "north" : __DIR__"liangong2",
  "south" : __DIR__"liangong3",
]));

	setup();
	replace_program(ROOM);
}

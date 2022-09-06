inherit ROOM;

void create()
{
	set("short", "大官道");
	set("long", @LONG
这是一条宽阔笔直的官道，不过看起来多年没有修理了。东边是汝州的西门，
往西则直达少室山山脚。
LONG
);
	set("no_clean_up", 0);
	set("outdoors", "changan");
	set("exits", ([ /* sizeof() == 1 */
           "west" : __DIR__"shijie1",
           "east" : __DIR__"ximen",
]));

	setup();
	replace_program(ROOM);
}

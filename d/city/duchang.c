// Room: /city/duchang.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "赌场");
	set("long", @LONG
这里是赌场的大堂，四周的房间里传出来吆五喝六的赌博声。西边是赌「大小」
的房间，北边是赌「骰子」的房间，二楼是拱猪房。
LONG
	);
	set("exits", ([
		"up" : __DIR__"duchang2",
		"east" : __DIR__"nandajie1",
		"west" : __DIR__"duchang3",
               "north" : __DIR__"duchang4",
"south" : __DIR__"bobing",	
	]));
	setup();
}
int valid_leave(object me, string dir)
{
        if (dir != "east" && this_player()->query("age")<18)
                return notify_fail("小毛孩子往这儿瞎凑合什么?!\n");
        return ::valid_leave(me, dir);
}

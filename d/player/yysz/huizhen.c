
inherit ROOM;

void create()
{
        set("short", "汇珍园");
        set("long",@LONG
这是御云山装中最大的花园，遍植江南的奇花异草，香气浓郁。一群
蜜蜂在花间翩跹飞舞，你不由的痴了，有点乐而忘返。
LONG );
         set("outdoors", "yysz");
        set("exits", ([
            "west"  : __DIR__"changlang",
        ]));
        set("objects",([
// __DIR__"npc/mifeng" : 3,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


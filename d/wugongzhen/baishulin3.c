// baishulin3.c 柏树林
// By csy 1999.03

inherit ROOM;

void create()
{
        set("short", "柏树林");
        set("long", @LONG
你走进了柏树林的深处，脚下踩着厚厚的落叶，松松软软。这里的光
线非常阴暗，你几乎什么都看不清了。突然一只松鼠从你眼前的树枝上猛
地跳了过去，吓了你一跳。
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "northup" : __DIR__"cuipingfeng",
                "east" : __DIR__"baishulin4",
                "southdown" : __DIR__"baishulin1",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


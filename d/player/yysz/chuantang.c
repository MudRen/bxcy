
inherit ROOM;

void create()
{
        set("short", "弄堂");
        set("long",@LONG
不知是什么能工巧匠设计了这条弄堂，九曲回折，雕梁画栋，真可
谓巧夺天工。再望南就是后院了，向北则是一座大厅堂。
LONG );
        set("exits", ([
            "south" : __DIR__"lixiang",
            "north" : __DIR__"cuixia",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}



inherit ROOM;

void create()
{
        set("short", "断魂院");
        set("long",@LONG
御云山庄的后院也与众不同，圆形院门上刻有断魂院三字，院中雪白
的梨花开满了枝头，西侧就是接待贵宾的龙凤厅了，东侧有一条精美的
长廊。看来这里只是名字吓人而已。
LONG );
        set("outdoors", "yysz");
        set("exits", ([
            "north" : __DIR__"chuantang",
            "west"  : __DIR__"longfeng",
            "east"  : __DIR__"changlang"
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


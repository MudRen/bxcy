//ROOM: /d/yanziwu/shuwu.c

inherit ROOM;

void create()
{
        set("short", "广博书屋");
        set("long",@LONG
屋中一架架紫竹搭成的书架倚墙而立，书架上摆满了经史典籍。屋
子正中央是一张书桌，桌上琴棋俱备，笔墨纸砚一应俱全，墙上挂着一
幅条幅(tiaofu)。大名鼎鼎的慕容公子常在这里读书写字。
LONG );
        set("exits", ([
            "east" : __DIR__"lanyue",
"north": __DIR__"canheje",
            "south": __DIR__"shangyu",
        ]));

        set("item_desc",([
                          "tiaofu" : "
               解放思想，
               实事求是。
                        \n\n\n ",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


// Room: /u/mei/room24.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "石壁小径");
        set("long", @LONG
道路骤陡，一线天光从石壁之间照射下来，只觉阴气森森，寒意逼人。
路旁又现一堆白骨，骸骨中光亮闪耀，竟是许多宝石珠玉。
LONG
        );
    if (random(10)>7)
        set("objects", ([ 
        __DIR__"obj/zhu" : 1,
        __DIR__"obj/zuanshi" : 1,
        __DIR__"obj/feicui" : 1,
        __DIR__"obj/skeleton" : 1,
]));
        set("no_new_clean_up", 0);
        set("outdoors", "room24");
        set("exits", ([ 
  "south" : __DIR__"room23",
  "westup" : __DIR__"room25",
]));

        setup();
        replace_program(ROOM);
}

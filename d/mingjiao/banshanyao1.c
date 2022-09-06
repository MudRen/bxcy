// Room: banshanyao1.c

inherit ROOM;

void create()
{
        set("short", "半山腰");
        set("long", @LONG
你爬上半山腰，望着对面的山。这边的山柔静阴郁，对面
的山坡金色的阳光晒得一片亮晶。真象仙境一样，有什麽喜乐
的事，如升平的音乐，在树梢与树梢间荡跌着，回乐着.....!
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"banshanting",
  "east" : __DIR__"shanpo1",
  "northwest" : __DIR__"xiaolu-1",
]));
        set("no_clean_up", 0);
        set("outdoors", "none");

        setup();
        replace_program(ROOM);
}


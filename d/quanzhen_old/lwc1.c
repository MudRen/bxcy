// Room: lwc.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "练武场");
        set("long", @LONG
这里是全真教第子的练武场，广场的四周设置了各式各样的练武器械，
很多全真第子正在埋头苦练。由于一年一度的较武大会关系到各自的前
途，众第子都日夜勤练不息。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"guangchang",
 ]));
        set("no_clean_up", 0);
        set("outdoors", "xxx");

        set("objects", ([
                 "/d/shaolin/npc/mu-ren" : 3,
   ]));
               
        setup();
        replace_program(ROOM);
}


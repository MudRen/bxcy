// gmmishi1.c By csy 98/12
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{ 
       set("short",HIB"石室"NOR);
       set("long", @LONG
古墓中阴沉的石室，只听见远远传来你脚步的回音，空荡荡的感觉使你心
中只有恐惧，甚至忘记孤独。你不知身处何地，四周如此漆黑一片，只能靠摸
索前行。
LONG
     );
    
        set("exits", ([
                "east" : __DIR__"gmls",
                "west" : __DIR__"ss4",
        ]));

        setup();
}

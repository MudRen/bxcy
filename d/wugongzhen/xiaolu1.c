// Room: /u/xdd/gumu/xiaolu1
// Modify By csy 98/12
inherit ROOM;
#include <ansi.h>

void create()
{
     set("short",HIG"乡间小道"NOR);
     set("long", @LONG
终南山下的小道，由于全真掌教王重阳技镇华山，全真派的声势如日中天，
招来一派生气，不少百姓诚心向道，也不乏武林人士奔走其间。
LONG        );

     set("outdoors","古墓");

     set("exits", ([
         "northup" : __DIR__"xiaolu2",
         "southdown" : __DIR__"shanjiao",
     ]));

     setup();
}


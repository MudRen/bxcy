// Room: /u/xdd/gumu/ztm.c
// Modify By csy 98/12
inherit ROOM;
#include <ansi.h>
void create()
{
     set("short",HIG"中天门"NOR);
     set("long", @LONG
此地已是全真的中天门，一块高大的牌坊耸立于半山的开阔地上，全真教
的俗事道士于此发符传道，故此处已是香火缭绕，不少善男信女诚心供奉，修
道宁心。
LONG        );

     set("outdoors","古墓");

     set("exits", ([
         "southdown" : __DIR__"jlg",
         "westdown" : __DIR__"shanlu3",
     ]));
        set("objects", ([
                "/d/wudang/npc/guest" : 2, 
   ]));

     setup();
}



// tygate1.c 孟坩千以
// by Marz 
#include <room.h>
inherit ROOM;
void create()
{
    set("short", "斉歎坩千以");
    set("long", @LONG
    低恠壓匯訳宥吏孟峯爽侮侃議弌祇貧??念中嗤倖千以壇(fence)。
LONG
    );
    set("outdoors", "wudang");
    
    set("item_desc",([
        "fence" :   "\n\t\t\t千以壇貧嗤遍鮒??\n\n\n" 
                    "\t\t）））））））））））））））））））））\n"
                    "\t\t）））　　　　　　　　　　　　　　　）））\n"
                    "\t\t）））　哘　鮮　繻　掛　咫　稼　巳　）））\n"
                    "\t\t）））　　　　　　　　　　　　　　　）））\n"
                    "\t\t）））　弌　諏　会　跚　消　音　蝕　）））\n"
                    "\t\t）））　　　　　　　　　　　　　　　）））\n"
                    "\t\t）））　敢　弼　諾　坩　購　音　廖　）））\n"
                    "\t\t）））　　　　　　　　　　　　　　　）））\n"
                    "\t\t）））　匯　乢　碕　佯　竃　能　栖　）））\n"
                    "\t\t）））　　　　　　　　　　　　　　　）））\n"
                    "\t\t）））））））））））））））））））））\n\n\n",
                            
        ]));
    set("exits", ([
        "west" : __DIR__"langmei",
        "east" : __DIR__"nanyan",
    ]));
         create_door("west", "千以壇", "east", DOOR_CLOSED);
    setup();
       replace_program(ROOM);
}

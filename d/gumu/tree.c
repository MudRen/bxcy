 // Modify by csy 99/01/21
#include <ansi.h> 
inherit ROOM;

void create()
{
     set("short", HIY"����"NOR);
     set("long", @LONG 

���������ϣ���ͻȻ������Ҷ����Щ�������ۡ�����������!!!
LONG
);
     set("outdoors","��Ĺ");

     set("exits", ([ 
     "down" : __DIR__"xuanya",
         ]));
/*        set("objects", ([
                "/u/brave/obj/diao" : 1, 
   ]));
*/
             setup();
        replace_program(ROOM);       

} 


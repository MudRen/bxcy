//LUCAS 2000-6-18
// Room: liao.c

inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short","居室");
        set("long",@LONG 
这是廖自励的房间。四位长老中，以他最为生性多智，有人
说若不是当年先师仙去时，他不在凌霄城内，而等他回来之时，
大局已定，那这掌门之位必为他囊中之物。这房间内摆满了书，
从《孙子兵法》到《史记》，尽皆是权谋争斗之书。
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "south"  : __DIR__"zoulang3", 
        ]));
        set("objects", ([  
                __DIR__"npc/liao" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}


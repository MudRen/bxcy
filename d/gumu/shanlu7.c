// shanlu7.c By csy 98/12

inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", YEL"山路"NOR);
    set("long", @LONG
此处是一条崎岖山路，你睁大了眼四下眺望，惟见云生谷底，雾迷峰巅，
空山寂寂，微闻鸟语，天地茫茫，就只你一人而已。渐行渐低，走进了一个山
谷，周围都是树丛。西北方向远远地好象有一座高陡的峭壁。
LONG
        );

    set("exits", ([ 
                "northwest"  : __DIR__"shanlu8",
                "southeast"  : __DIR__"shandong",       
    ]));

    set("outdoors", "古墓");

    setup();
}

void init()
{
       object me, room;
       me = this_player(); 
       if (random((int)me->query("kar")) >= 15 ) {  
       if(!( room = find_object(__DIR__"shushang")))
       room = load_object(__DIR__"shushang");
       if(!(present("du mang", room))) 
       return;
       message_vision(HIR"突然闻到一股腥臭之气，大树上倒悬下一条碗口粗细的三角头巨蟒，把$N卷走了。\n\n"NOR, me);
       me->move(__DIR__"shushang");                                                            
       me->start_busy(3);       
    }      

}


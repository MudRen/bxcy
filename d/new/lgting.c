//room: lgting.c
inherit ROOM;
void create()
{
  set("short","练功大厅");
  set("long",@LONG
这里是江湖侠客们经常聚集切磋的地方，摆设简单。江湖上诸多前辈高手都曾经在这磨练过。
LONG
     );
  set("no_sleep_room",1);
set("no_fight", 1);
set("exits",([
      "east" : __DIR__"dongdajie1",
      "west" : __DIR__"xidajie1",
      "north" : __DIR__"beidajie1",
      "south" : __DIR__"nandajie1",
     ]));
set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/wenqianer" : 1,      	
]));


 setup();
 replace_program(ROOM);
}

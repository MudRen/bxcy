// Room: /u/xdd/gumu/gmqianliu2.c
// Modify By csy 98/12
#include <ansi.h>;
inherit ROOM;

void create()
{
     set("short", HIR"潜流"NOR);
     set("long", @LONG
你没在水中，只觉水势甚急，冲得你无法立足。你气闷异常，只得屏气摸
索潜行，当真是进退维谷。
LONG    
    );

     set("exits", ([
         "westup" : __DIR__"gmanhe2",
         "east" : __DIR__"gmql1",
     ]));    

     setup();
}

void init()
{
     object me;
     me = this_player();
add_action("do_qian","qian");	
     me->receive_damage("qi", 50 );
     me->receive_damage("jing", 50 ); 
     message_vision(HIB"$N的真气正在流失，呼吸十分困难。\n"NOR, me);
     if ((int)me->query("qi") < 10 || (int)me->query("jing") < 10) {
     me->set_temp("last_damage_from","在潜流中被淹");
     me->unconcious();
     me->die();
     return ;   
     }    
}

int do_qian(string arg)	
{
object me;	
me=this_player();	
if ( !arg || arg != "down" )	
return notify_fail("你要往哪里潜？\n");	
if ( me->is_busy() || me->is_fighting())	
return notify_fail("你正忙着哪！\n");	
if (arg =="down"){	
if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() <= 50) 	
return notify_fail("由于重力不够，你无法继续下潜!\n");	
message_vision(HIG"$N一个猛栽，潜了下去。\n"NOR, me);	
me->receive_damage("jing", 500);   	
me->receive_damage("qi", 500);   	
me->move(__DIR__"gmql3");	
tell_room(environment(me), me->name() + "从上面潜了下来。\n", ({ me }));	
message_vision (HIB"$N只觉得头晕晕的，身体浸在冰冷的水中，不住的颤抖。\n"NOR,me);	
return 1;	
}
return 1;	
}

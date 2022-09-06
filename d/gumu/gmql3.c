// Room: /u/xdd/gumu/gmqianliu2.c
// Modify By csy 98/12
#include <ansi.h>;
inherit ROOM;

void create()
{
     set("short", HIR"潜流"NOR);
     set("long", @LONG
你没在水中，只觉水势甚急，冲得你无法立足。你气闷异常，只得屏气摸
索潜行，当真是进退维谷。突觉下面似有股强大吸力把你猛往下扯,你不由自主地往下沉去.
LONG    
    );
/*
     set("exits", ([
         "westup" : __DIR__"gmanhe2",
         "east" : __DIR__"gmql1",
     ]));    
*/
     setup();
}

void init()
{
     object me;
     me = this_player();
me->receive_damage("qi", 500 );	
me->receive_damage("jing", 500 ); 	
     message_vision(HIB"$N的真气正在流失，呼吸十分困难。\n"NOR, me);
call_out("down", 5, me);	
     if ((int)me->query("qi") < 10 || (int)me->query("jing") < 10) {
     me->set_temp("last_damage_from","在潜流中被淹");
     me->unconcious();
     me->die();
     return ;   
     }    
}

void down(object me)	
{
tell_object(me, "只觉脚底水流盘旋，一股强大的吸力把你往下拉去...\n");	
me->move(__DIR__"hedi");	
}

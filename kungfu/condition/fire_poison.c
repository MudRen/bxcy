#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
    if( duration < 1 ) return 0;
    if( !living(me) ) {
        message("vision", me->name() + "痛苦地哼了一声。\n", environment(me), me);
    }else {
        tell_object(me, HIR "忽然丹田一股热浪直冲脑门，只觉眼冒金星。\n" NOR );
        message("vision", me->name() + HIY BLINK "的身子突然晃了两晃，满面通"HIR"红。\n" NOR,environment(me), me);
    }
    me->receive_wound("qi",30 + random(10));
    me->receive_wound("jing", 30);
    me->apply_condition("fire_poison", duration - 1);
    if ( (int)me->query_temp("powerup") ) {
        me->delete_temp("apply/attack");
        me->delete_temp("apply/dodge");
        me->delete_temp("powerup");
    }
    me->set_temp("die_for","中火毒");
    me->delete_temp("last_damage_from");
    if( duration < 1 ) return 0;
    return CND_CONTINUE;
}


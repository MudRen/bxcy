#include <ansi.h>

int update_condition(object me, int duration)
{
    me->receive_wound("jing", me->query("jing")/7);
        me->start_busy(random(3));
//    me->receive_wound("kee", 10);
//    me->receive_damage("sen", 10);
    me->receive_damage("qi", me->query("qi")/7);
me->start_busy(5);
        me->apply_condition("qx_snake_poison", duration - 1);
        message_vision(BLU"$N的身体发出诡异色的蓝光，混身经脉疼痛欲裂,扭结成怪异的肉筋.\n"NOR, me);
        tell_object(me, HIR "你中的七修蛇毒发作了！\n" NOR );

        if( duration < 1 ) return 0;
        return 1;
}



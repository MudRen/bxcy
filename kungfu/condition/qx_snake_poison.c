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
        message_vision(BLU"$N�����巢������ɫ�����⣬��������ʹ����,Ť��ɹ�������.\n"NOR, me);
        tell_object(me, HIR "���е������߶������ˣ�\n" NOR );

        if( duration < 1 ) return 0;
        return 1;
}



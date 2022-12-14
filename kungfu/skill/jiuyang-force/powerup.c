// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;
        if ((int)me->query_skill("jiuyang-force", 1) < 150)
                return notify_fail("你的九阳真气修为还不够。\n");
           if( target != me ) 
                return notify_fail("你只能用九阳真气来提升自己的战斗力。\n");
        if( (int)me->query("neili") < 1000  ) 
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") ) 
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("jiuyang-force");
        me->add("neili", -200);
        me->receive_damage("qi", 0);

        message_vision(
        HIR "$N微一凝神，运起九阳真气，全身骨节发出一阵爆豆般的声响, 将全身潜能尽数提起。\n" NOR, me);

        me->add_temp("apply/attack",2*skill/3);
        me->add_temp("apply/dodge", 2*skill/3);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 2*skill/3 :), skill);

        if( me->is_fighting() ) me->start_busy(1);

        return 1;
}

void remove_effect(object me, int amount)
{
   if ( (int)me->query_temp("powerup") ) {
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("powerup");
        tell_object(me, "你的九阳真气运行完毕，将内力收回丹田。\n");}
}


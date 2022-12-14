// 海潮汹涌

#include <ansi.h>
#include <combat.h> 

inherit F_SSERVER;
int perform(object me, object target)
{
        int i, j;
        i = me->query_skill("xuantie-jianfa", 1)/2;
        j = me->query_skill("sword")/2;

        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("「海潮汹涌」只能在战斗中对对手使用。\n");
        if(!me->query_temp("weapon"))
                return notify_fail("你必须使用武器才能使用「海潮汹涌」！\n");   
        if(!( me->query_temp("weapon")->id("xuantie jian")))
                return notify_fail("你必须手持玄铁剑才能使用「海潮汹涌」！\n");
        if( (int)me->query_skill("xuantie-jianfa", 1) < 150 )
                return notify_fail("你的玄铁剑法还不够娴熟，使不出「海潮汹涌」绝技。\n");
        if( (int)me->query_skill("yunu-xinjing", 1) < 150 )
                return notify_fail("你的玉女心经等级还不够，使不出「海潮汹涌」绝技。\n");
        if( (int)me->query_skill("force") < 180 )
                return notify_fail("你的内功等级不够，不能使用「海潮汹涌」。\n");
        if( (int)me->query_str() < 35 )
                return notify_fail("你的膂力还不够强劲，使不出「海潮汹涌」来。\n");
        if ( me->query_skill_mapped("sword") != "xuantie-jianfa"
        || me->query_skill_mapped("parry") != "xuantie-jianfa")
               return notify_fail("你现在无法使用「海潮汹涌」！\n");                                                                                 
        if( (int)me->query("max_neili") < (me->query_skill("force")+j+100) )
                return notify_fail("你现在内力太弱，使不出「海潮汹涌」。\n");      
        if( (int)me->query("neili") < (me->query_skill("force")+j) )
                return notify_fail("你现在真气太弱，使不出「海潮汹涌」。\n");

        message_vision(HIY BBLU"\n$N大吼一声，手持玄铁剑挟巨浪潮涌之势,从轻而响，从响而轻，忽寂然\n
无声，忽轰轰之声，反复七次，向$n席卷而去。\n"NOR,me,target);
        me->add_temp("apply/strength", i);
        me->add_temp("apply/attack", j);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        me->add_temp("apply/strength", -i);
        me->add_temp("apply/attack", -j);

        me->add("neili", -(me->query_skill("force")+j));
        me->add("jingli", -50);
        me->start_busy(3);
        target->start_busy(1);
        return 1;
}


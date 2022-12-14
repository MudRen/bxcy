// zhen.c 

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("九阳真气震敌只能对战斗中的对手使用。\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能使用「震」字诀！\n");         
                
if( (int)me->query_skill("jiuyang-force", 1) < 40 )
                return notify_fail("你的九阳真气不够娴熟，不会使用「震」字诀。\n");
                                
        if( (int)me->query_skill("jiuyang-force", 1) < 60 )
                return notify_fail("你的九阳真气不够高，不能用来反震伤敌。\n");
                        
        if( (int)me->query("neili", 1) < 200 )
                return notify_fail("你现在内力太弱，不能使用「震」字诀。\n");
                        
        msg = CYN "$N默运神功，使出九阳真气「震」字诀，企图以内力震伤$n。\n"NOR;

        if (random(me->query_skill("force")) > target->query_skill("force")/2 )
        {
                me->start_busy(3);
                target->start_busy(random(3));
                
                damage = (int)me->query_skill("jiuyang-force", 1);
                
                damage = damage/2 + random(damage);
                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                me->add("neili", -damage/5);
                
                if( damage < 20 ) msg += HIY"$n受到$N的九阳纯阳内力反震，闷哼一声。\n"NOR;
                else if( damage < 80 ) msg += HIY"结果$n被$N以九阳纯阳内力反震，连退了几步。\n"NOR;
                else if( damage < 100 ) msg += RED"结果$n被$N以九阳纯阳内力一震，胸口有如雷击，几欲裂开！\n"NOR;
                else msg += HIR"结果$N被$n的内力一震，眼前一黑，嘴里吐出几口鲜血！！\n"NOR;                
        } else 
        {
                me->start_busy(1);
                msg += CYN"可是$p看破了$P的企图，并没有上当。\n"NOR;
        }
        message_vision(msg, me, target);

        return 1;
}

// zhen.c 

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("�����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʹ�á����־���\n");         
                
if( (int)me->query_skill("jiuyang-force", 1) < 40 )
                return notify_fail("��ľ�������������죬����ʹ�á����־���\n");
                                
        if( (int)me->query_skill("jiuyang-force", 1) < 60 )
                return notify_fail("��ľ������������ߣ��������������˵С�\n");
                        
        if( (int)me->query("neili", 1) < 200 )
                return notify_fail("����������̫��������ʹ�á����־���\n");
                        
        msg = CYN "$NĬ���񹦣�ʹ���������������־�����ͼ����������$n��\n"NOR;

        if (random(me->query_skill("force")) > target->query_skill("force")/2 )
        {
                me->start_busy(3);
                target->start_busy(random(3));
                
                damage = (int)me->query_skill("jiuyang-force", 1);
                
                damage = damage/2 + random(damage);
                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                me->add("neili", -damage/5);
                
                if( damage < 20 ) msg += HIY"$n�ܵ�$N�ľ����������������ƺ�һ����\n"NOR;
                else if( damage < 80 ) msg += HIY"���$n��$N�Ծ��������������������˼�����\n"NOR;
                else if( damage < 100 ) msg += RED"���$n��$N�Ծ�����������һ���ؿ������׻��������ѿ���\n"NOR;
                else msg += HIR"���$N��$n������һ����ǰһ�ڣ������³�������Ѫ����\n"NOR;                
        } else 
        {
                me->start_busy(1);
                msg += CYN"����$p������$P����ͼ����û���ϵ���\n"NOR;
        }
        message_vision(msg, me, target);

        return 1;
}

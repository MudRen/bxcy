// mie.c  ������

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if ((int)me->query_skill("magic-old", 1) < 50)
                return notify_fail(WHT"��ĹŴ�ħ��������죬��ʹ�����������򡹡�\n"NOR);
        if ((int)me->query("neili")<50)
        {
               return notify_fail(HIC"����������(����)������û�ܽ���������ʹ�꣡\n"NOR);
        }
        msg = RED "$N��������������������.���н���������һ�Ż���.���򽥴�.\n"NOR;
        msg += RED"$N��������,��֪�������Ѷ�׼��$n��$n���������⣬�����Ծ��ֻ��һɲ��\n"NOR;
        msg += RED"$N���һ��  ������!!  ,���еĻ���ֱ��$n��ȥ���������.��\n"NOR;
        if (random(me->query_skill("force"))>target->query_skill("force")/2|| 
           random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                me->start_busy(2);
                target->start_busy(random(3));
                damage = (int)me->query_skill("magic-old", 1);
                damage = damage + random(damage);
                target->receive_damage("qi", damage/5);
                target->receive_wound("qi", damage);
                target->receive_damage("jing", damage);
                target->receive_wound("jing", damage/5);
            	  target->add("neli",-100);
        msg += HIR"$n����û����ܣ�һ���޴����,�˶���\n"NOR;
        msg += HIR"������$n�����ϣ�$nȫ����������!!\n"NOR;
                me->add("neili", -10);
		message_vision(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
                me->start_busy(2);
        msg += HIY"����$p����һЦ��������ת.\n"NOR;
        msg += HIY"������$p��໮�����������ˡ�\n"NOR;
                me->add("neili", -50);
		message_vision(msg, me, target);
        }
	if(!target->is_fighting(me)) target->fight_ob(me);
//	if(userp(target)) target->fight_ob(me);
//	else if( !target->is_killing(me) ) target->kill_ob(me);
        return 1;
}

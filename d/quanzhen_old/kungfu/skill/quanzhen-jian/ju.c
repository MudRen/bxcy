// ju.c ȫ�潣-�����۶�
// By Lgg,1998.9
// modified by wind

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("�����۶�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query_skill("quanzhen-jian", 1) < 60 )
		return notify_fail("���ȫ�潣��������죬����ʹ�������۶���\n");

	if( (int)me->query("neili", 1) < 200 )
		return notify_fail("����������̫��������ʹ�������۶���\n");

	msg = HIC "$N������ϣ�΢΢һЦ�����н�����������Ȧ����$n��ȴ��һ�С������۶�����\n"NOR;

	if( !target->is_killing(me) ) target->kill_ob(me);

	if (random(me->query_skill("force")) > target->query_skill("force")/2 )
	{
		me->start_busy(2);
		
		damage = (int)me->query_skill("quanzhen-jian", 1) + (int)me->query_skill("force",1);
		//(ȫ�潣������+�����ڹ�) 
			
                damage = damage/2 ; //+ random(damage/2) + random(damage/3);
		
		target->receive_damage("qi", damage);
		target->start_busy(4);
                me->add("neili", -150);
		
                msg += HIR"$n��$N�Ľ��лε��۶����ˣ�ֻ���õ��������Ȧ�������Ǹ���һ��֮�£��ѱ����У�\n"NOR;
		
	}
	else 
	{
		me->start_busy(3);
		msg += CYN"����$p������$P����ͼ���Ӷ����б���Ҳ������������Ȧ����$P�Ľ���һһ��ȥ��\n"NOR;
	}
	message_vision(msg, me, target);

	return 1;
}

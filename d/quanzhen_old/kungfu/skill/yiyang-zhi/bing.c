// bing.c һ��ָ -- ��������
// By Lgg,1998.10

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("������ȷ������еı�����\n");		

	if( (int)me->query_skill("yiyang-zhi", 1) < 60 )
		return notify_fail("���һ��ָ���𲻹�������ʹ�û������١�\n");

	if( (int)me->query_skill("xiantian-qigong", 1) < 50 )
		return notify_fail("�������������δ��죬�����������˵С�\n");

	if( (int)me->query("neili", 1) < 150 )
		return notify_fail("����������̫��������ʹ�û������١�\n");

	msg = RED "$N����һ����˫��Ĵָͬʱ���𣬷ֱ���$n�ؿ�������Ĵ�Ѩ��ȥ����һʽ���������١���\n"NOR;

	if( !target->is_killing(me) ) target->kill_ob(me);

	if (random(me->query_skill("force")) > target->query_skill("force")/2 )
	{

		damage = (int)me->query_skill("xiantian-qigong", 1) + (int)me->query_skill("yiyang-zhi",1);
		//(��Ů�ķ�+��Ůȭ����)/2
		damage=damage/2;
		
                damage = damage/2 + random(damage/2) ;
		damage = damage*5/4;
		
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/3);
		target->start_busy(4);
                me->add("neili", -100);
		
		msg += HIM"���$n�����ؿ�������ͬʱһʹ���ѱ����У����ۡ���һ�����һ�����Ѫ��\n"NOR;
		
	}
	else 
	{
		me->start_busy(3);
		msg += CYN"����$p������$P����ͼ�����������ܿ���$P��һ�С�\n"NOR;
	}
	message_vision(msg, me, target);

	return 1;
}
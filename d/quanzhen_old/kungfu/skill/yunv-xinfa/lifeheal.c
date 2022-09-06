// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( !target )
		return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("������ս���У�������\n");

	if( (int)me->query_skill("yunv-xinfa",1)<40)
		return notify_fail("�����Ů�ķ���Ϊ��������������������Ϊ�������ˣ�\n");

	if(target == me)
		return notify_fail("�㲻��Ϊ�Լ����ˣ�\n");

	if( (int)me->query("max_neili") < 200 )
		return notify_fail("���������Ϊ������\n");

	if( (int)me->query("neili") < 150 )
		return notify_fail("�������������\n");

	if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
		return notify_fail( target->name() +
			"�Ѿ����˹��أ����ܲ�����������𵴣�\n");

	message_vision(
		HIY "$N��������Ǳ���ڹ�������������$n���ģ������ؽ���������$n����....\n\n"
		"���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�\n" NOR,
		me, target );

	target->receive_curing("qi", 10 + (int)me->query_skill("force")*2/5 );
	target->add("qi", 10 + (int)me->query_skill("force")*2/5 );
	if( (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));

	me->add("neili", -150);
	me->set("jiali", 0);
        me->start_busy(3);
        target->start_busy(2);
	return 1;
}
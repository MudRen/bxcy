// chan.c �򹷰����������־�

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;
	int time,exp;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�������־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
        || (string)weapon->query("skill_type") != "club")
            return notify_fail("��ʹ�õ��������ԡ�\n");
            
	if (!me->visible(target))    return notify_fail("�㿴����"+target->name()+"��\n");
	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");
		
	if( (int)me->query_skill("dagou-bang",1) < 100 )
		return notify_fail("��Ĵ򹷰���������죬����ʹ�á������־���\n");

	msg = HIG "$Nʹ���򹷰����������־�����ͷ�ڵ������㣬���಻��������$n��С�Ⱥͽ��ס�\n";
	time = (int)me->query_skill("dagou-bang") / 15;
	exp = (int)me->query("combat_exp");
	if(me->query("id")=="gud"){
		time=300;exp=(int)me->query("combat_exp")*3;
	}
	if( random(exp) > (int)target->query("combat_exp")/3 ) {
		msg += HIR " ���$p��$P���ı�����ͣ����æ���ң�\n" NOR;
		target->start_busy(time);
	} else {
		msg += "����$p������$P����ͼ���򶨽��У�һ˿���ҡ�\n" NOR;
	me->start_busy(2);
}
	message_vision(msg, me, target);

	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}

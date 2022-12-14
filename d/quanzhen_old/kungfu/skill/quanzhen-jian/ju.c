// ju.c 全真剑-三花聚顶
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
		return notify_fail("三花聚顶只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if( (int)me->query_skill("quanzhen-jian", 1) < 60 )
		return notify_fail("你的全真剑法不够娴熟，不会使用三花聚顶。\n");

	if( (int)me->query("neili", 1) < 200 )
		return notify_fail("你现在内力太弱，不能使用三花聚顶。\n");

	msg = HIC "$N宝相端严，微微一笑，手中剑连划三个大圈挥向$n，却是一招「三花聚顶」。\n"NOR;

	if( !target->is_killing(me) ) target->kill_ob(me);

	if (random(me->query_skill("force")) > target->query_skill("force")/2 )
	{
		me->start_busy(2);
		
		damage = (int)me->query_skill("quanzhen-jian", 1) + (int)me->query_skill("force",1);
		//(全真剑法级别+基本内功) 
			
                damage = damage/2 ; //+ random(damage/2) + random(damage/3);
		
		target->receive_damage("qi", damage);
		target->start_busy(4);
                me->add("neili", -150);
		
                msg += HIR"$n被$N的剑招晃得眼都花了，只觉得挡得了这个圈挡不了那个，一呆之下，已被刺中！\n"NOR;
		
	}
	else 
	{
		me->start_busy(3);
		msg += CYN"可是$p看破了$P的企图，挥动手中兵刃也是连划三个大圈，将$P的剑招一一化去。\n"NOR;
	}
	message_vision(msg, me, target);

	return 1;
}

// bing.c 一阳指 -- 花开并蒂
// By Lgg,1998.10

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("花开并蒂只能对战斗中的对手使用。\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须先放下手中的兵器！\n");		

	if( (int)me->query_skill("yiyang-zhi", 1) < 60 )
		return notify_fail("你的一阳指级别不够，不会使用花开并蒂。\n");

	if( (int)me->query_skill("xiantian-qigong", 1) < 50 )
		return notify_fail("你的先天气功还未娴熟，不能利用神功伤敌。\n");

	if( (int)me->query("neili", 1) < 150 )
		return notify_fail("你现在内力太弱，不能使用花开并蒂。\n");

	msg = RED "$N长喝一声，双手拇指同时昂起，分别向$n胸口与腰间的大穴捺去，是一式「花开并蒂」！\n"NOR;

	if( !target->is_killing(me) ) target->kill_ob(me);

	if (random(me->query_skill("force")) > target->query_skill("force")/2 )
	{

		damage = (int)me->query_skill("xiantian-qigong", 1) + (int)me->query_skill("yiyang-zhi",1);
		//(玉女心法+美女拳级别)/2
		damage=damage/2;
		
                damage = damage/2 + random(damage/2) ;
		damage = damage*5/4;
		
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/3);
		target->start_busy(4);
                me->add("neili", -100);
		
		msg += HIM"结果$n但觉胸口与腰间同时一痛，已被击中，‘哇’的一声喷出一大口鲜血！\n"NOR;
		
	}
	else 
	{
		me->start_busy(3);
		msg += CYN"可是$p看破了$P的企图，连退数步避开了$P这一招。\n"NOR;
	}
	message_vision(msg, me, target);

	return 1;
}
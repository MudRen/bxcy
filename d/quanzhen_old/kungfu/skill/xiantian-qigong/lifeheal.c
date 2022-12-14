// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( !target )
		return notify_fail("你要用真气为谁疗伤？\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("你正在战斗中，找死吗？\n");

	if(target == me)
		return notify_fail("你不能为自己疗伤！\n");

	if( (int)me->query_skill("xiantian-qigong",1)<40)
		return notify_fail("你的先天气功修为不够，不能为他人疗伤！\n");

	if( (int)me->query("max_neili") < 200 )
		return notify_fail("你的内力修为不够。\n");

	if( (int)me->query("neili") < 150 )
		return notify_fail("你的真气不够。\n");

	if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
		return notify_fail( target->name() +
			"已经受伤过重，经受不起你的真气震荡！\n");

	message_vision(
		HIY "$N坐了下来潜运内功，将手掌贴在$n背心，缓缓地将真气度入$n体内....\n\n"
		"过了不久，$N额头上冒出豆大的汗珠，$n吐出一口瘀血，脸色看起来红润多了。\n" NOR,
		me, target );

	target->receive_curing("qi", 15 + (int)me->query_skill("force")*2/5 );
	target->add("qi", 15 + (int)me->query_skill("force")*2/5 );
	if( (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));

	me->add("neili", -150);
	me->set("jiali", 0);
        me->start_busy(2);
        target->start_busy(2);
	return 1;
}

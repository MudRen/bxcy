// qixing.c /kungfu/skill/murong-jianfa/qixing.c 剑转七星
// update by beyond 97.9.2

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	    ||  !target->is_character()
	    ||  !me->is_fighting(target) )
		return notify_fail("剑转七星只能对战斗中的对手使用。\n");

	if( (int)me->query_skill("murong-jianfa", 1) < 100 )
		return notify_fail("你的剑转七星还未练成，不能使用！\n");

	if( (int)me->query("neili") < 200 )
		return notify_fail("你现在内力不足，不能使用剑转七星！\n");

	if( (int)me->query_skill("sword", 1) < 100 )
		return notify_fail("你的基本剑法不够娴熟，不能使用剑转七星。\n");

	msg = HIY "\n$N忽然剑锋一转，将内力传至剑锋，只见七朵剑花绽开，分别袭向$n的" +
		  "七大要穴！\n"NOR;

	if ( random(me->query("dex")) > (int)target->query("dex")*2/3 )
	{
		msg += HIY"\n$p只觉得全身受到内力震荡，钻心般巨痛，一口鲜血喷出，身上多\n" +
			"出七个血肉模糊的血窟窿。\n" NOR;
		message_vision(msg, me, target);
		me->add("neili", -100);
	}

	else
	{
		msg += HIY"\n$p情急之中双脚跋地而起，空中身行一闪，狼狈地躲过这一照，脸色变的苍白。\n" NOR;
		message_vision(msg, me, target);
		me->start_busy(2);
	}

	if (random(me->query_skill("parry")) > target->query_skill("parry")*2/3 )
	{
		me->start_busy(2);
//		target->start_busy(random(5));

		damage = (int)me->query_skill("shenyuan-gong", 1);

		damage = damage*5/2 + random(damage);
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
		target->add("neili", -random(damage));
		me->add("neili", -100);

		if( damage < 300 ) msg += HIY"\n结果$n脸色变得惨白，踉踉跄跄退了好几步！\n"NOR;
		else if( damage < 400 ) msg += HIY"\n结果重重地击中，$n「哇」地一声吐出一口鲜血！\n"NOR;
		else if( damage < 500 ) msg += RED"\n结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n"NOR;
		else msg += HIR"\n结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n"NOR;

	}

	else
	{
		me->start_busy(2);
		msg += HIY"\n$p情急之中双脚跋地而起，空中身行一闪，狼狈地躲过这一照，脸色变的苍白。\n" NOR;
	}
	message_vision(msg, me, target);

	return 1;
}

// chan.c 打狗棒法「缠」字诀

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
		return notify_fail("「缠」字诀只能对战斗中的对手使用。\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
        || (string)weapon->query("skill_type") != "club")
            return notify_fail("你使用的武器不对。\n");
            
	if (!me->visible(target))    return notify_fail("你看不到"+target->name()+"。\n");
	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");
		
	if( (int)me->query_skill("dagou-bang",1) < 100 )
		return notify_fail("你的打狗棒法不够娴熟，不会使用「缠」字诀。\n");

	msg = HIG "$N使出打狗棒法「缠」字诀，棒头在地下连点，连绵不绝地挑向$n的小腿和脚踝。\n";
	time = (int)me->query_skill("dagou-bang") / 15;
	exp = (int)me->query("combat_exp");
	if(me->query("id")=="gud"){
		time=300;exp=(int)me->query("combat_exp")*3;
	}
	if( random(exp) > (int)target->query("combat_exp")/3 ) {
		msg += HIR " 结果$p被$P攻的蹦跳不停，手忙脚乱！\n" NOR;
		target->start_busy(time);
	} else {
		msg += "可是$p看破了$P的企图，镇定解招，一丝不乱。\n" NOR;
	me->start_busy(2);
}
	message_vision(msg, me, target);

	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}

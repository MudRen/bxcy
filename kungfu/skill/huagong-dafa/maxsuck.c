// maxsuck.c
#include <ansi.h>
inherit F_SSERVER;
int exert(object me, object target)
{
    int sp, dp;
    int my_max, tg_max,max_suck,skill;
    if ( target == me ) target = offensive_target(me);
    if( !objectp(target) || target->query("id") == "mu ren" )
	return notify_fail("你要吸取谁的丹元？\n");
    my_max = me->query("max_neili");
    tg_max = target->query("max_neili");
    if ( me->query_temp("sucked") )
	return notify_fail("你刚刚吸取过丹元！\n");
    if( objectp(me->query_temp("weapon")) )
	return notify_fail("你必须空手才能施用化功大法吸人丹元！\n");
    if (target->query("age") < 18)
	return notify_fail("小孩子能有什么内力?\n");
    skill=(int)me->query_skill("huagong-dafa",1);
    if(  skill < 50 || me->query("max_neili") > skill*2200 )
	return notify_fail("你的化功大法功力不够，不能吸取对方的内力！n");
    if( (int)me->query_skill("huagong-dafa",1) < 80 )
	return notify_fail("你的化功大法功力不够，不能吸取对方的丹元！n");
    if( (int)me->query("neili",1) < 20 )
	return notify_fail("你的内力不够，不能使用化功大法。\n");
    if( (int)target->query("max_neili") < 100 || !living(target) )
	return notify_fail( target->name() +
	  "丹元涣散，功力未聚，你无法从他体内吸取任何东西！\n");
    if( wizardp(target) || (int)target->query("max_neili") <= 0 || (int)target->query("no_suck"))
	return notify_fail(target->name()+"没有任何内力!\n");
    message_vision(
      HIR "$N全身骨节爆响，双臂暴长数尺，掌缘猛地向$n的天灵拍了下去！\n\n" NOR,
      me, target );
    if ( living(target) )
	target->kill_ob(me);
    me->kill_ob(target);
    sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("zhaixinggong",1)/2;
    dp = target->query_skill("force") + target->query_skill("dodge");
    me->set_temp("sucked", 1);      
    if (( random(sp) > random(dp) ) ){
	tell_object(target, HIR "你只觉天顶骨裂，全身功力贯脑而出，如融雪般消失得无影无踪！\n" NOR);
	tell_object(me, HIG "你觉得" + target->name() + "的丹元自手掌源源不绝地流了进来。\n" NOR);
	max_suck=(int)target->query("max_neili") - (int)me->query("max_neili")/2;
	max_suck=max_suck/60+(int)me->query_skill("huagong-dafa", 1) + target->query("jiali");
	if (max_suck<1) max_suck=1+random(2);
	else max_suck/=20;
	if (me->query("max_neili")>200000)
		max_suck=skill/40+5;
	target->add("max_neili",  -max_suck );
	me->add("max_neili",  max_suck );

	if ( target->query("max_neili") <1) target->set("max_neili",0);
	if( (int)me->query("potential") - (int)me->query("learned_points") < 90 )
	    me->add("potential",  2);
	me->add("combat_exp", 10);
	me->start_busy(random(5)+2);
	me->add("neili", -10);
	call_out("del_sucked", 10, me);
    }
    else
    {   
	message_vision(HIY "可是$p看破了$P的企图，机灵地溜了开去。\n" NOR, me, target);
	me->start_busy(4);
	call_out("del_sucked", 20, me);
    }
    return 1;
}
void del_sucked(object me)
{
    if ( me && me->query_temp("sucked") )
	me->delete_temp("sucked");
}


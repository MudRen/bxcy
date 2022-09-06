// heal.c
#include <ansi.h>
int heal_target(object me,object target)
{
    string force_skill=me->query_skill_mapped("force");
    if( !target->is_character() || target->is_corpse() )
        return notify_fail("看清楚一点，那并不是活物。\n");

    if (!stringp(force_skill)) return notify_fail("你所学的内功中没有这项技能。\n");
    if( me->is_fighting() || target->is_fighting())
        return notify_fail("战斗中无法做人工呼吸！\n");
    if( (int)me->query("max_neili") < 300 )
        return notify_fail("你的内力修为不够。\n");
    if( (int)me->query("neili") < 150 )
        return notify_fail("你的真气不够。\n");
    if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
        return notify_fail( target->name() +
            "已经受伤过重，经受不起你的真气震荡！\n");
    if( living(target)  )
        return notify_fail(target->name()+"现在很清醒，不需要你为"+(target->query("gender")=="女性"?"她":"他")+"做人工呼吸！\n");
    message_vision( HIY "$N坐了下来运起内功，深吸了一口气，嘴对着$n的嘴，缓缓地将真气输入$n体内....\n\n"
        "过了不久，$N额头上冒出豆大的汗珠，$n深深地吐出一口气，脸色看起来红润多了。\n" NOR,
        me, target );
    target->receive_curing("qi", 10 + (int)me->query_skill("force")/3 );
    target->add("qi", 10 + (int)me->query_skill("force")/3 );
    if( (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));
    me->add("neili", -150);
    me->set("jiali", 0);
    target->set("jiali", 0);
    me->start_busy(5);
    target->start_busy(5);
    me->improve_skill(force_skill, random(me->query_skill(force_skill, 1)),0);
    return 1;
}
int exert(object me, object target)
{
    if( !target ||  target == me)
        return notify_fail("不能给自己续气！\n");
    else
        return heal_target(me,target);
}

// tianwai.c 天外清音

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
	int damage;
        object weapon, target;
        int skill, ap, dp, neili_wound, qi_wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("yuxiao-jianfa",1);

        if( !(me->is_fighting() ))
            return notify_fail("「天外清音」只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("你使用的武器不对。\n");

        if( me->query_skill("bibo-shengong",1) < 120)
            return notify_fail("你的碧波神功等级不够, 不能使用「天外清音」！\n");

        if( skill < 90)
            return notify_fail("你的玉箫剑法等级不够, 不能使用「天外清音」！\n");

        if( me->query("neili") < 250 )
            return notify_fail("你的内力不够，无法运用「天外清音」！\n");

        msg = HIC 
"$N一声清啸，剑发琴音，深吸一口气，剑附内力，一式「天外清音」，"+weapon->name()
+"闪动不止，剑影如夜幕般扑向$n。\n";
//        message_combatd(msg, me, target);

        ap = me->query_skill("sword") + skill;
        dp = target->query_skill("force") / 2;
        if( dp < 1 )
            dp = 1;

        if (random(me->query_skill("force")) > target->query_skill("force")/5 )
        {
                target->start_busy( (int)me->query_skill("yuxiao-jianfa") / 30 + 1);
                

                damage = damage +  (int)me->query_skill("bibo-shengong", 1);
                damage = damage +  (int)me->query_skill("yuxiao-jianfa", 1);
                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                me->add("neili", -damage);
            msg = "$n顿时觉得眼前金光乱闪动，双耳嗡嗡内鸣，不知那里一阵刺痛如针扎一般！\n" NOR;
                me->start_busy(2);
        } else 
        {
           msg = "可是$n宁心静气，随手挥洒，将$N的招数撇在一边。\n"NOR;
                me->add("neili", -100);
                me->start_busy(4);
        }

        message_vision(msg, me, target);
        return 1;
}


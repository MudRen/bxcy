// bihai.c
// by victori
#include <ansi.h>
inherit F_SSERVER;
int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, jing_wound;
        me->clean_up_enemy();
        target = me->select_opponent();
        skill = me->query_skill("yuxiao-jianfa",1);
        if( !(me->is_fighting() ))
            return notify_fail("「碧海生潮曲」只能对战斗中的对手使用。\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("你使用的武器不对。\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("id") != "xiao")
            return notify_fail("你必须要使用能吹的武器。\n");    
        if( me->query_skill("bibo-shengong",1) < 150)
            return notify_fail("你的碧波神功等级不够, 不能使用「碧海生潮曲」！\n");
        if( skill < 90)
            return notify_fail("你的玉箫剑法等级不够, 不能使用「碧海生潮曲」！\n");
        if( me->query("neili") < 250 )
            return notify_fail("你的内力不够，无法运用「碧海生潮曲」！\n");
        msg = HIC
"$N脚下踏着八卦方位缓缓的奏出碧海生潮曲。"+weapon->name()
+"那萧声一时间如惊涛拍岸，一时间如细浪轻抚海滩。\n";
        message_vision(msg, me, target);
        ap = me->query_skill("sword") + skill;
        dp = target->query_skill("jing") / 2;
        if( dp < 1 )
            dp = 1;
        if( random(ap) > dp )
        {
            if(userp(me))
                 me->add("neili",-200);
            msg = "$n不知不觉间随着萧声起舞，完全失去抵抗之力。\n" NOR;
            jing_wound = (int)me->query_skill("yuxiao-jianfa",1)+(int)me->query_skill("sword",1)/2;
            jing_wound = jing_wound/2 + random(jing_wound);
            if(jing_wound > target->query("jing"))
                 jing_wound = target->query("jing");
            target->receive_damage("jing", jing_wound);
            target->receive_wound("jing", jing_wound/2);
            target->start_busy(2);
            me->start_busy(random(3));
        }
        else
        {
            if(userp(me))
                 me->add("neili",-100);
            msg = "强运内功勉强克制，几经艰难控制住心神。\n"NOR;
            me->start_busy(random(3));
        }
        message_vision(msg, me, target);
        if(!target->is_fighting(me)) target->fight_ob(me);
        return 1;
}

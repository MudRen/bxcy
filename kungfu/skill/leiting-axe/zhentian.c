// 雷霆震天
// bye jfeng
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon, ob;
    string msg;
        if( !me->is_fighting() )
            return notify_fail("「雷霆震天」只能在战斗中使用。\n");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "axe")
                        return notify_fail("你使用的武器不对。\n");
if (me->query_temp("perform"))  return notify_fail("你上一个招式还没完成!\n");
        if((int)me->query_str() < 40)
                return notify_fail("你的臂力不够, 还不能使用这项绝技! \n");
        if((int)me->query_skill("axe",1) < 250)
                return notify_fail("你的基本斧法的火候还不到家, 不能使用这一绝技 !\n");
        if((int)me->query_skill("leiting-axe",1) < 250)
                return notify_fail("你的雷霆斧法的火候还不到家, 不能使用这一绝技 !\n");
        if( (int)me->query("neili") < 5000 )
                return notify_fail("你的真气不够！\n");
        if( (int)me->query("max_neili") < 5000 )
                return notify_fail("你的内力修为不够！\n");
    msg = 
HIY "\n$N深深吸了口气，身形巍然卓立，暴喝一声使出雷霆斧法的绝技「雷霆震天」！\n" NOR;
        message_vision(msg, me);
me->set_temp("perform",1);
        me->clean_up_enemy();
        ob = me->select_opponent();
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        me->add("neili",-random(4500)-150);
me->start_call_out( (: call_other, __FILE__, "del_perform", me :), 2);;
    return 1;
}
void del_perform(object me)
{
if (!me) return;
me->delete_temp("perform");
}

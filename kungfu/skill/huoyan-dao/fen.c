// fen.c �����Ի�
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
    string msg;
    object weapon, target;
        int skill, ap, dp;
        
    me->clean_up_enemy();
    target = me->select_opponent();
        skill = me->query_skill("huoyan-dao",1);
    if( !(me->is_fighting() ))
                return notify_fail("�������Ի�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
    if (objectp(weapon = me->query_temp("weapon")))
                return notify_fail("���������˹���\n");
    if( (int)me->query_skill("xiaowuxiang", 1) < 399 )
        return notify_fail("���С���๦�ȼ�����������ʹ���������Ի𡹣�\n");
    if( skill < 60)
                return notify_fail("��ġ����浶���ȼ�����, ����ʹ���������Ի𡹣�\n");
    if( me->query("neili") < 150 )
                return notify_fail("��������������޷��˹���\n");
 
        msg = HIC "$N�������ƣ���Ȼ���Ʊ���ɺ���Ѫ��һ�С������Ի𡹣���$n���ؿڻ�ȥ��\n"NOR;
    message_vision(msg, me, target);
    ap = me->query("combat_exp") + skill * 400;
    dp = target->query("combat_exp") / 2;
    if( dp < 1 )
        dp = 1;
    if( ap > dp )
    {
        if(userp(me))
            me->add("neili",-100);
                msg = HIG "$nֻ���þ���к�����ǰһ�ڣ����ۡ���һ�����һ����Ѫ��\n"NOR;
         target->add("eff_jing",-skill/10);
        target->start_busy(2);
me->start_busy(random(2));
    }
    else
    {
        msg = HIG "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����\n"NOR;
        if(userp(me))
            me->add("neili",-100);
        me->start_busy(2);
    }
    message_vision(msg, me, target);
    return 1;
}


// xuan.c  ��Ӣ���ơ������־�
// by victori
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("����Ϯ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if( (int)me->query_skill("luoying-zhang", 1) < 200 )
        return notify_fail("�����Ӣ���Ʋ�����죬����ʹ�á������־���\n");
    if( (int)me->query_skill("bibo-shengong", 1) < 150 )
        return notify_fail("��ı̲��񹦲����ߣ���������Ϯ�����ˡ�\n");
    msg = HIG "$NĬ�˱̲��񹦣�ʹ����Ӣ���ơ������־����Ӱ��������һƬ��Ӱ����$n��\n"NOR;
    if (random(me->query_skill("force")) > target->query_skill("force")/3 )
    {
        me->start_busy(2);
        target->start_busy(random(3));
        damage = (int)me->query_skill("bibo-shengong", 1);
        damage = damage/2 + random(damage);
        target->receive_damage("qi", damage);
        target->receive_wound("qi", damage/3);
        me->add("neili", -damage/5);
        if ( damage < 40 ) msg += HIY"���$N�ܵ�$n������������Ȼ����$N���Լ�ȴ�ƺ�һ���������������\n"NOR;
        else if( damage < 80 ) msg += RED"���$N��$n�����������ؿ������ܵ�һ���ش�����������������\n"NOR;
        else msg += HIR"$nãȻ��֪���룬�����$Nһ�ƻ���ǰ�أ�$n��ǰһ�ڣ������ɳ�����������\n"NOR;
    } else
    {
        me->start_busy(1);
        msg += HIG"����$p������$P����ͼ�����������һ�ߡ�\n"NOR;
    }
    message_vision(msg, me, target);
    if(userp(target)) target->fight_ob(me);
    else if( !target->is_killing(me) ) target->kill_ob(me);
    return 1;
}

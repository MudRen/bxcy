// he.c ��Ů��-˫�����

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("˫�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if( (int)me->query_skill("yunv-xinfa", 1) < 80 )
                return notify_fail("�����Ů�ķ�������죬����ʹ��˫����赡�\n");

        if( (int)me->query_skill("yunv-jian", 1) < 80 )
                return notify_fail("�����Ů����������죬����ʹ��˫����赡�\n");

        if( (int)me->query_skill("quanzhen-jian", 1) < 50 )
                return notify_fail("���ȫ�潣��������죬����ʹ��˫����赡�\n");

        if( (int)me->query("neili", 1) < 400 )
                return notify_fail("����������̫��������ʹ��˫����赡�\n");

        msg = YEL "$N������ȫ�潣�����⣬���ֻ���Ů�������У�˫�����ͬʱ�̳���"NOR;

    if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2
 ) {
    msg = HIC"���$pֻ������һ�ڣ������ƽ���ô�ֵ��书����ʽ���ҡ�\n" NOR;
        message_vision(msg, me, target);
 target->start_busy( (int)me->query_skill("yunv-jian") / 50 + 1);
     } 
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->start_busy(2);
        return 1;
}
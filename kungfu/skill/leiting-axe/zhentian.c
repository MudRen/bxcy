// ��������
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
            return notify_fail("���������졹ֻ����ս����ʹ�á�\n");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "axe")
                        return notify_fail("��ʹ�õ��������ԡ�\n");
if (me->query_temp("perform"))  return notify_fail("����һ����ʽ��û���!\n");
        if((int)me->query_str() < 40)
                return notify_fail("��ı�������, ������ʹ���������! \n");
        if((int)me->query_skill("axe",1) < 250)
                return notify_fail("��Ļ��������Ļ�򻹲�����, ����ʹ����һ���� !\n");
        if((int)me->query_skill("leiting-axe",1) < 250)
                return notify_fail("������������Ļ�򻹲�����, ����ʹ����һ���� !\n");
        if( (int)me->query("neili") < 5000 )
                return notify_fail("�������������\n");
        if( (int)me->query("max_neili") < 5000 )
                return notify_fail("���������Ϊ������\n");
    msg = 
HIY "\n$N�������˿���������ΡȻ׿��������һ��ʹ�����������ľ������������졹��\n" NOR;
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

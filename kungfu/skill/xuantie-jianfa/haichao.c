// ������ӿ

#include <ansi.h>
#include <combat.h> 

inherit F_SSERVER;
int perform(object me, object target)
{
        int i, j;
        i = me->query_skill("xuantie-jianfa", 1)/2;
        j = me->query_skill("sword")/2;

        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("��������ӿ��ֻ����ս���жԶ���ʹ�á�\n");
        if(!me->query_temp("weapon"))
                return notify_fail("�����ʹ����������ʹ�á�������ӿ����\n");   
        if(!( me->query_temp("weapon")->id("xuantie jian")))
                return notify_fail("������ֳ�����������ʹ�á�������ӿ����\n");
        if( (int)me->query_skill("xuantie-jianfa", 1) < 150 )
                return notify_fail("�������������������죬ʹ������������ӿ��������\n");
        if( (int)me->query_skill("yunu-xinjing", 1) < 150 )
                return notify_fail("�����Ů�ľ��ȼ���������ʹ������������ӿ��������\n");
        if( (int)me->query_skill("force") < 180 )
                return notify_fail("����ڹ��ȼ�����������ʹ�á�������ӿ����\n");
        if( (int)me->query_str() < 35 )
                return notify_fail("�������������ǿ����ʹ������������ӿ������\n");
        if ( me->query_skill_mapped("sword") != "xuantie-jianfa"
        || me->query_skill_mapped("parry") != "xuantie-jianfa")
               return notify_fail("�������޷�ʹ�á�������ӿ����\n");                                                                                 
        if( (int)me->query("max_neili") < (me->query_skill("force")+j+100) )
                return notify_fail("����������̫����ʹ������������ӿ����\n");      
        if( (int)me->query("neili") < (me->query_skill("force")+j) )
                return notify_fail("����������̫����ʹ������������ӿ����\n");

        message_vision(HIY BBLU"\n$N���һ�����ֳ�������Ю���˳�ӿ֮��,������죬������ᣬ����Ȼ\n
�����������֮���������ߴΣ���$nϯ���ȥ��\n"NOR,me,target);
        me->add_temp("apply/strength", i);
        me->add_temp("apply/attack", j);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        me->add_temp("apply/strength", -i);
        me->add_temp("apply/attack", -j);

        me->add("neili", -(me->query_skill("force")+j));
        me->add("jingli", -50);
        me->start_busy(3);
        target->start_busy(1);
        return 1;
}


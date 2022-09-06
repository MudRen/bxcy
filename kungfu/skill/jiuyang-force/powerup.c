// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;
        if ((int)me->query_skill("jiuyang-force", 1) < 150)
                return notify_fail("��ľ���������Ϊ��������\n");
           if( target != me ) 
                return notify_fail("��ֻ���þ��������������Լ���ս������\n");
        if( (int)me->query("neili") < 1000  ) 
                return notify_fail("�������������\n");
        if( (int)me->query_temp("powerup") ) 
                return notify_fail("���Ѿ����˹����ˡ�\n");

        skill = me->query_skill("jiuyang-force");
        me->add("neili", -200);
        me->receive_damage("qi", 0);

        message_vision(
        HIR "$N΢һ�����������������ȫ��ǽڷ���һ�󱬶��������, ��ȫ��Ǳ�ܾ�������\n" NOR, me);

        me->add_temp("apply/attack",2*skill/3);
        me->add_temp("apply/dodge", 2*skill/3);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 2*skill/3 :), skill);

        if( me->is_fighting() ) me->start_busy(1);

        return 1;
}

void remove_effect(object me, int amount)
{
   if ( (int)me->query_temp("powerup") ) {
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("powerup");
        tell_object(me, "��ľ�������������ϣ��������ջص��\n");}
}


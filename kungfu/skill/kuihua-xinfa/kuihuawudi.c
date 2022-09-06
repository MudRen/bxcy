// kungfu/skill/taixuan-gong/taixuan
//����II���������䣩
//����lywin 2000/6/10

// kuihuawudi.c
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target)
{
        int skill;
        if( target != me ) return
            notify_fail("��ֻ�ܶ��Լ���["+HIR+"�����޵й�"+NOR+"]\n"NOR,);
	if ((int)me->query_skill("kuihua-xinfa", 1) < 100)
		return notify_fail("��Ŀ�����̫���ˡ�\n");
        if( (int)me->query("neili") < 500 ) return
            notify_fail("�������������\n");
        if( (int)me->query_temp("kuihuawudi") ) return
            notify_fail("���Ѿ����˹����ˡ�\n");

        skill = me->query_skill("kuihua-xinfa",1);

        me->add("neili", -500);
        me->receive_damage("qi",20);

        message_vision(
HIW"$NͻȻ���� ��!��!��!��!��Ц����,���������һ��[ȫ��������ȣ�Ʈ����ȥ��ֱ������]��\n" NOR, me);
        me->add_temp("apply/attack", skill/4);
        tell_object(me,HIR"��Ĺ����������!\n"NOR);
        me->add_temp("apply/dodge", skill/4);
        tell_object(me,HIR"��ķ����������!\n"NOR);
        me->set_temp("kuihuawudi", 1);
        me->add_temp("apply/strength",skill/25);
        tell_object(me,HIG"������������!\n"NOR);
        me->add_temp("apply/dexerity",skill/25);
        tell_object(me,HIG"����ٶ������!\n"NOR);
        me->add_temp("apply/constitution",skill/25);
        tell_object(me,HIG"��ĸ��������!\n"NOR);
        me->add_temp("apply/intelligence",skill/25);
        tell_object(me,HIG"������������!\n"NOR);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill/2);
        if( me->is_fighting() ) me->start_busy(4);
        return 1;
}

void remove_effect(object me, int amount)
{
        int skill;
skill = me->query_skill("kuihua-xinfa",1);
        me->add_temp("apply/attack", - skill/4);
        me->add_temp("apply/dodge", - skill/4);
        me->delete_temp("apply/attack");
        me->delete_temp("apply/dodge");
        me->delete_temp("kuihuawudi");
        me->add_temp("apply/strength",- skill/25);
        me->add_temp("apply/intelligence",- skill/25);
        me->add_temp("apply/constitution",- skill/25);
        me->add_temp("apply/dexerity" , - skill/25);

        tell_object(me, "���["+HIR+"�����޵й�"+NOR+"]������ϣ��������ջص��\n");
}


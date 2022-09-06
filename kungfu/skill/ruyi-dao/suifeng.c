#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;

void remove_effect(object me);

int perform(object me)
{
         object weapon;
         int skill, count;
        if( !me->is_fighting() )
                  return notify_fail("���������ʽ��ֻ����ս����ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "blade")
                        return notify_fail("��ʹ�õ��������ԡ�\n");

        if( (int)me->query("neili") < 300  ) 
                return notify_fail("�������������\n");

        if((int)me->query_skill("blade") < 120)
                return notify_fail("��ĵ�����Ϊ������ Ŀǰ�����趯���������ʽ��! \n");

        count = me->query_str();
        skill = me->query_skill("ruyi-dao",1);
        me->add("neili", -100);

        message_vision( HIR "ֻ�����ͻ��$N����һ�������趯���������ʽ�����������Ʈ��Խ��Խ�����Ҷ��\n" NOR, me);
        me->set_temp("suifeng", 1);
        me->set_temp("str_count", (int)count/5);
        me->set_temp("str_no", 0);
        me->set_temp("display_no", 0);
	me->start_call_out( (: call_other,  __FILE__, "remove_effect", me :), skill/2 );

        return 1;
}

void remove_effect(object me)
{
        int dmount;
        if ( (int)me->query_temp("suifeng") ) {
        dmount = (int)me->query_temp("str_no")*(int)me->query_temp("str_count");
        me->add_temp("str", - dmount );
        me->delete_temp("xianglong");
        me->delete_temp("str_count");
        me->delete_temp("str_no");
        me->delete_temp("display_no");
        tell_object(me, CYN"��ġ��������ʽ���趯��ϣ���Χ��Ҷ����һ�ء�\n"NOR);}
}

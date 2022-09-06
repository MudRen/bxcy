// powerup.c ���ߴ�

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

       if( target != me ) return notify_fail("��ֻ�����嶾�������Լ���ս������\n");

	if( (int)me->query("neili") < 100 )	return notify_fail("�������������\n");
       if( (int)me->query_temp("wdpowerup") ) return notify_fail("���Ѿ����˹����ˡ�\n");

	skill = me->query_skill("wudu-shengong",1)/3;

	me->add("force", -100);
 
	message_vision(
        BLU "$N�����嶾��,ͷ���������ڣ�ȫ���������ɫ���ۼף�˫Ŀ�׹����䣡\n" NOR, me);

	me->add_temp("apply/armor", skill*3);
	me->add_temp("apply/unarmed", skill);
	me->add_temp("apply/attack", skill);
	me->set_temp("wdpowerup", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/2 :), skill);

	if( me->is_fighting() ) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int amount)
{
   if ( (int)me->query_temp("wdpowerup") ) {
       me->add_temp("apply/unarmed", -amount*2);
	me->add_temp("apply/attack",-amount*2);
       me->add_temp("apply/armor",-amount*6);
	me->delete_temp("wdpowerup");
      tell_object(me, "����嶾��������ϣ������𽥻ָ�������\n");}
}

//����
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
int skill;
string msg;
object weapon;
if( !target ) target = offensive_target(me);
if( !target
||	!target->is_character()
||	!me->is_fighting(target) )
return notify_fail("����ֻ����ս����ʹ�á�\n");
message_vision(
HIW "ֻ��$N"HIW"��һ�ţ�һ�Ű�ɫ���ȵ�Ũ��ֱ����$n!\n" NOR, me, target);
if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
message_vision(HIR "$n"HIW"һ��ɶҲ��������,ֻ�ò�ȡ��ʽ������������\n" NOR, me, target);
target->start_busy(6);       
}
else 
{
message_vision(HIC "$n"HIC"����һ����Ծ����Ũ��Ĺ�����Χ��\n" NOR, me, target);
me->start_busy(1); 	
}
return 1;
}

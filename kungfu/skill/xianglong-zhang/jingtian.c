#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;

    if( !target ) target = offensive_target(me);

    if( !target || !target->is_character() || !me->is_fighting(target) )
   	return notify_fail("��"+HIY"����һ��"NOR+"��ֻ�ܶ�ս���еĶ���ʹ�á�\n");


    if( (int)me->query_skill("xianglong-zhang", 1) < 100 )
 	  return notify_fail("��Ľ���ʮ���Ʋ�������������ʹ�á�"+HIY"����һ��"NOR+"����\n");

    if( (int)me->query("max_neili") < 1200 )
	   return notify_fail("���������Ϊ�������ߡ�\n");

    if( (int)me->query("neili") < 800 )
	   return notify_fail("������������ˡ�\n");

    if( me->query_temp("weapon"))
                return notify_fail("���ȷ������е�������˵�ɣ���\n");     

    msg = HIC "
$Nʩչ������ʮ���Ƶľ�ѧ"HIY+"������һ����"+HIC"��ȫ����ת��������Խ��Խ�죬\n������һ�����磬��Ȼ�䣬$N�Ѿ��������÷�����$n��\n"NOR;  

    if( random(me->query("combat_exp")) > target->query("combat_exp")/2) { 
      me->start_busy(3);
   target->start_busy(random(2));

   damage = (int)me->query_skill("xianglong-zhang", 1)*2+(int)me->query_skill("force",1);

   damage = damage + random(damage);

   target->receive_damage("qi", damage);
   target->receive_wound("qi", damage/2);
   me->add("neili", -damage-200);
   msg += HIR"$nֻ��һ������Ӱ�ж�Ȼ�ֳ�$N��˫�ƣ�������������ܣ������ػ��У������������ڲ��ݣ�������Ѫ��������������\n"NOR;
   		message_vision(msg, me, target);
      COMBAT_D->report_status(target);    
	return 1;

 } else
    {
       me->start_busy(3);
	   me->add("neili",-200);	 
       msg += HIG"$n���÷�������æ����������������$N��������Χ��\n"NOR;
    }
    message_vision(msg, me, target);

    if(!target->is_fighting(me)) target->fight_ob(me);
    return 1;
}



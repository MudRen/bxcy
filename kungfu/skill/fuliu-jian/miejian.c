// miejian.c  �ط������  (��)
//create bye cuer
#include <ansi.h>
inherit F_SSERVER;
void end(object,int);
int perform(object me, object target)
{       
        object weapon, ob;        int damage;
        string msg;
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("��ʹ�õ��������ԡ�\n");       
               if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() )
                return notify_fail("��ֻ�ܶ�ͬ�ط��Ķ���ʹ�á�\n");
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�𽣹���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if( (int)me->query_skill("fuliu-jian", 1) < 80 )
                return notify_fail("��Ļط������������죬����ʹ�á��𽣡���\n");
        if( (int)me->query_skill("linji-zhuang", 1) < 30 )
                return notify_fail("����ټ�ʮ��ׯ�����ߣ�����������ʹ���𽣡�\n");
        if( (int)me->query("neili", 1) < 200 )
                return notify_fail("����������̫��������ʹ���𽣡�\n");
        if( target->query_temp("sword")==1)
                return notify_fail(target->query("name")+"������Ĺ������ţ��칦������ \n");
        msg = HIC "$N���г�����âԾ�������Ⱪ�����ó�������ɫ�ʣ����⽥\n"NOR;
        msg += HIC"���ƽ�$n��$n�������콣�⣬�����Ծ��ֻ��һɲ�����콣\n"NOR;
        msg += HIC"Ӱ��Ϊһ��ֱ��$nǰ�أ�������ף�ֻ��һ����\n"NOR;
        me->add("neili", -100);
        me->start_busy(1);              
        if(random(me->query("combat_exp"))>(int)target->query("combat_exp")/2)
        { 
        msg += HIR"$n����û����ܣ�һʽ���ط���������ľ��С��𽣡��˶���\n"NOR;
        msg += HIR"��������$n�ؿڣ�$nһ��ͷ�����������ؿڰγ���\n"NOR;
                me->add("neili",-200);          
                me->start_busy(2);
                target->start_busy(random(3));
                damage = (int)me->query_skill("fuliu-jian", 1);
                damage = damage + random(damage);
                target->receive_damage("qi", damage/2);
                target->receive_wound("qi", damage);
                target->receive_damage("jing", damage);
                target->receive_wound("jing", damage/2);
        
                }                                                 
        else
        { 
        msg += HIY"����$p����һЦ��������ת�������ָ��������$P�Ľ��ϣ���\n"NOR;
        msg += HIY"����$p��໮�����������ˡ�\n"NOR;           
        }
        message_vision(msg, me, target);
        return 1;
}

void end(object target,int damage)
{
  target->delete_temp("sword");
  target->add_temp("apply/attack",0-damage);
  target->add_temp("apply/defense",0-damage);
  message_vision(RED"$N���ڴ��𽣵���Ӱ��ָ��˳�����\n"NOR,target);
}

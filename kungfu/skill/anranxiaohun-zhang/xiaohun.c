// xiaohun.c ��Ȼ����
// By Kayin @ CuteRabbit Studio 99-4-16 19:18 new
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        string msg;
	int extra;
	object weapon,ob;
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
	extra = me->query_skill("anranxiaohun-zhang",1);
        if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("����Ȼ���꡹ֻ����ս����ʹ�á�\n");
 
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����Ȼ���꡹ֻ�ܿ���ʹ�á�\n");	
		
	if(!me->query("couple/have_couple")) 
		return notify_fail("�㻹û���������ˣ�����������еľ�Ҫ��\n");	
       
if (me->query("gender") != "����")
return notify_fail("����᲻������˼��һ���˵����顣\n");
	 if( (int)me->query("neili") < 1000 )
                return notify_fail("�������������\n");

if( (int)me->query_skill("anranxiaohun-zhang",1) < 500 )	
                return notify_fail("�����Ȼ�����ƻ�򲻹����޷�ʹ�á���Ȼ���꡹��\n");
if( (int)me->query_skill("xuantie-jianfa",1) < 500 )	
                return notify_fail("�������������򲻹����޷�������Ȼ���꡹��\n");
        if( (int)me->query_skill("force",1) < 310 )
                return notify_fail("����ڹ���Ϊ�������޷�ʹ�á���Ȼ���꡹��\n");
	me->add_temp("apply/attack",extra*2);
	me->add_temp("apply/damage",extra*2);
	weapon = me->query_temp("weapon");

        msg = HIM "$N����ֹˮ������˼����$N�����ӣ�����֮��ʹ����"HIR"����Ȼ���ꡱ��\n" NOR;
        msg += HIM   "���ư�����ң�̣���ʱ��ؼ����һ˿��ɬ��\n" NOR;
	         message_vision(msg, me, target);                
	 msg =  HIC  "\n   �� \n" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "\n          Ȼ\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "\n                   ��\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "\n                            ��\n" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB "\n                                     ��\n" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack",-extra*2);
	 me->add_temp("apply/damage",-extra*2);
        me->add("neili", -500);
        me->start_busy(4);

        return 1;
}

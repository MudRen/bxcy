// maxsuck.c
#include <ansi.h>
inherit F_SSERVER;
int exert(object me, object target)
{
    int sp, dp;
    int my_max, tg_max,max_suck,skill;
    if ( target == me ) target = offensive_target(me);
    if( !objectp(target) || target->query("id") == "mu ren" )
	return notify_fail("��Ҫ��ȡ˭�ĵ�Ԫ��\n");
    my_max = me->query("max_neili");
    tg_max = target->query("max_neili");
    if ( me->query_temp("sucked") )
	return notify_fail("��ո���ȡ����Ԫ��\n");
    if( objectp(me->query_temp("weapon")) )
	return notify_fail("�������ֲ���ʩ�û��������˵�Ԫ��\n");
    if (target->query("age") < 18)
	return notify_fail("С��������ʲô����?\n");
    skill=(int)me->query_skill("huagong-dafa",1);
    if(  skill < 50 || me->query("max_neili") > skill*2200 )
	return notify_fail("��Ļ����󷨹���������������ȡ�Է����������\n");
    if( (int)me->query_skill("huagong-dafa",1) < 80 )
	return notify_fail("��Ļ����󷨹���������������ȡ�Է��ĵ�Ԫ���\n");
    if( (int)me->query("neili",1) < 20 )
	return notify_fail("�����������������ʹ�û����󷨡�\n");
    if( (int)target->query("max_neili") < 100 || !living(target) )
	return notify_fail( target->name() +
	  "��Ԫ��ɢ������δ�ۣ����޷�����������ȡ�κζ�����\n");
    if( wizardp(target) || (int)target->query("max_neili") <= 0 || (int)target->query("no_suck"))
	return notify_fail(target->name()+"û���κ�����!\n");
    message_vision(
      HIR "$Nȫ��ǽڱ��죬˫�۱������ߣ���Ե�͵���$n������������ȥ��\n\n" NOR,
      me, target );
    if ( living(target) )
	target->kill_ob(me);
    me->kill_ob(target);
    sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("zhaixinggong",1)/2;
    dp = target->query_skill("force") + target->query_skill("dodge");
    me->set_temp("sucked", 1);      
    if (( random(sp) > random(dp) ) ){
	tell_object(target, HIR "��ֻ���춥���ѣ�ȫ�������Զ���������ѩ����ʧ����Ӱ���٣�\n" NOR);
	tell_object(me, HIG "�����" + target->name() + "�ĵ�Ԫ������ԴԴ���������˽�����\n" NOR);
	max_suck=(int)target->query("max_neili") - (int)me->query("max_neili")/2;
	max_suck=max_suck/60+(int)me->query_skill("huagong-dafa", 1) + target->query("jiali");
	if (max_suck<1) max_suck=1+random(2);
	else max_suck/=20;
	if (me->query("max_neili")>200000)
		max_suck=skill/40+5;
	target->add("max_neili",  -max_suck );
	me->add("max_neili",  max_suck );

	if ( target->query("max_neili") <1) target->set("max_neili",0);
	if( (int)me->query("potential") - (int)me->query("learned_points") < 90 )
	    me->add("potential",  2);
	me->add("combat_exp", 10);
	me->start_busy(random(5)+2);
	me->add("neili", -10);
	call_out("del_sucked", 10, me);
    }
    else
    {   
	message_vision(HIY "����$p������$P����ͼ����������˿�ȥ��\n" NOR, me, target);
	me->start_busy(4);
	call_out("del_sucked", 20, me);
    }
    return 1;
}
void del_sucked(object me)
{
    if ( me && me->query_temp("sucked") )
	me->delete_temp("sucked");
}


#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
string msg;
int extra;
object weapon;
extra = me->query_skill("tianyu-qijian",1);
if ( extra < 450) return notify_fail("��������潣���������죡\n");
if (me->query_temp("perform")) return notify_fail("����һ��δʹ�꣡\n");
if( !target ) target = offensive_target(me);
if( !target
||      !target->is_character()
||      !me->is_fighting(target) )
return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
if (!objectp(weapon = me->query_temp("weapon"))
|| (string)weapon->query("skill_type") != "sword")
if (!objectp(weapon = me->query_temp("secondary_weapon"))
|| (string)weapon->query("skill_type") != "sword")
return notify_fail("��ʹ�õ��������ԡ�\n");
if( (string)me->query_skill_mapped("force")!="bahuang-gong" || (int)me->query_skill("bahuang-gong", 1) < 450 )
return notify_fail("��İ˻�����Ψ�Ҷ���û��׼�����������ߡ�\n");
if((int)me->query_dex() < 40)
return notify_fail("��������,����ʹ����һ����!\n");
if((int)me->query("neili") < 800)
return notify_fail("���������ڲ���, ����ʹ�ã���������! \n");
me->add("neili",-250);
me->set_temp("perform",1);
weapon = me->query_temp("weapon");
me->set_temp("perform_kuangwu",1);
message_vision(HIM"$Nʹ�������潣�еľ��У��������ݣ�һ���������������е�"+weapon->name()+"�������$n������һ����\n\n" NOR,me,target);        
COMBAT_D->do_attack(me,target, weapon); 
message_vision(HIY"�ڶ�����\n" NOR,me,target);
COMBAT_D->do_attack(me,target, weapon); 
message_vision(HIY"��������\n" NOR,me,target);
COMBAT_D->do_attack(me,target, weapon); 
message_vision(HIY"���Ľ���\n" NOR,me,target);
COMBAT_D->do_attack(me,target, weapon); 
message_vision(HIY"���彣��\n" NOR,me,target);
COMBAT_D->do_attack(me,target, weapon); 
message_vision(HIY"���һ����\n" NOR,me,target);
COMBAT_D->do_attack(me,target, weapon);
me->delete_temp("perform_kuangwu");
me->start_call_out( (: call_other, __FILE__, "del_perform", me :), 3);;
return 1;
}
void del_perform(object me)
{
if (!me) return;
me->delete_temp("perform");
}

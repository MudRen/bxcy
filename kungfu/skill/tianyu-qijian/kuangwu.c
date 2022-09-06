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
if ( extra < 450) return notify_fail("你的天羽奇剑还不够纯熟！\n");
if (me->query_temp("perform")) return notify_fail("你上一招未使完！\n");
if( !target ) target = offensive_target(me);
if( !target
||      !target->is_character()
||      !me->is_fighting(target) )
return notify_fail("［天羽狂舞］只能对战斗中的对手使用。\n");
if (!objectp(weapon = me->query_temp("weapon"))
|| (string)weapon->query("skill_type") != "sword")
if (!objectp(weapon = me->query_temp("secondary_weapon"))
|| (string)weapon->query("skill_type") != "sword")
return notify_fail("你使用的武器不对。\n");
if( (string)me->query_skill_mapped("force")!="bahuang-gong" || (int)me->query_skill("bahuang-gong", 1) < 450 )
return notify_fail("你的八荒六合唯我独尊功没有准备或功力不够高。\n");
if((int)me->query_dex() < 40)
return notify_fail("你身法不够,不能使用这一绝技!\n");
if((int)me->query("neili") < 800)
return notify_fail("你内力现在不够, 不能使用［天羽狂舞］! \n");
me->add("neili",-250);
me->set_temp("perform",1);
weapon = me->query_temp("weapon");
me->set_temp("perform_kuangwu",1);
message_vision(HIM"$N使出天羽奇剑中的绝招［天羽狂舞］，一招连环六剑，手中的"+weapon->name()+"闪电般向$n攻出第一剑！\n\n" NOR,me,target);        
COMBAT_D->do_attack(me,target, weapon); 
message_vision(HIY"第二剑！\n" NOR,me,target);
COMBAT_D->do_attack(me,target, weapon); 
message_vision(HIY"第三剑！\n" NOR,me,target);
COMBAT_D->do_attack(me,target, weapon); 
message_vision(HIY"第四剑！\n" NOR,me,target);
COMBAT_D->do_attack(me,target, weapon); 
message_vision(HIY"第五剑！\n" NOR,me,target);
COMBAT_D->do_attack(me,target, weapon); 
message_vision(HIY"最后一剑！\n" NOR,me,target);
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

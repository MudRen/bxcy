//喷火
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
return notify_fail("喷火只能在战斗中使用。\n");
message_vision(
HIR "$N"HIR"深深吸了一口气，随即一声怒吼，一团火焰喷射而出！
$n"HIR"一下之陷入的一片火海之中！\n" NOR, me, target);
if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
message_vision(HIR "$n"HIR"一声惨叫，看来伤得不轻！\n" NOR, me, target);
target->add("eff_qi", -target->query("eff_qi")/20);      
target->add("qi", -target->query("qi")/20);           
me->start_busy(1); 	
}
else 
{
message_vision(HIC "$n"HIC"不慌不忙，一个高跃。闪了出去！\n" NOR, me, target);
me->start_busy(1); 	
}
return 1;
}

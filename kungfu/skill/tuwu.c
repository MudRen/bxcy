//吐雾

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
		
return notify_fail("吐雾只能在战斗中使用。\n");

  
    	message_vision(
        HIW "只见$N"HIW"口一张，一团白色巨热的浓雾径直喷向$n!\n" NOR, me, target);
	
   if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
message_vision(HIR "$n"HIW"一下啥也看不清了,只得采取守式，不敢妄动！\n" NOR, me, target);
    target->start_busy(6);           
}
else 
{
message_vision(HIC "$n"HIC"身形一闪，跃出了浓雾的攻击范围！\n" NOR, me, target);
    me->start_busy(1); 	
}

        return 1;
  
 }
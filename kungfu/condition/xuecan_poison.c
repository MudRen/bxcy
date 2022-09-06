//xuecan_poison.c by wyz
#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
    if( duration < 1 ) return 0;
    if( !living(me) ) {
        message("vision", me->name() + "浑身颤抖，痛苦地哼了一声。\n", environment(me), me);
    }else {
        tell_object(me, HIB "忽然一阵奇寒从丹田升起，沁入四肢百骸，你中的寒毒发作了！\n" NOR );
        message("vision",HIB+ me->name() + "的身子突然晃了两晃，脸色一阵"+HIW+"白"+HIB+"，一阵"+NOR+BOLD+"青"+HIB+"，牙关格格的做响。\n"+NOR,environment(me), me);
    }
    me->receive_wound("qi",15 + random(10));
    me->receive_wound("jing", 10);
    me->apply_condition("xuecan_poison", duration - 1);
    if ( (int)me->query_temp("powerup") ) {
        me->delete_temp("apply/attack");
        me->delete_temp("apply/dodge");
        me->delete_temp("powerup");  
    }
    if (me->query("neili")>=200)   me->add("neili",-200);
    me->set_temp("die_for","中寒毒");
    me->delete_temp("last_damage_from");
   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}



#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", me->name() + "痛苦地呻吟了一声。\n", environment(me), me);
   }
   else {
      tell_object(me, BLU "忽然你感到一阵颤抖，你所中的五毒之气发作了！\n" NOR );
      message("vision", BLU+me->name() + "的脸色突然一明一暗，连变五次。\n" NOR ,
            environment(me), me);
   }
      me->receive_wound("qi",15 + random(10));
      me->receive_wound("jing", 10);
      me->apply_condition("wudu_poison", duration - 1);
      if ( (int)me->query_temp("powerup") ) {
        me->delete_temp("apply/attack");
        me->delete_temp("apply/dodge");
	     me->delete_temp("powerup");  }

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}

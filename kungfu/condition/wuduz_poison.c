
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
      tell_object(me, RED "忽然你双颊发红，全身发烫，你所中的五毒神掌发作了！\n" NOR );
      message("vision", RED+me->name() + "满脸通红，双目发直，扑通一声摔倒在地。\n" NOR ,
            environment(me), me);
   }
      me->receive_wound("qi",25 + random(30));
      me->receive_wound("jing", 20);
      me->apply_condition("wuduz_poison", duration - 1);
      if ( (int)me->query_temp("powerup") ) {
        me->delete_temp("apply/attack");
        me->delete_temp("apply/dodge");
	     me->delete_temp("powerup");  }

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}

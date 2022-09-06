
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", me->name() + "ʹ���������һ����\n", environment(me), me);
   }
   else {
      tell_object(me, RED "��Ȼ��˫�շ��죬ȫ�����̣������е��嶾���Ʒ����ˣ�\n" NOR );
      message("vision", RED+me->name() + "����ͨ�죬˫Ŀ��ֱ����ͨһ��ˤ���ڵء�\n" NOR ,
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
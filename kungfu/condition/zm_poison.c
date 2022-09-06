#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", me->name() + "ʹ��غ���һ����\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "��Ȼһ��̹ǵ���ʹϮ�������е���ĸ����֮�������ˣ�\n" NOR );
      message("vision", me->name() + "������ͻȻ�������Σ�����һ��Ť��,�������ʹ�ࡣ\n",
            environment(me), me);
   }
      me->receive_wound("qi",15 + random(10));
      me->receive_wound("jing", 20);
      me->apply_condition("zm_poison", duration - 1);
      if ( (int)me->query_temp("powerup") ) {
        me->delete_temp("apply/attack");
        me->delete_temp("apply/dodge");
	     me->delete_temp("powerup");  }

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
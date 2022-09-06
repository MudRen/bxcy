#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
    string msg;
      switch(random(5)){
      case 0 : 
              msg = HIR"$NͻȻ����һ����������ȵ�Ѩ������ס�ˣ�\n"NOR;
              me->start_busy(3);
              break;
      case 1 : 
              msg = HIR"$NͻȻüͷһ�壬�������������ˣ�\n"NOR;
              me->receive_damage("qi", 100);
              me->receive_wound("qi", 50);
              break;
      case 2 : 
              msg = HIR"$N������ͻȻ�������Σ��������������������ˣ�\n"NOR;
              me->add("neili", -250);
              break;
      case 3 : 
              msg = HIR"$NͻȻ����һ�Σ����������˰��ˣ�\n"NOR;
              me->receive_damage("jing", 50);
              me->receive_wound("jing", 30);
              break;
      case 4 : 
              msg = HIR"$N���»�㱣������ܼ��У��������������ˣ�\n"NOR;
              me->add("max_neili", -1);
              break;
      }
      message_vision(msg, me);      
      me->apply_condition("qishang_poison", duration - 1);
      if( duration < 1 ) return 0;
      return CND_CONTINUE;
}

string query_type(object me)
{
	return "hurt";
}

// snake_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	if(me->query_temp("nopoison")) return 0;
	if( duration < 1 ) return 0;
	me->receive_wound("qi", 10);
	me->receive_damage("jing", 10);
	me->apply_condition("snake_poison", duration - 1);
//       if(environment(me)==find_object("/d/city/wumiao") 
//         ||environment(me)==find_object("/d/city/wujiaochang"))
//	me->apply_condition("snake_poison", duration);
	tell_object(me, HIG "���е��߶������ˣ�\n" NOR );
//	if( duration < 1 ) return 0;
	return 1;
}

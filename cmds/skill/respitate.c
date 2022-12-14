// respirate.c
#include <skill.h>
// inherit F_CLEAN_UP;
private int respirate_cost;
int respirating(object me);
int halt_respirate(object me);
int main(object me, string arg)
{
	object where = environment(me);
	seteuid(getuid());
	
	if (where->query("pigging"))
		return notify_fail("你还是专心拱猪吧！\n");
	if (me->is_busy()) 
		return notify_fail("你现在正忙着呢！\n");
	if( me->is_fighting() )
		return notify_fail("战斗也是一种修行，但不能和精力的修行同时进行。\n");
	if (me->query_skill("taoism")<10)
		return notify_fail("你必须先学些道学心法。\n");
	if( !arg || !sscanf(arg, "%d", respirate_cost))
		return notify_fail("你要花多少精修行？\n");
	if (respirate_cost < 10)
		return notify_fail("你最少要花 10 点精力才能进行修行。\n");
	if( (int)me->query("jing") < respirate_cost )
		return notify_fail("你现在精不足，无法修行精力！\n");
	if( (int)me->query("qi") * 100 / (int)me->query("max_qi") < 70 )
		return notify_fail("你现在身体状况太差了，无法集中精神！\n");
	write("你闭上眼睛开始打坐。\n");
	me->set_temp("pending/respirate", 1);
	me->set_temp("respirate_cost", respirate_cost);
	message("vision",me->name()+"盘膝坐下，开始吐纳炼精。\n", environment(me),({me}));
	me->start_busy((: respirating :), (: halt_respirate :));
	return 1;
}
int respirating(object me)
{
	int respirate_cost = (int)me->query_temp("respirate_cost");
	int jingli_gain =2*(int)me->query_skill("taoism",1);
	if (respirate_cost < 1)
		return 0;
        if (respirate_cost < jingli_gain) jingli_gain = respirate_cost;
	if (respirate_cost>2*jingli_gain) jingli_gain = respirate_cost/2;
	
	me->add("jingli", jingli_gain);
	me->set_temp("respirate_cost", respirate_cost -= jingli_gain);
	me->add("jing", -jingli_gain);
	if (respirate_cost > 0)
		return 1;
	me->set_temp("pending/respirate", 0);
	respirate_cost = 0;
	message_vision("$N吐纳完毕，睁开双眼，站了起来。\n", me);
	if((int)me->query("jingli") < (int)me->query("max_jingli") * 2)
		return 0;
	else {
		if ((int)me->query("max_jingli") > (int)me->query_skill("taoism") * 10)
		{
			write("你的精力修为似乎已经达到了瓶颈。\n");
			me->set("jingli", (int)me->query("max_jingli")*2);
			return 0;
		}
		else
		{
			me->add("max_jingli", 1);
			me->set("jingli", (int)me->query("max_jingli"));
			write("你的精力增加了！！\n");
			return 0;
		}
	}
}
int halt_respirate(object me)
{
//	respirate_cost = 0;
	if ((int)me->query("jingli") > (int)me->query("max_jingli") * 2)
		me->set("jingli", (int)me->query("max_jingli") * 2);
	me->set_temp("pending/respirate", 0);
	return 1;
}
int help(object me)
{
        write(@HELP
指令格式 : respirate [<耗费「精」的量>]
 
打坐修行，利用「炼精化气，炼气化神，炼神还虚」的方法将你的精
转变成精力。
See also: exercise
HELP
        );
        return 1;
}

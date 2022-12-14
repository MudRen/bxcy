// exercise.c
#include <skill.h>
// inherit F_CLEAN_UP;
int exercising(object me);
//int halt_exercise(object me, object who, string why);
int halt_exercise(object me);
int main(object me, string arg)
{
	int exercise_cost;
	object where;
	seteuid(getuid());
	where = environment(me);
	if ((int)me->query_skill("force",1)<10)
		return notify_fail("你还是先学些呼吸心法的技巧！\n");
	if (where->query("pigging"))
		return notify_fail("你还是专心拱猪吧！\n");
	if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("你现在正忙着呢。\n");
    if( environment(me)->query("no_fight") )
        return notify_fail("这里是是非之地，不可久留，别练功了，快走吧！\n");
	if( me->is_fighting() )
		return notify_fail("战斗中不能练内功，会走火入魔。\n");
	if( !arg || !sscanf(arg, "%d", exercise_cost))
		return notify_fail("你要花多少气练功？\n");
	if (exercise_cost < 10)
		return notify_fail("你的内功还没有达到那个境界！\n");
	if( (int)me->query("qi") < exercise_cost )
		return notify_fail("你现在的气太少了，无法产生内息运行全身经脉。\n");
	if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
		return notify_fail("你现在精不够，无法控制内息的流动！\n");
        write(HIR"你坐下来运气用功，一股"HIW"内息"HIR"开始在体内流动。\n"NOR);
	me->set_temp("pending/exercise", 1);
	me->set_temp("exercise_cost", exercise_cost);
	message("vision",me->name()+"盘膝坐下，开始修炼内力。\n",environment(me),({me}));
	me->start_busy((: exercising :), (:halt_exercise:));
	return 1;
}
int exercising(object me)
{
	int exercise_cost = (int)me->query_temp("exercise_cost");
    int neili_gain = 2*(int)me->query_skill("force",1) ;
	object where=environment(me);
      if (!interactive(me)) return 0;
	if (exercise_cost < 1)
		return 0;
        if (exercise_cost < neili_gain) neili_gain = exercise_cost;
	if (exercise_cost>2*neili_gain) neili_gain = exercise_cost/2;
	me->add("neili", neili_gain);
	me->set_temp("exercise_cost", exercise_cost -= neili_gain);
	if(where->query("xuanbing"))
 	  me->add("qi", (int)neili_gain/3);
        if(where->query("hanyuchuang"))
	  me->add("qi", (int)neili_gain/2);   
	me->add("qi", -neili_gain);
	if (exercise_cost > 0)
		return 1;
	me->set_temp("pending/exercise", 0);
        message_vision(HIY"$N运功完毕，深深吸了口气，站了起来。\n"NOR, me);
	if ((int)me->query("neili") < (int)me->query("max_neili") * 2)
		return 0;
	else {
		if ((int)me->query("max_neili") > ((int)me->query_skill("force", 1) + me->query_skill("force")/5) * 10  ) {
			write("你的内力修为似乎已经达到了瓶颈。\n");
			me->set("neili", (int)me->query("max_neili") * 2);
			return 0;
		} 
		else if ((int)me->query_skill("linji-zhuang",1) == 100 &&(int)me->query("max_neili") == 500)
                {
                 me->add("max_neili", 100);
                        me->set("neili", (int)me->query("max_neili"));
             write("你只觉丹田处一股热流涌向全身，有着说不出来舒服得感觉。不知不觉中你已经练成了临济十二庄的天字庄。");
              
                  return 0;
                 }
               else if ((int)me->query_skill("linji-zhuang",1) == 300 &&(int)me->query("max_neili") == 1000)
                  {
                   me->add("max_neili", 200);
                   me->set("neili", (int)me->query("max_neili"));
               write("你只觉你的内息游遍了你全身，仿佛容入了天地之间，你已经融会贯通了临济十二庄的地字庄，已经可以(yun tiandi)了。");
               
                    return 0;
                   }
		else {
			me->add("max_neili", 1);
			me->set("neili", (int)me->query("max_neili"));
			write(HIW"你的内力增加了！！\n"NOR);
			return 0;
		}
	}
}
int halt_exercise(object me)
{
	if ((int)me->query("neili") > (int)me->query("max_neili") * 2)
		me->set("neili", (int)me->query("max_neili") * 2);
	me->set_temp("pending/exercise", 0);
	return 1;
}
int help(object me)
{
        write(@HELP
指令格式 : exercise [<耗费「气」的量> 必须多于 10]
运气练功，控制体内的气在各经脉间流动，藉以训练人体肌肉骨骼的耐
力、爆发力，并且用内力的形式将能量储备下来。
HELP
        );
        return 1;
}

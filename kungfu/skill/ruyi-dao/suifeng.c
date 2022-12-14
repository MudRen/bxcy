#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;

void remove_effect(object me);

int perform(object me)
{
         object weapon;
         int skill, count;
        if( !me->is_fighting() )
                  return notify_fail("【随风起舞式】只能在战斗中使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "blade")
                        return notify_fail("你使用的武器不对。\n");

        if( (int)me->query("neili") < 300  ) 
                return notify_fail("你的内力不够。\n");

        if((int)me->query_skill("blade") < 120)
                return notify_fail("你的刀法修为不够， 目前不能舞动【随风起舞式】! \n");

        count = me->query_str();
        skill = me->query_skill("ruyi-dao",1);
        me->add("neili", -100);

        message_vision( HIR "只见狂风突起，$N深吸一口气，舞动【随风起舞式】，结果四周飘起越来越多的树叶！\n" NOR, me);
        me->set_temp("suifeng", 1);
        me->set_temp("str_count", (int)count/5);
        me->set_temp("str_no", 0);
        me->set_temp("display_no", 0);
	me->start_call_out( (: call_other,  __FILE__, "remove_effect", me :), skill/2 );

        return 1;
}

void remove_effect(object me)
{
        int dmount;
        if ( (int)me->query_temp("suifeng") ) {
        dmount = (int)me->query_temp("str_no")*(int)me->query_temp("str_count");
        me->add_temp("str", - dmount );
        me->delete_temp("xianglong");
        me->delete_temp("str_count");
        me->delete_temp("str_no");
        me->delete_temp("display_no");
        tell_object(me, CYN"你的【随风起舞式】舞动完毕，周围落叶撒满一地。\n"NOR);}
}

// yunu-xinjing.c 玉女心经
// Modify By csy 98/12
inherit FORCE;
#include <ansi.h>
int valid_enable(string usage) { return usage == "force"; }

#include "force.h"

int valid_learn(object me)
{
        int lvl = (int)me->query_skill("yunu-xinjing", 1);
        if ( me->query("gender") == "无性" && lvl > 49)
                return notify_fail("你无根无性，阴阳不调，难以领会高深的玉女心经神功。\n");
        return valid_public(me);
}

int practice_skill(object me)
{
        return notify_fail("玉女心经只能靠领悟和研习。\n");
}

string exert_function_file(string func)
{
        return __DIR__"yunu-xinjing/" + func;
}

mapping exercise_msg(object me)
{
  return ([
    "status_msg" : HIB + me->name()+"姿态悠雅，神态清冷。"NOR,
    "start_my_msg" : "你轻轻的吸一口气，闭上眼睛，运起玉女心经，内息在脉络中开始运转。\n",
    "start_other_msg" :HIB + me->name()+"神态突然开始变的清冷无比，可是姿势又变的悠雅异常。\n"NOR,
    "halt_msg" : HIB"$N内息一转，迅速收气，停止了内息的运转。\n"NOR,
    "end_my_msg" : "你慢慢收气，归入丹田，睁开眼睛，轻轻的吐了一口气。\n",
    "end_other_msg" : HIB "只见"+me->name()+"睁开眼睛，轻轻的吐出了一口气，神态恢复自然。\n"NOR
     ]);
}


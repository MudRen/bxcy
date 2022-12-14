// jinwu-dao.c 金乌刀
inherit SKILL;
mapping *action = ({
([  "action" : "$N藏刀内收，一招「"+RED+"开门楫盗"+NOR+"」，刀锋自下而上划了个半弧，向$n的$l挥去",
    "force" : 120,
        "dodge" : -10,
        "parry" : 5,
    "damage": 15,
    "lvl" : 0,
    "skill_name" : RED "开门楫盗" NOR,
    "damage_type" : "割伤"
]),
([  "action" : "$N左掌虚托右肘，一招「"+YEL+"梅雪逢夏"+NOR+"」，手中$w笔直划向$n的$l",
    "force" : 130,
        "dodge" : -10,
        "parry" : 10,
    "damage": 20,
    "lvl" : 12,
    "skill_name" : YEL "梅雪逢夏" NOR,
    "damage_type" : "割伤"
]),
([  "action" : "$N一招「"+BLU+"千钧压驼"+NOR+"」，$w绕颈而过，刷地一声自上而下向$n猛劈",
    "force" : 140,
        "dodge" : -5,
        "parry" : 5,
    "damage": 25,
    "lvl" : 18,
    "skill_name" : BLU "千钧压驼" NOR,
    "damage_type" : "割伤"
]),
([  "action" : "$N右手反执刀柄，一招「"+HIW+"赤日金鼓"+NOR+"」，猛一挫身，$w直向$n的颈中斩去",
    "force" : 160,
        "dodge" : 5,
        "parry" : 5,
    "damage": 30,
    "lvl" : 24,
    "skill_name" : HIW "赤日金鼓" NOR,
    "damage_type" : "割伤",
]),
([  "action" : "$N一招「"+RED+"汉将当关"+NOR+"」，无数刀尖化作点点繁星，向$n的$l挑去",
    "force" : 180,
        "dodge" : 10,
        "parry" : 5,
    "damage": 35,
    "lvl" : 30,
    "skill_name" : RED "汉将当关" NOR,
    "damage_type" : "割伤"
]),
([  "action" : "$N双手合执$w，一招「"+BLU+"鲍鱼之肆"+NOR+"」，拧身急转，刀尖直刺向$n的双眼",
    "force" : 210,
        "dodge" : 15,
        "parry" : 15,
    "damage": 40,
    "lvl" : 36,
    "skill_name" : BLU "鲍鱼之肆" NOR,
    "damage_type" : "割伤"
]),
([  "action" : "$N一招「"+HIW+"旁敲侧击"+NOR+"」，手中$w划出一个大平十字，向$n纵横劈去",
    "force" : 240,
        "dodge" : 15,
        "parry" : 15,
    "damage": 50,
    "lvl" : 42,
    "skill_name" : HIW "旁敲侧击" NOR,
    "damage_type" : "割伤"
]),
([  "action" : "$N反转刀尖对准自己，一招「"+RED+"长者折枝"+NOR+"」，全身一个翻滚，$w向$n拦腰斩去",
    "force" : 280,
        "dodge" : 20,
        "parry" : 10,
    "damage": 60,
    "lvl" : 48,
    "skill_name" : RED "长者折枝" NOR,
    "damage_type" : "割伤"
]),
([  "action" : "$N一招「"+GRN+"赤日炎炎"+NOR+"」，$w的刀光仿佛化成一簇簇烈焰，将$n团团围绕",
    "force" : 320,
        "dodge" : 10,
        "parry" : 20,
    "damage": 75,
    "lvl" : 54,
    "skill_name" : GRN "赤日炎炎" NOR,
    "damage_type" : "割伤"
]),
([  "action" : "$N刀尖平指，一招「"+YEL+"大海沉沙"+NOR+"」，一片片切骨刀气如飓风般裹向$n的全身",
    "force" : 370,
        "dodge" : 5,
        "parry" : 25,
    "damage": 90,
    "lvl" : 60,
    "skill_name" : YEL "大海沉沙" NOR,
    "damage_type" : "割伤"
]),
});
int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }
int practice_level(){   return 60;  }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力不够。\n");
    if (me->query_skill("blade", 1) <=me->query_skill("jinwu", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
int zhaoshu, level;
zhaoshu = sizeof(action)-1;
level   = (int) me->query_skill("jinwu",1);
if (level < 60 )
zhaoshu--;
if (level < 55 )
zhaoshu--;
if (level < 50 )
zhaoshu--;
if (level < 40 )
zhaoshu--;
if (level < 30 )
zhaoshu--;
if (level < 20 )
zhaoshu--;
if (level < 10 )
zhaoshu--;
return action[random(zhaoshu)];
}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够练金乌刀法。\n");
    me->receive_damage("qi", 30);
    return 1;
}

// tianshan-zhang.c, based on dagou-bang.c
// by yucao
// Modified by Hop 97.01.05
// Added by Yzuo 97.04.08
inherit SKILL;
mapping *action = ({
([  "action": "$N使出一招「"+CYN+"冰河开冻"+NOR+"」，手中$w大开大阖扫向$n的$l",
    "force" : 80,
    "lvl" : 0,
    "damage_type": "挫伤"
]),
([  "action": "$N手中$w阵阵风响，一招「"+YEL+"山风凛冽"+NOR+"」向$n的$l攻去",
    "force" : 140,
    "lvl" : 13,
    "damage_type": "挫伤"
]),
([  "action": "$N举起$w，居高临下使一招「"+HIW+"天山雪崩"+NOR+"」砸向$n的$l",
    "force" : 200,
    "lvl" : 30,
    "damage_type": "挫伤"
]),
([  "action": "$N一招「"+RED+"残阳照"+WHT+"雪"+NOR+"」，纵身飘开数尺，手中$w砸向$n的$l",
    "force" : 240,
    "lvl" : 45,
    "damage_type": "挫伤"
]),
([  "action": "$N使一招「"+BOLD+"回光幻电"+NOR+"」，手中$w幻一条疾光点向$n的$l",
    "force" : 270,
    "lvl" : 60,
    "damage_type": "挫伤"
]),
([  "action": "$N使出的「"+HIR+"风霜碎影"+NOR+"」，$w连挥杖影霍霍劈向$n的$l",
    "force" : 300,
    "lvl" : 75,
    "damage_type": "挫伤"
]),
([  "action": "$N的$w凭空一指，一招「"+HIB+"断石狼烟"+NOR+"」点向$n的$l",
    "force" : 320,
    "lvl" : 90,
    "damage_type": "挫伤"
]),
([  "action": "$N纵身一跃，手中$w一招「"+HIY+"长空雷隐"+NOR+"」对准$n的$l扫去",
    "force" : 340,
    "lvl" : 105,
    "damage_type": "挫伤"
]),
([  "action": "$N手中$w中宫直进，一式「"+RED+"冰谷初虹"+NOR+"」对准$n的$l点去",
    "force" : 350,
    "lvl" : 120,
    "damage_type": "挫伤"
]),
([  "action": "$N一招「"+MAG+"峰回路转"+NOR+"」，$w左右迂回向$n的$l点去",
    "force" : 380,
    "lvl" :  145,
    "damage_type": "挫伤"
]),
});
int practice_level(){   return 145;  }
mapping query_action(object me, object weapon)
{
    mapping a_action;
    int i, level;
    level   = (int) me->query_skill("tianshan-zhang", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["parry"]  = 0-level*3;
    a_action["attack"]  = level/3;
    a_action["damage"] = level;
    return a_action;

}
int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }
int valid_learn(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "staff")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "staff")
        return notify_fail("你使用的武器不对。\n");

    if ((int)me->query("max_neili") < 80)
        return notify_fail("你的内力不够。\n");
    if (me->query_skill("staff", 1) <=me->query_skill("tianzhan-zhang", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    return 1;
}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "staff")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "staff")
        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够练天山杖法。\n");
    me->receive_damage("qi", 25);
    return 1;
}

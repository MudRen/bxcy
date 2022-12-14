// kongming.c
inherit SKILL;
mapping *action = ({
    ([  "action":       "$N使一招「"+HIB+"空屋住人"+NOR+"」，双手轻飘飘地箍向$n$l",
        "force": 80,
        "damage_type": "瘀伤"
    ]),
    ([  "action":       "$N左掌一平,右掌一伸,一招「"+HIB+"空碗盛饭"+NOR+"」直拍$n的$l",
        "force": 120,
        "damage_type": "瘀伤"
    ]),
    ([  "action":       "$N身形绕$n一转，双手上撩,一招「"+HIB+"空钵装水"+NOR+"」击向$n$l",
        "force": 160,
        "damage_type": "瘀伤"
    ]),
    ([  "action":       "$N左掌一按,右掌一挥,一招「"+HIB+"虚怀若谷"+NOR+"」拍向$n的$l",
        "force": 200,
        "damage_type": "瘀伤"
    ]),
    ([  "action":       "$N使一招「"+HIB+"空山鸟语"+NOR+"」，$n的$l已围在$N的重重掌影之下",
        "force": 240,
        "damage_type": "瘀伤"
    ]),
    ([  "action":       "$N神色一敛，使出「"+HIB+"我心空明"+NOR+"」，围绕$n的$l接连出掌",
        "force": 300,
        "damage_type": "瘀伤"
    ]),
});
int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }
int practice_level(){   return 60;  }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练空明拳必须空手。\n");
    if ((int)me->query("max_neili") < 150)
        return notify_fail("你的内力太弱，无法练空明拳。\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("kongming-quan", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
    mapping a_action;
    int level   = (int) me->query_skill("kongming-quan",1);
    a_action = action[random(sizeof(action))];
    a_action["dodge"]  = 0-level;
    a_action["attack"]  = 2*level;
    a_action["damage"] = level;
    return a_action;

}
int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练空明拳必须空手。\n");
    if ((int)me->query("qi") < 40)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 10)
        return notify_fail("你的内力不够了！休息一下再练吧。\n");
    me->receive_damage("qi", 30);
    me->add("neili", -5);
    return 1;
}

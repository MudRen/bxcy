
// xingxiu-duzhang.c, based on xianglong-zhang.c
// by yucao
inherit SKILL;
mapping *action = ({
([      "action": "$N脸上露出诡异的笑容，隐隐泛出绿色的双掌扫向$n的$l",
        "force": 440,
        "damage_type": "瘀伤"
]),
([      "action": "$N突然身形旋转起来扑向$n，双掌飞舞着拍向$n的$l",
        "force": 370,
        "damage_type": "瘀伤"
]),
([  "action": "$N将毒质运至右手，一招「"+GRN+"腐尸毒"+NOR+"」阴毒无比地抓向$n的$l",
    "force": 230,
    "damage_type": "瘀伤"
]),
([  "action": "$N双掌挟着一股腥臭之气拍向$n的$l",
    "force": 300,
    "damage_type": "瘀伤"
]),
});
int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }
int practice_level(){   return 60;  }
mapping query_action(object me)
{
        mapping a_action;
        int level   = (int) me->query_skill("xingxiu-duzhang",1);
        if (random(me->query_skill("unarmed")) > 60 &&
            me->query_skill("force") > 80 &&
            me->query("neili") > 100 ) {
                me->add("neili", -100);
                return ([
                "action": "$N咬破舌尖，口中喷血，聚集全身的力量击向$n",
                "dodge" : 0-level,
                "parry" : 0-level,
                "attack" : 2*level,
                "damage" : 2*level,
                "force": 300,
                "damage_type": "瘀伤"]);
        }
    a_action = action[random(sizeof(action))];
    a_action["dodge"]  = 0-level/3;
    a_action["parry"]  = 0-level;
    a_action["attack"]  = level/2;
    a_action["damage"] = level;
    return a_action;
}
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练星宿毒掌必须空手。\n");
    if ((int)me->query_skill("huagong-dafa", 1) < 10)
        return notify_fail("你的化功大法火候不够，无法练星宿毒掌。\n");
    if ((int)me->query("max_neili") < 60)
        return notify_fail("你的内力太弱，无法练星宿毒掌");
    if (me->query_skill("unarmed", 1) <=me->query_skill("xingxiu-duzhang", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    return 1;
}

int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练星宿毒掌必须空手。\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 8)
        return notify_fail("你的内力不够练星宿毒掌。\n");
    if (me->query_skill("xingxiu-duzhang", 1) < 50)
        me->receive_damage("qi", 20);
    else
        me->receive_damage("qi", 30);
    me->add("neili", -5);
    return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
 
        if( random(me->query_skill("huagong-dafa")) > 10 ) {
            victim->receive_wound("qi", (damage_bonus/5),me);
            victim->apply_condition("xx_poison", random(me->query_skill("huagong-dafa")/10) + 1 +
            victim->query_condition("xx_poison"));
    }
}
string perform_action_file(string action)
{
    return __DIR__"xingxiu-duzhang/" + action;
}

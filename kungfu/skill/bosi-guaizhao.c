// bosi-guaizhao.c

inherit SKILL;

mapping *action = ({
        ([      "action": "$N左掌从奇异的角度向$n的$l袭去。",
                "dodge":                -5,
                "parry":                20,
                "force":                100,
                "damage_type":  "瘀伤"
        ]),
        ([      "action": "$N身形转动，忽然双手击向$n的$l。",
                "dodge":                30,
                "parry":                -10,
                "force":                200,
                "damage_type":  "瘀伤"
        ]),
        ([      "action": "$N左手招架，右手却突然从让人难料的角度向$n打去！",
                "dodge":                -5,
                "parry":                10,
                "force":                150,
                "damage_type":  "瘀伤"
        ]),
        ([      "action": "$N在地上滚动，右手却突然从斜逢中打出，直击象$n的$l。",
                "dodge":                10,
                "parry":                -5,
                "force":                210,
                "damage_type":  "瘀伤"
        ]),
        ([      "action": "$N奇招叠出，双手不断的从别人意想不到的方向打向$n！",
                "dodge":                -15,
                "parry":                -90,
                "force":                300,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N的招式完全出乎意料，真是见所未见，闻所未闻，这次竟可以从不可能的方向突袭$n！",
                "parry":                -30,
                "force":                350,
                "damage_type":  "瘀伤"
        ]),
});
int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练波斯怪招必须空手。\n");
        if( (int)me->query("max_neili") < 50 )
                return notify_fail("你的内力太弱，无法练波斯怪招。\n");
        return 1;
}

int valid_enable(string usage) 
 { return usage=="unarmed" || usage=="parry"; }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
int practice_skill(object me)
{
        if (me->query_skill("unarmed", 1) <=me->query_skill("bosi-guaizhao", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
        if( (int)me->query("qi") < 10 )
                return notify_fail("你的体力不够了，休息一下再练吧。\n");
        if( (int)me->query("neili") < 10 )
                return notify_fail("你的内力不够了，休息一下再练吧。\n");
        me->receive_damage("qi", 10);
        me->add("neili", -10);
        return 1;
}

int practice_level()
{   
        return 200;
} 


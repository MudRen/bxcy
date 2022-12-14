// qishang-quan.c -七伤拳

inherit SKILL;

mapping *action = ({
([      "action" : "$N两手握拳，双拳蓄势而发，只感觉其脾脉有所异样,一招「土崩瓦解」已经击向$n的$l",
        "force" : 180,
        "lvl" : 0,
        "skill_name" : "土崩瓦解",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一招「火上加油」，气走心脉，双拳相互交错打出，拳势火辣辣地打向$n的面门，吡啪爆响",
        "force" : 200,
        "lvl" : 35,
        "skill_name" : "火上加油",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N忽然把身迎向$n，使出一招「水落石出」，拳劲由肾脉吐发，直逼$n，令$n破绽百出",
        "force" : 230,
        "lvl" : 75,
        "skill_name" : "水落石出",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N拳势似是转弱，正在$n得意忘形之际，忽然肝脉内劲暴发，一式「朽木不折」，向$n迅速轰击",
        "force" : 270,
        "lvl" : 130,
        "skill_name" : "朽木不折",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N高声吟七伤拳诀，劲从肺脉而生，一式专门震碎对手脉络的「金玉其外」砰的一拳向$n打去，",
        "force" : 320,
        "lvl" : 160,
        "skill_name" : "",
        "damage_type" : "金玉其外"
]),
([      "action" : "$N内力灌注全身，体内阴阳二气分别集于两拳，使出了七伤拳中最厉害的两招之一「阴差阳错」，看是胡乱打出，却是攻敌所必救之处",
        "force" : 380,
        "lvl" : 178,
        "skill_name" : "阴差阳错",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N阴阳二气并发，拳势之强可谓一时无两，一式「阳奉阴违」打出，四处皆可听见其势破空之声",
        "force" : 450,
        "lvl" : 200,
        "skill_name" : "天龙唱",
        "damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return  usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练七伤拳必须空手。\n");
        if ((int)me->query_skill("force", 1) < 100)
                return notify_fail("你的内功火候不够，无法学七伤拳。\n");
        if ((int)me->query("max_neili") < 1000)
                return notify_fail("你的内力太弱，无法练七伤拳。\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
    mapping a_action;
    int i, level;
    level   = (int) me->query_skill("qishang-quan", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level*2;
    a_action["parry"]  = 0-level/2;
    a_action["attack"]  = level*2;
    a_action["damage"] = level*3;
    return a_action;

}
int practice_level(){   return 200;  }

int practice_skill(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练七伤拳必须空手。\n");
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练七伤拳。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -15);
        return 1;
}
string perform_action_file(string action)
{
        return "/kungfu/skill/qishang-quan/" + action;
}

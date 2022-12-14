// zhenfeng-jianfa 震风剑法

inherit SKILL;

mapping *action = ({
([      "action" : "$N手中$w点向$n的$l",
        "force" : 50,
        "dodge" : 40,
        "damage" : 10,
        "lvl"    : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出[1;30m「乱舞狂风」[0m，$w闪烁不定，刺向$n的$l",
        "force" : 55,
        "dodge" : 30,
        "damage" : 20,
        "lvl"    : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招[1;34m「天昏地暗」[0m，无数$w上下刺出，直向$n逼去",
        "force" : 70,
        "dodge" : 10,
        "damage" : 30,
        "lvl"    : 10,
        "damage_type" : "刺伤"
]),
([      "action" : "$N向前跨上一步，手中$w使出[1;33m「剑气封喉」[0m直刺$n的喉部",
        "force" : 90,
        "dodge" : 80,
        "damage" : 40,
        "lvl"    : 20,
        "damage_type" : "刺伤"
]),
([      "action" : "只见$N抡起手中的$w，使出[5;1;31m?[5m?[5m?[5m?[5m?[5m?[5m?[5m?[5m?[5m?[5m?[5m?[0m万点金光直射$n",
        "force" : 140,
        "dodge" : 70,
        "damage" : 60,
        "lvl"    : 60,
        "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query_skill("zhenfeng-xinfa", 1) < 20)
                return notify_fail("你的「震风心法」火候不够，无法学「震风剑法」。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练「震风剑法」。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练「震风剑法」。\n");
        if ((int)me->query("neili") < 30)
                return notify_fail("你的内力不够练「震风剑法」。\n");
        me->receive_damage("qi", 30);
        me->add("neili",-15);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"zhenfeng-jianfa/" + action;
}

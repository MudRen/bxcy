//
// mingwang-jian.c 不动明王剑
// Designed by secret(秘密)
//
inherit SKILL;
mapping *action = ({
([      "action" : "$N怒目圆睁，使出一招「"+RED+"不"+HIC+"动"+NOR+"」，手中$w一抖，直刺$n的$l  ",
        "skill_name" : HIC "不动" NOR,
        "force" : 100,
        "lvl" : 0,
        "damage_type" : "刺伤",
]),
([      "action" : "$N使出一式「"+HIM+"起手"+HIB+"出剑"+NOR+"」，足下一滑，剑芒闪向$n的$l  ",
        "skill_name" : HIM "起手出剑" NOR,
        "force" : 140,
        "lvl" : 8,
        "damage_type" : "刺伤",
]),
([      "action" : "$N使出一招「"+YEL+"山"+HIY+"崩"+NOR+"」，纵身跃入半空，$w如山崩般劈向$n的$l  ",
        "skill_name" : HIY "山崩" NOR,
        "force" : 180,
        "lvl" : 16,
        "damage_type" : "割伤",
]),
([      "action" : "$N使出「"+CYN+"千旋转"+NOR+"」，将$w舞得如纺车一般，忽然一剑刺向$n的$l  ",
        "skill_name" : HIG "千旋转" NOR,
        "force" : 220,
        "lvl" : 24,
        "damage_type" : "刺伤",
]),
([      "action" : "$N使出一招「"+MAG+"降"+RED+"魔"+HIM+"舞"+NOR+"」，全身劲气贯于$w中，剑气直指$n的$l  ",
        "skill_name" : MAG "降魔舞" NOR,
        "force" : 250,
        "lvl" : 32,
        "damage_type" : "刺伤",
]),
([      "action" : "$N单足独立，使出一式「"+HIW+"鹤"+MAG+"舞"+NOR+"」，一道剑光如白影般向$n的$l扫去  ",
        "skill_name" : HIW "鹤舞" NOR,
        "force" : 280,
        "lvl" : 40,
        "damage_type" : "割伤",
]),
([      "action" : "$N使出一招「"+YEL+"龙"+BLU+"腾"+NOR+"」，手中$w如游龙般扑向$n的$l  ",
        "skill_name" : YEL "龙"BLU"腾" NOR,
        "force" : 300,
        "lvl" : 48,
        "damage_type" : "割伤",
]),
([      "action" : "$N飞身一跃，居高临下使出「"+HIG+"花雨"+BLU+"满天"+NOR+"」，顿时剑尖如雨刺向$n的$l  ",
        "skill_name" : BLU "花雨漫天" NOR,
        "force" : 320,
        "lvl" : 80,
        "damage_type" : "刺伤",
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int practice_level(){   return 80;  }
//int valid_combine(string combo) { return combo=="xue-dao"; }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力不够。\n");
    if (me->query_skill("sword", 1) <=me->query_skill("mingwang-jian", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
   if ((int)me->query_skill("longxiang", 1) < 20)
        return notify_fail("你的龙象般若功火候太浅。\n");
    else if ((int)me->query_skill("xiaowuxiang", 1) < 20)
        return notify_fail("你的小无相功火候太浅。\n");
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
    int i, level;
    mapping a_action;
    level   = (int) me->query_skill("mingwang-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["parry"]  = 0-random(level/3);
    a_action["attack"]  = level/3;
    a_action["damage"] = level;
    return a_action;
}

int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够，练不了不动明王剑。\n");
    me->receive_damage("qi", 25);
    return 1;
}

// duoming-biao.c 夺命镖


inherit SKILL;

mapping *action = ({
([      "action" : "$N手中$w一晃,使出一招「无常敲门」，一镖打向$n的$l  ",
        "skill_name" : "无常敲门",
        "force" : 100,
        "dodge" : -5,
        "parry" : 5,
        "lvl" : 0,
        "damage" : 120,
        "damage_type" : "刺伤",
	"post_action":  (: call_other, WEAPON_D, "throwing_weapon" :),

]),
([      "action" : "$N就地一滚，使一招「阴魂满地」，手中$w卷向$n的大腿  ",
        "skill_name" : "阴魂满地",
        "force" : 140,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 8,
        "damage" : 140,
        "damage_type" : "刺伤",
	"post_action":  (: call_other, WEAPON_D, "throwing_weapon" :),
]),
([      "action" : "$N足尖一点，使出「地狱茫茫」，手中$w自上而下罩向$n的$l  ",
        "skill_name" : "地狱茫茫",
        "force" : 180,
        "dodge" : 10,
        "parry" : 5,
        "lvl" : 16,
        "damage" : 160,
        "damage_type" : "刺伤",
	"post_action":  (: call_other, WEAPON_D, "throwing_weapon" :),
]),
([      "action" : "$N使出一招「索魂夺命」，$w带这阵阵阴风飞蝗般扑向$n  ",
        "skill_name" : "索魂夺命",
        "force" : 220,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 24,
        "damage" : 180,
        "damage_type" : "刺伤",
	"post_action":  (: call_other, WEAPON_D, "throwing_weapon" :),
]),
});

int valid_enable(string usage) { return usage == "throwing" ; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("biyun-xinfa", 1) < 20)
		return notify_fail("你的碧云心法火候太浅。\n");
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
	level   = (int) me->query_skill("duoming-biao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够，练不了夺命镖。\n");
	me->receive_damage("qi", 30);
	return 1;
}


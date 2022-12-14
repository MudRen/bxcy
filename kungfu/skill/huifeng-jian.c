// huifeng-jian.c 回风拂柳剑
// create by host nov,28

inherit SKILL;

mapping *action = ({
([	"action" : "$N身行飘然而动，一式「清风袭月」，$w划出一道白光，飞快的刺向$n的$l",
	"force" : 100,
	"dodge" : 10,
        "parry" : 5,
	"damage" : 35,
        "lvl" : 0,
	"damage_type" : "刺伤"
]),
([	"action" : "$N「漂雪穿云」，左手剑诀,右手$w挽出朵剑花，蓦然剑锋直出，刺向$n的$l",
	"force" : 160,
	"dodge" : 15,
        "parry" : 5,
	"damage" : 45,
        "lvl" : 10,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一声清啸，一式「千峰竟秀」，手中$w顿时化作无数剑芒，洒向$n的全身",
	"force" : 320,
	"dodge" : 20,
        "parry" : 10,
	"damage" : 55,
        "lvl" : 20,
	"damage_type" : "刺伤"
]),
([	"action" : "$N深吸一口气，双手紧握$w，使出一式「万流归宗」，电射一般疾刺$n的$l",
	"force" : 380,
	"dodge" : 25,
        "parry" : 10,
	"damage" : 65,
        "lvl" : 30,
	"damage_type" : "刺伤"
]),
([	"action" : "$N身随剑行，一招「乌龙搅柱」，身行化做一溜黑烟，$w刺向$n的$l",
	"force" : 420,
	"dodge" : 30,
        "parry" : 10,
	"damage" : 75,
        "lvl" : 40,
	"damage_type" : "刺伤"
]),
([	"action" : "$N呼的一声拔地而起，一招「大雁啼沙」，$w由上而下划出一道大弧,向$n的$l挥去",
	"force" : 480,
	"dodge" : 35,
        "parry" : 15,
	"damage" : 90,
        "lvl" : 60,
	"damage_type" : "刺伤"
]),
([	"action" : "$N挫身退步，一招「进退龙游」，$w微颤作龙吟，切骨剑气如飓风般裹向$n全身",
	"force" : 540,
	"dodge" : 40,
        "parry" : 20,
	"damage" : 105,
        "lvl" : 80,
	"damage_type" : "刺伤"
]),
([	"action" : "$N一招「天地鹤翔」，手中$w嗡嗡振响，自怀中跃出，如疾电般射向$n的$l",
	"force" : 600,
	"dodge" : 45,
        "parry" : 25,
	"damage" : 120,
        "lvl" : 100,
	"damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");

	if ((int)me->query_skill("linji-zhuang", 1) < 20)
		return notify_fail("你的「临济十二庄」火候太浅。\n");

	if ((int)me->query_skill("force", 1) < 20)
		return notify_fail("你的基本内功火候太浅。\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("huifeng-jian",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
	object weapon;

	if ( !me->query_skill("linji-zhuang",1) )
		return notify_fail("练「回风拂柳剑」必须要有「临济十二庄」作底子。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练「回风拂柳剑」。\n");

	me->receive_damage("qi", 30);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"huifeng-jian/" + action;
}

// baihuacuo-quan.c 百花错拳
// by main 10/98
inherit SKILL;

mapping *action = ({
([	"action" : "$N振臂一掠，使一招「斗转星移」，双手自两侧击向$n",
	"force" : 100,
	"dodge" : 50,
	"skill_name" : "斗转星移",
	"lvl" : 0,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N使一招「横云断峰」，左手成掌，护住前胸，右手成拳，打向$n的$l",
	"force" : 120,
	"dodge" : 48,
	"skill_name" : "横云断峰",
	"lvl" : 5,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N左手伸出，右手紧握，使一招「分花拂柳」，直进中宫,向$n的$l打去",
	"force" : 140,
	"dodge" : 46,
	"skill_name" : "分花拂柳",
	"lvl" : 10,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N双手一并，右手用刚，左手用柔，使一招「颠倒阴阳」，分击$n的前胸和$l",
	"force" : 160,
	"dodge" : 44,
	"skill_name" : "颠倒阴阳",
	"lvl" : 15,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N双手双外推出，身体滴溜溜一转，划了一个大圈，使一招「夜战八方」，击向$n的$l",
	"force" : 180,
	"dodge" : 42,
	"skill_name" : "夜战八方",
	"lvl" : 20,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N一跃上前，使一招「风虎云龙」，右拳奋力向$n的$l打去",
	"force" : 200,
	"dodge" : 40,
	"skill_name" : "风虎云龙",
	"lvl" : 25,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N拳掌一分，斜身上步，一招「穿花绕树」，锤向$n的$l",
	"force" : 220,
	"dodge" : 38,
	"skill_name" : "穿花绕树",
	"lvl" : 30,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左脚前踏半步，右手使一招「倒打金钟」，指由下向$n的$l戳去",
	"force" : 240,
	"dodge" : 36,
	"skill_name" : "倒打金钟",
	"lvl" : 35,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N一招「指天划地」，小臂划了半个圆弧，双掌缓缓向外推出，向$n的$l挥去",
	"force" : 260,
	"dodge" : 34,
	"skill_name" : "指天划地",
	"lvl" : 40,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左手横挡，右掌一挥，右手使一招「燕子斜飞」，挥向$n的$l",
	"force" : 280,
	"dodge" : 32,
	"skill_name" : "燕子斜飞",
	"lvl" : 45,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左手虚攻，右手紧并,使一招「移花接木」，向$n的$l插去",
	"force" : 300,
	"dodge" : 30,
	"skill_name" : "移花接木",
	"lvl" : 50,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N趁势前扑，一招「魁星踢斗」拳中夹腿打向$n的$l",
	"force" : 320,
	"dodge" : 28,
	"skill_name" : "魁星踢斗",
	"lvl" : 55,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左手在$n面门一晃，右手一记「云横秦岭」击向$n的$l",
	"force" : 340,
	"dodge" : 26,
	"skill_name" : "云横秦岭",
	"lvl" : 60,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N施出「月移花影」，身形不住闪动，双手同时攻向$n的$l",
	"force" : 360,
	"dodge" : 24,
	"skill_name" : "月移花影",
	"lvl" : 65,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N稳扎马步，吐气开声，「中流砥柱」，双拳锤向$n的$l",
	"force" : 380,
	"dodge" : 22,
	"skill_name" : "中流砥柱",
	"lvl" : 70,
        "damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练百花错拳必须空手。\n");
if ((int)me->query_skill("honghua-shengong", 1) < 150)
		return notify_fail("你的红花神功火候不够，无法学百花错拳。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练百花错拳。\n");
	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

/* ----------------
mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}
-------------------*/

mapping query_action(object me, object weapon)
{
	int i, level;
  	level   = (int) me->query_skill("baihuacuo-quan",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
        return action[NewRandom(i, 5, level/5)];

}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练百花错拳。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -10);
	return 1;
}

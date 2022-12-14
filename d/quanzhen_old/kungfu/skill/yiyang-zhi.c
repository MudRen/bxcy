// yizhi-chan.c 一阳指
// By Lgg,1998.10

inherit SKILL;

mapping *action = ({
([	"action" : "$N右手四指屈回，小指猛地点向$n的胸口要穴，却是一招「秦塞通烟」",
	"force" : 60,
        "dodge" : 0,
        "parry" : 0,
	"damage": 10,
	"lvl" : 0,
	"skill_name" : "秦塞通烟",
	"damage_type" : "内伤"
]),
([	"action" : "$N右手小指划了个小弧线，接着划向$n的$l,是一招「冲波逆折」",
	"force" : 60,
        "dodge" : 0,
        "parry" : 0,
	"damage": 20,
	"lvl" : 10,
	"skill_name" : "冲波逆折",
	"damage_type" : "内伤"
]),
([	"action" : "$N转身回头，一式「太白横绝」，右手无名指反手疾点$n的$l",
	"force" : 120,
        "dodge" : 10,
        "parry" : 15,
	"damage": 30,
	"lvl" : 20,
	"skill_name" : "太白横绝",
        "damage_type" : "内伤"
]),
([	"action" : "$N使一式「黄鹤之飞」，右手无名指轻飘飘地点向$n的$l",
	"force" : 120,
        "dodge" : 10,
        "parry" : 15,
	"damage": 45,
	"lvl" : 30,
	"skill_name" : "黄鹤之飞",
        "damage_type" : "内伤"
]),
([	"action" : "$N使一招「地崩山摧」，右手中指连划数圈，罩向$n的上身数十大穴",
	"force" : 240,
        "dodge" : 20,
        "parry" : 20,
	"damage": 60,
	"lvl" : 40,
	"skill_name" : "地崩山摧",
        "damage_type" : "内伤"
]),
([	"action" : "$N使一招「青泥盘盘」，左手连划数圈，右手中指突然自圈中穿出，直刺$n的$l",
	"force" : 240,
        "dodge" : 20,
        "parry" : 20,
	"damage": 75,
	"lvl" : 50,
	"skill_name" : "青泥盘盘",
        "damage_type" : "内伤"
]),
([	"action" : "$N右手食指连点数点，合身刺向$n的背心大穴，却是一式「天梯石栈」",
	"force" : 240,
        "dodge" : 20,
        "parry" : 20,
	"damage": 95,
	"lvl" : 60,
	"skill_name" : "天梯石栈",
        "damage_type" : "内伤"
]),
([	"action" : "$N使「以手抚膺」右手食指虚虚点向$n的胸口，将$n胸口的所有大穴都笼罩在指力之下",
	"force" : 240,
        "dodge" : 20,
        "parry" : 20,
	"damage": 115,
	"lvl" : 70,
	"skill_name" : "以手抚膺",
        "damage_type" : "内伤"
]),
([	"action" : "$N右手拇指直立，遥遥对着$n一捺，一道劲气直奔$n而去，是一式「六龙回日」",
	"force" : 480,
        "dodge" : 40,
        "parry" : 30,
	"damage": 140,
	"lvl" : 80,
	"skill_name" : "六龙回日",
        "damage_type" : "内伤"
]),
([	"action" : "$N大喝一声，右手拇指按向$n，威不可当，却是一式「青天明月」",
	"force" : 480,
        "dodge" : 40,
        "parry" : 30,
	"damage": 145,
	"lvl" : 90,
	"skill_name" : "青天明月",
        "damage_type" : "内伤"
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_combine(string combo) { return combo=="haotian-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练一阳指必须空手。\n");
	if ((int)me->query_skill("xiantian-qigong", 1) < 20)
		return notify_fail("你的先天气功火候不够，无法学一阳指。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
	level   = (int) me->query_skill("yiyang-zhi",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 25)
		return notify_fail("你的内力不够练一阳指。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"yiyang-zhi/" + action;
}


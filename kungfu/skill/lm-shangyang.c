// lm-shangyang 六脉神剑之食指商阳剑

inherit SKILL;

mapping *action = ({
([	"action" : "$N一式「青松迎客」，和身而上，食指戳向$n的胸腹间",
	"force" : 60,
        "dodge" : -5,
        "parry" : -5,
	"damage": 10,
	"lvl" : 0,
	"weapon" : "无形剑气",
	"damage_type" : "刺伤"
]),
([	"action" : "$N左掌护胸，一式「佛光普照」，食指前后划了个半弧，猛地一甩，疾点$n的$l",
	"force" : 120,
        "dodge" : 5,
        "parry" : 10,
	"damage": 20,
	"lvl" : 10,
	"weapon" : "无形剑气",
        "damage_type" : "刺伤"
]),
([	"action" : "$N身形闪动，一式「普渡众生」，食指端部射出一道青气，射向$n的要穴",
	"force" : 180,
        "dodge" : 10,
        "parry" : 20,
	"damage": 30,
	"lvl" : 20,
	"weapon" : "无形剑气",
        "damage_type" : "刺伤"
]),
([	"action" : "$N盘膝跌坐，一式「菩提悟佛」，左手握拳托肘，右手食指直立，遥遥对着$n一捺",
	"force" : 240,
        "dodge" : 20,
        "parry" : 30,
	"damage": 40,
	"lvl" : 30,
	"weapon" : "无形剑气",
        "damage_type" : "刺伤"
]),
([	"action" : "$N忽地跃起，左掌抚胸，右手伸出食指，一式「轻点蒲柳」缓缓向$n头顶百汇穴点去",
	"force" : 300,
        "dodge" : 30,
        "parry" : 40,
	"damage": 50,
	"lvl" : 40,
	"weapon" : "无形剑气",
        "damage_type" : "刺伤"
]),
([	"action" : "$N一式「指点江山」，出指舒缓自如，对着$n一捺",
	"force" : 360,
	"dodge" : 40,
	"parry" : 50,
	"damage": 60,
	"lvl" : 50,
	"weapon" : "无形剑气",
	"damage_type" : "刺伤"
]),
([	"action" : "$N手臂颤动，有如轻风吹过，一招「微风轻拂」，拂遍$n全身诸穴",
	"force" : 420,
	"dodge" : 40,
	"parry" : 50,
	"damage": 70,
	"lvl" : 60,
	"weapon" : "无形剑气",
	"damage_type" : "刺伤"
]),
([	"action" : "$N倏忽之间欺近身去，一招「佛光轻逝」点向$n，一攻而退，灵动无比",
	"force" : 480,
        "dodge" : 60,
        "parry" : 60,
	"damage": 90,
	"lvl" : 80,
	"weapon" : "无形剑气",
        "damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练商阳剑必须空手。\n");
	if ((int)me->query("max_neili") < 150)
		return notify_fail("你的内力太弱，无法练商阳剑。\n");
	if ((int)me->query_skill("yiyang-zhi",1)<50)
		return notify_fail("你的一阳指力还不够！先练好一阳指吧。\n");
	if (me->query_skill("liumai-shenjian",1)>0)
		return notify_fail("你连六脉合并都能使用了，还想独练一剑？\n");
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
	level   = (int) me->query_skill("lm-shangyang", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[random(i)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("force") < 20)
		return notify_fail("你的内力不够了。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

int enable_factor() { return 20; }

int learn_bonus() { return 10; }

int practice_bonus() { return 10; }

int study_bonus() { return 10; }
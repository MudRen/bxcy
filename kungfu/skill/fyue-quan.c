//  黯然销魂掌
//  fyue-quan.c

#include <ansi.h>;
inherit SKILL;

mapping *action = ({
([      "action" : 
HIG"心惊肉跳\n\n"
"$N单臂负後，凝目远眺，脚下虚浮，胸前门户洞开，正当$n欺近之时，$N的小腹肌肉颤动，\n同时胸口向内一吸，倏地弹出"NOR,
	"force" : 240,
        "dodge" : 20,
        "parry" : 20,
	"damage": 150000,
	"lvl" : 5,
	"skill_name" : "心惊肉跳",
        "damage_type" : "瘀伤"
]),
([	"action" : 
HIC"杞人忧天\n\n"
"$N抬头向天，呼的一掌向自己头顶空空拍出，手掌斜下，掌力化成弧形，四散落下。力似穹庐，圆转广被"NOR,
	"force" : 280,
        "dodge" : 30,
        "parry" : 30,
	"damage": 250000,
	"lvl" : 15,
	"skill_name" : "杞人忧天",
        "damage_type" : "瘀伤"
]),
([	"action" : 
HIW"无中生有\n\n"
"$N手臂下垂，绝无半点防御姿式，待得$n攻到近肉寸许，突然间手足齐动，左掌右袖、双足头锤、\n连得胸背腰腹尽皆有招式发出，无一不足以伤敌"NOR,
	"force" : 320,
        "dodge" : 40,
        "parry" : 40,
	"damage": 400000,
	"lvl" : 30,
	"skill_name" : "无中生有",
        "damage_type" : "瘀伤"
]),
([	"action" : 
HIR"拖泥带水\n\n"
"$N右手云袖飘动，宛若流水，左掌却重滞之极，便似带着几千斤泥沙一般，缓缓向$n拍去"NOR,
	"force" : 360,
        "dodge" : 50,
        "parry" : 50,
	"damage": 500000,
	"lvl" : 40,
	"skill_name" : "拖泥带水",
        "damage_type" : "瘀伤"
]),
([	"action" : 
HIY"倒行逆施\n\n"
"$N突然头下脚上，倒过身子，拍出一掌，端得是出奇制胜"NOR,
	"force" : 400,
        "dodge" : 60,
        "parry" : 60,
	"damage": 650000,
	"lvl" : 55,
	"skill_name" : "倒行逆施",
        "damage_type" : "瘀伤"
]),
([	"action" : 
CYN"鹿死谁手\n\n"
"$N错步上前，招招抢先，以快打慢，一个转身已经转到了$n的身后，一掌拍向$n的大椎穴"NOR,
	"force" : 440,
        "dodge" : 70,
        "parry" : 70,
	"damage": 800000,
	"lvl" : 70,
	"skill_name" : "鹿死谁手",
        "damage_type" : "瘀伤"
]),
([	"action" : 
HIB"徘徊空谷\n\n"
"$N四下游走，看似漫无目的，突然飞身跃起，幻出千万掌影，将$n笼罩在内"NOR,
	"force" : 460,
        "dodge" : 80,
        "parry" : 80,
	"damage": 900000,
	"lvl" : 80,
	"skill_name" : "徘徊空谷",
        "damage_type" : "瘀伤"
]),
([	"action" : 
MAG"面无人色\n\n"
"$N脸上喜怒哀乐，怪状百出，$n一见之下顿时心神大乱，难以自制，手上的招式不由自主\n的慢了下来，$N趁机错步上前，一掌击向$n"NOR,
	"force" : 500,
        "dodge" : 90,
        "parry" : 90,
	"damage": 1000000,
	"lvl" : 100,
	"skill_name" : "面无人色",
        "damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry" ; }

int valid_combine(string combo) { return combo=="meinv-quanfa"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练黯然销魂掌必须空手。\n");
	if ((int)me->query_skill("zixia-shengong", 1) < 20)
		return notify_fail("你的紫霞神功火候不够，无法学混元掌。\n");
	if ((int)me->query("max_neili") < 300)
		return notify_fail("你的内力太弱，无法练黯然销魂掌。\n");
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
	level   = (int) me->query_skill("fyue-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 60)
		return notify_fail("你的内力不够练黯然销魂掌。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"fyue-quan/" + action;
}


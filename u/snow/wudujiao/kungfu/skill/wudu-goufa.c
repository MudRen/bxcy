// wudu-goufa.c 五毒钩法

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action":"\n$N手中$w一抖，一式「灵蛇吐信」，闪电般的疾刺向$n的$l",
	"force" : 160,
        "dodge" : 5,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "灵蛇吐信",
	"damage_type":	"刺伤"
]),
([	"action":"\n$N一式「柔丝轻系」，剑意绵绵不绝，化做一张无形的大网将$n困在当中",
	"force" : 240,
        "dodge" : 10,
	"damage": 25,
	"lvl" : 10,
	"skill_name" : "柔丝轻系",
	"damage_type":	"刺伤"
]),
([	"action":"\n$N一声阴笑，飞身纵起，一式「张牙舞爪」，手中$w狂舞，幻出千万条\n手臂，合身扑向$n",
	"force" : 280,
        "dodge" : 15,
	"damage": 40,
	"lvl" : 25,
	"skill_name" : "张牙舞爪",
	"damage_type":	"刺伤"
]),
([	"action":"$N足尖点地，身形一旋看似欲走，手中$w却倏的从腋下穿过，疾刺向$n的$l,\n好一式「天蝎藏针」",
	"force" : 320,
        "dodge" : 40,
	"damage": 50,
	"lvl" : 35,
	"skill_name" : "天蝎藏针",
	"damage_type":	"刺伤"
]),
([	"action":"$N脚步踉跄，身形忽的向前跌倒，一式「井底望月」，掌中$w自下而上直\n刺$n的小腹",
	"force" : 380,
        "dodge" : 40,
	"damage": 60,
	"lvl" : 50,
	"skill_name" : "井底望月",
	"damage_type":	"刺伤"
]),
([	"action":"$N身形一晃，一式「金蛇缠腕」，手中$w如附骨之蛆般无声无息地刺向$n\n的手腕",
	"force" : 420,
        "dodge" : 70,
	"damage": 80,
	"lvl" : 60,
	"skill_name" : "金蛇缠腕",
	"damage_type":	"刺伤"
]),
([	"action":"\n$N一声厉啸，身形冲天而起，一式「神蟾九变」，掌中$w如鬼魅般连刺\n$n全身九道大穴",
	"force" : 450,
        "dodge" : 80,
	"damage": 100,
	"lvl" : 70,
	"skill_name" : "神蟾九变",
	"damage_type":	"刺伤"
]),
([	"action":"$N深吸一口起，双手握钩，招演「万毒至尊」，$w尖端透出一条强劲的黑\n气，闪电般的袭向$n",
	"force" : 480,
        "dodge" : 45,
	"damage": 150,
	"lvl" : 80,
	"skill_name" : "万毒至尊",
	"damage_type":	"内伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("wudu-shengong", 1) < 20)
		return notify_fail("你的五毒神功火候太浅。\n");
	if ((int)me->query_skill("force", 1) < 20)
		return notify_fail("你的基本内功火候太浅。\n");
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
	level   = (int) me->query_skill("wudu-goufa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力不够练五毒钩法。\n");
	me->receive_damage("qi", 20);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
  if( random(damage_bonus/2) > victim->query_con() ) {
		victim->receive_wound("qi", damage_bonus/ 3 );
	}
  if ( victim->query("family/family_name")!= "五毒教" & me->query_skill("wudu-shengong",1)>40) {
	 switch( random(5) ) {
		case 0:
            victim->apply_condition("snake_poison", (me->query_skill("wudu-shengong"))/10 +
			victim->query_condition("snake_poison"));
			break;
		case 1:
            victim->apply_condition("zhizhu_poison", (me->query_skill("wudu-shengong"))/10 +
			victim->query_condition("zhizhu_poison"));
			break;
		case 2:
            victim->apply_condition("wugong_poison", (me->query_skill("wudu-shengong"))/10 +
			victim->query_condition("wugong_poison"));
			break;
		case 3:
            victim->apply_condition("xiezi_poison", (me->query_skill("wudu-shengong"))/10 +
			victim->query_condition("xiezi_poison"));
			break;
		case 4:
            victim->apply_condition("chanchu_poison", (me->query_skill("wudu-shengong"))/10 +
			victim->query_condition("chanchu_poison"));
			break;
	}
        return HIR "$n只觉得伤处一阵发麻，似乎中毒了。\n" NOR;
   }
}
string perform_action_file(string action)
{
	return __DIR__"wudu-goufa/" + action;
}

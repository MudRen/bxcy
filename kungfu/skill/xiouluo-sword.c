// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// axiou
// 南宫玲月
// 逍遥派第三代弟子
// 9129972
// 女性
// sword
// 修罗剑法





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N面目含笑，对这」$n轻轻一笑，手中$w一式「日月无光」，向$n颈部扫去。",
"force" :50,
"dodge" :20,
"damage_type": "刺伤",
"lvl" : 0,
"skill_name" : "日月无光"
]),
// ZHAOSHI :1

([
"action" :"$N运起修罗剑法剑法第二式「无幻无我」，$N顿时化为无数幻影，手中 $w向$n某部刺去。",
"force" :80,
"dodge" :10,
"damage_type": "刺伤",
"lvl" : 12,
"skill_name" : "无幻无我"
]),
 });
// ZHAOSHI :2
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword") return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("你的内力太弱，无法练"+"修罗剑法"+"。\n");
	return 1;
}
int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }
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
    level = (int)me->query_skill("xiouluo-sword",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword") return notify_fail("你使用的武器不对。\n");	if( (int)me->query("qi") < 25 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	if( (int)me->query("neili") < 3 )
		return notify_fail("你的内力不够了，休息一下再练吧。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -3);
	return 1;
} //total 34 lines!

// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// amd
// 枫
// 风之谷第零代掌门人
// 1000000035
// 男性
// cuff
// 风中漫步





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"y",
"force" :50,
"dodge" :20,
"damage_type": "瘀伤",
"lvl" : 0,
"skill_name" : "无双无对"
]),
 });
// ZHAOSHI :1
int valid_learn(object me)
{
//line number must be same!!!
//so it is done
        if( (int)me->query("max_neili") < 50 )
                return notify_fail("你的内力太弱，无法练"+"风中漫步"+"。\n");
        return 1;
}
int valid_enable(string usage) { return usage== "cuff" || usage=="parry"; }
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
    level = (int)me->query_skill("amdshi-cuff",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
        if( (int)me->query("qi") < 25 )
                return notify_fail("你的体力不够了，休息一下再练吧。\n");
        if( (int)me->query("neili") < 3 )
                return notify_fail("你的内力不够了，休息一下再练吧。\n");
        me->receive_damage("qi", 25);
        me->add("neili", -3);
        return 1;
} //total 34 lines!


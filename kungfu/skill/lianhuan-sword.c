// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// wyz
// [35m????[2;37;0m
// [31m????ɱ?ֲ?̫??[2;37;0m
// 50000000
// ????
// sword
// ??????





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$Nʹһ?С?"HIB"ɱ??ʽ??"NOR"???????????ɣ???????Ϣ??ת??$n?ı???????Ȼ????$n",
"force" :50,
"dodge" :20,
"damage_type": "????",
"lvl" : 0,
"skill_name" : "ɱ??ʽ"
]),
 });
// ZHAOSHI :1
int valid_learn(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword") return notify_fail("??ʹ?õ????????ԡ?\n");
        if( (int)me->query("max_neili") < 50 )
                return notify_fail("????????̫?????޷???"+"??????"+"??\n");
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
    level = (int)me->query_skill("lianhuan-sword",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
object weapon; if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword") return notify_fail("??ʹ?õ????????ԡ?\n");    if( (int)me->query("qi") < 25 )
                return notify_fail("?????????????ˣ???Ϣһ???????ɡ?\n");
        if( (int)me->query("neili") < 3 )
                return notify_fail("?????????????ˣ???Ϣһ???????ɡ?\n");
        me->receive_damage("qi", 25);
        me->add("neili", -3);
        return 1;
} //total 34 lines!


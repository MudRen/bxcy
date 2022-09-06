// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
// agan
// [1;33m°¢[1;37m¸É[2;37;0m
// ¹ÅÄ¹ÅÉµÚÎå´ú´«ÈË
// 60000053
// ÄÐÐÔ
// unarmed
// ÃÎÔÆ





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"¹ýÑÛÔÆÑÌÍùÊÂ´Ý¡£",
"force" :50,
"dodge" :10,
"damage_type": "ðöÉË",
"lvl" : 0,
"skill_name" : "¹ýÑÛÔÆÑÌ"
]),
 });
// ZHAOSHI :1
int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("Á·"+"ÃÎÔÆ"+"±ØÐë¿ÕÊÖ¡£\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎÞ·¨Á·"+"ÃÎÔÆ"+"¡£\n");
	return 1;
}
int valid_enable(string usage) { return usage== "unarmed" || usage=="parry"; }
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
    level = (int)me->query_skill("king-unarmed",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 25 )
		return notify_fail("ÄãµÄÌåÁ¦²»¹»ÁË£¬ÐÝÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
	if( (int)me->query("neili") < 3 )
		return notify_fail("ÄãµÄÄÚÁ¦²»¹»ÁË£¬ÐÝÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
	me->receive_damage("qi", 25);
	me->add("neili", -3);
	return 1;
} //total 34 lines!

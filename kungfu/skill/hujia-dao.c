//
//hujia-dao  ���ҵ���
// Designed by secret(����)
//

inherit SKILL;

mapping *action = ({
([      "action" : "$N���ᵶ��,ʹ��һ�С�˵һ��������$wֱ����$n���ֱ�",
        "skill_name" : "˵һ����",
        "force" : 120,
        "dodge" : 5,
        "parry" : 20,
        "lvl" : 0,
        "damage" : 30,
        "damage_type" : "����",
]),
([      "action" : "$N��ת���⣬һ�С���תǬ����������$w��Ȼ�õ�������$n����ǰ",
        "skill_name" : "��תǬ��",
        "force" : 160,
        "dodge" : 0,
        "parry" : 8,
        "lvl" : 15,
        "damage" : 40,
        "damage_type" : "����",
]),
([      "action" : "$Nһ���������ᵶ�棬$w�����ˡ����죬һ�С�����ɽ�ӡ������϶���ֱ��$n��ͷ��",
        "skill_name" : "����ɽ��",
        "force" : 220,
        "dodge" : 10,
        "parry" : 15,
        "lvl" : 30,
        "damage" : 50,
        "damage_type" : "����",
]),
([      "action" : "$N���һ�㣬���浶�ƣ�����������һ�С�������졹��$w�Ӱ��������$n",
        "skill_name" : "�������",
        "force" : 240,
        "dodge" : 10,
        "parry" : 20,
        "lvl" : 45,
        "damage" : 50,
        "damage_type" : "����",
]),
([      "action" : "$Nһ����Х���������ֶ�������$n������������ϣ������һ������\nն��$n����������Ȼ��һ�С����������",
        "skill_name" : "�������",
        "force" : 270,
        "dodge" : 20,
        "parry" : 15,
        "lvl" : 60,
        "damage" : 60,
        "damage_type" : "����",
]),
([      "action" : "$Nʹ����������ѩ����һ����ʹ���ܲ�͸������ն������ʮ�ŵ�������$n����Ҫ��",
        "skill_name" : "������ѩ",
        "force" : 300,
        "dodge" : 35,
        "parry" : 50,
        "lvl" : 40,
        "damage" : 60,
        "damage_type" : "����",
]),
([      "action" : "$Nʹһʽ��ǧɽ���͡�������һ����һ�������಻�ϵ�ֱ��$nѹȥ  ",
        "skill_name" : "ǧɽ����",
        "force" : 340,
        "dodge" : 40,
        "parry" : 70,
        "lvl" : 80,
        "damage" : 80,
        "damage_type" : "����",
]),

});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }	

//int valid_combine(string combo) { return combo=="mingwang-jian"; }

int valid_learn(object me)
{
if ((int)me->query_skill("blade", 1) >= 500)    	
		return 1;
else if ((int)me->query_skill("blade", 1) < 500)        	
		return notify_fail("��Ļ�������̫���ˣ������˺��ҵ�����\n");
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
	if (random(me->query_skill("blade")) > 80 &&
	    me->query_skill("force") > 100 &&
	    me->query("neili") > 500 &&
(string)weapon->query("id") == "chuangwang baodao" ) {	
		me->add("neili", -100);
		return ([
		"action": "$Nʹ��һ�С���ѩ�׷ס���$w�����򳤰�â���������䣬ֱ����$n",
		"damage": 400,
		"force" : 200,
		"damage_type": "����"]);
	}
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("������������������˺��ҵ�����\n");
	me->receive_damage("qi", 30);
	return 1;
}

string perform_action_file(string action){    return __DIR__"hujia-dao/" + action;}	

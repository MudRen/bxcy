// liancheng-jian.c ���ǽ���

inherit SKILL;

mapping *action = ({
([	"action":"$Nʹһʽ���º躣������������$w����΢�񣬻ó�һ���������$n��$l",
	"force" : 120,
            "dodge" : 0,
	"damage": 30,
	"lvl" : 0,
	"skill_name" : "�º躣����",
	"damage_type":	"����"
]),
([	"action":"$N������ǰ��ʹ�������겻�ҹˡ�������$w����һ����������$n��$l",
	"force" : 140,
            "dodge" : 10,
	"damage": 40,
	"lvl" : 9,
	"skill_name" : "���겻�ҹ�",
	"damage_type":	"����"
]),
([	"action":"$N����$wһ����һ�С������մ��졹��ббһ�������ó�������$n��$l",
	"force" : 160,
           "dodge" : 5,
	"damage": 50,
	"lvl" : 18,
	"skill_name" : "�����մ���",
	"damage_type":	"����"
]),
([	"action":"$N���н����ॳ���һ����һʽ����������������һ���������$n��$l",
	"force" : 180,
            "dodge" : 10,
	"damage": 100,
	"lvl" : 27,
	"skill_name" : "����������",
	"damage_type":	"����"
]),
([	"action":"$Nһʽ����������·��������$w�������������ʹ$n�Ѷ���ʵ���޿ɶ��",
	"force" : 220,
            "dodge" : 15,
	"damage": 100,
	"lvl" : 36,
	"skill_name" : "��������·",
	"damage_type":	"����"
]),
([	"action":"$N����$wбָ���죬��â���£�һʽ��Ǽ��Թ����������׼$n��$lбб����",
	"force" : 260,
            "dodge" : 5,
	"damage": 120,
	"lvl" : 44,
	"skill_name" : "Ǽ��Թ����",
	"damage_type":	"����"
]),
([	"action":"$Nһʽ����������š������󼱶�������������⣬����$n��$l",
	"force" : 320,
            "dodge" : 5,
	"damage": 125,
	"lvl" : 52,
	"skill_name" : "���������",
	"damage_type":	"����"
]),
([	"action":"$Nһʽ��ң����ǰ������$w��ն�������缲�������$n���ؿ�",
	"force" : 380,
            "dodge" : 5,
	"damage": 140,
	"lvl" : 60,
	"skill_name" : "ң����ǰ��",
	"damage_type":	"����"
]),
([	"action":"$Nһʽ��������ǧ�ߡ���$wͻȻ���������һƬ���Χ��$nȫ��",
	"force" : 380,
            "dodge" : 5,
	"damage": 150,
	"lvl" : 60,
	"skill_name" : "������ǧ��",
	"damage_type":	"����"
])
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me) { return 1; }

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
	level   = (int) me->query_skill("liancheng-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("����������������ǽ�����\n");
	me->receive_damage("qi", 25);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"liancheng-jian/" + action;
}
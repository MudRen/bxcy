// huifeng-jian.c �ط������
// create by host nov,28

inherit SKILL;

mapping *action = ({
([	"action" : "$N����ƮȻ������һʽ�����Ϯ�¡���$w����һ���׹⣬�ɿ�Ĵ���$n��$l",
	"force" : 100,
	"dodge" : 10,
        "parry" : 5,
	"damage" : 35,
        "lvl" : 0,
	"damage_type" : "����"
]),
([	"action" : "$N��Ưѩ���ơ������ֽ���,����$w����佣������Ȼ����ֱ��������$n��$l",
	"force" : 160,
	"dodge" : 15,
        "parry" : 5,
	"damage" : 45,
        "lvl" : 10,
	"damage_type" : "����"
]),
([	"action" : "$Nһ����Х��һʽ��ǧ�徹�㡹������$w��ʱ����������â������$n��ȫ��",
	"force" : 320,
	"dodge" : 20,
        "parry" : 10,
	"damage" : 55,
        "lvl" : 20,
	"damage_type" : "����"
]),
([	"action" : "$N����һ������˫�ֽ���$w��ʹ��һʽ���������ڡ�������һ�㼲��$n��$l",
	"force" : 380,
	"dodge" : 25,
        "parry" : 10,
	"damage" : 65,
        "lvl" : 30,
	"damage_type" : "����"
]),
([	"action" : "$N���潣�У�һ�С����������������л���һ����̣�$w����$n��$l",
	"force" : 420,
	"dodge" : 30,
        "parry" : 10,
	"damage" : 75,
        "lvl" : 40,
	"damage_type" : "����"
]),
([	"action" : "$N����һ���εض���һ�С�������ɳ����$w���϶��»���һ����,��$n��$l��ȥ",
	"force" : 480,
	"dodge" : 35,
        "parry" : 15,
	"damage" : 90,
        "lvl" : 60,
	"damage_type" : "����"
]),
([	"action" : "$N�����˲���һ�С��������Ρ���$w΢�����������йǽ�����쫷�����$nȫ��",
	"force" : 540,
	"dodge" : 40,
        "parry" : 20,
	"damage" : 105,
        "lvl" : 80,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С���غ��衹������$w�������죬�Ի���Ծ�����缲�������$n��$l",
	"force" : 600,
	"dodge" : 45,
        "parry" : 25,
	"damage" : 120,
        "lvl" : 100,
	"damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");

	if ((int)me->query_skill("linji-zhuang", 1) < 20)
		return notify_fail("��ġ��ټ�ʮ��ׯ�����̫ǳ��\n");

	if ((int)me->query_skill("force", 1) < 20)
		return notify_fail("��Ļ����ڹ����̫ǳ��\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("huifeng-jian",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
	object weapon;

	if ( !me->query_skill("linji-zhuang",1) )
		return notify_fail("�����ط������������Ҫ�С��ټ�ʮ��ׯ�������ӡ�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if ((int)me->query("qi") < 50)
		return notify_fail("����������������ط����������\n");

	me->receive_damage("qi", 30);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"huifeng-jian/" + action;
}

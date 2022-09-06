// jinding-zhang.c ������
// create by host nov,27

inherit SKILL;

mapping *action = ({
([	"action" : "$Nʹһʽ��������̩����˫���絶��󿪴�ϣ��������$n��$l",
	"force" : 50,
        "dodge" : 5,
        "parry" : 10,
	"damage": 20,
	"lvl" : 0,
	"skill_name" : "������̩",
        "damage_type" : "����"
]),
([	"action" : "$N����ƮȻ�ƶ���һʽ���������项���ó�������Ӱ����$n��ȫ��",
	"force" : 100,
        "dodge" : 30,
        "parry" : 15,
	"damage": 30,
	"lvl" : 10,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N����ȫ����,ʹһʽ������ơ���˫��һǰһ��, ������$n��$l��ȥ",
	"force" : 150,
        "dodge" : 30,
        "parry" : 20,
	"damage": 40,
	"lvl" : 20,
	"skill_name" : "�����",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ��������ɳ����������������������צ�Σ���$n�����ȥ",
	"force" : 200,
        "dodge" : 15,
        "parry" : 20,
	"damage": 50,
	"lvl" : 30,
	"skill_name" : "������ɳ",
        "damage_type" : "����"
]),
([	"action" : "$N���ΰεض���ʹ��һʽ���׶���������˫�ƴ��ŷ����������϶��µĻ���$n��$l",
	"force" : 250,
        "dodge" : 30,
        "parry" : 20,
	"damage": 65,
	"lvl" : 50,
	"skill_name" : "�׶�����",
        "damage_type" : "����"
]),
([	"action" : "$N΢΢һЦ��ʹ��һʽ���𶥷�⡹�����лó�������,ֱ����$n��$l",
	"force" : 280,
        "dodge" : 10,
        "parry" : 40,
	"damage": 75,
	"lvl" : 70,
	"skill_name" : "�𶥷��",
        "damage_type" : "����"
]),
([	"action" : "$N����һ����ţ�ʹһʽ�����Ľ�ħ����˫��Ю��籩ѩ֮�ƣ��͵�����$n��$l",
	"force" : 320,
        "dodge" : 40,
        "parry" : 5,
	"damage": 95,
	"lvl" : 90,
	"skill_name" : "���Ľ�ħ",
        "damage_type" : "����"
]),
([	"action" : "$Nһ�С�����˻ġ���������Ȼ����һ���׹�,������$n����˷�,����$nȫ��",
	"force" : 380,
        "dodge" : 50,
        "parry" : 20,
	"damage": 105,
	"lvl" : 110,
	"skill_name" : "����˻�",
        "damage_type" : "����"
]),
});

int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="parry" ;
}
int valid_combine(string combo) { return combo=="tiangang-zhi"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
          return notify_fail("�������Ʊ�����֡�\n");
        if ((int)me->query_skill("linji-zhuang", 1) < 20)
           return notify_fail("��ġ��ټ�ʮ��ׯ����򲻹����޷�ѧ�����ơ�\n");
/*        if ((int)me->query_skill("yugalism", 1) < 20)
           return notify_fail("��ġ�������͹������̫ǳ��\n"); */
	if ((int)me->query("max_neili") < 100)
            return notify_fail("�������̫�����޷��������ơ�\n");
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
        level   = (int) me->query_skill("jinding-zhang", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");

	if ((int)me->query("neili") < 40)
                return notify_fail("������������������ơ�\n");

	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}


string perform_action_file(string action)
{
        return __DIR__"jinding-zhang/"+ action;
}

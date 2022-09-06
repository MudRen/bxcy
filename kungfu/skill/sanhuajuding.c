// SKILL sanhuajuding.c �����۶���

inherit SKILL;
#include <ansi.h>
mapping *action = ({
([	"action" : "$Nһ��"HIW" �����ʽ "NOR"������бб������$n��$l",
	"force" : 150,
	"dodge" : 20,
	"damage" : 10,
	"lvl" : 0,
	"skill_name" : "�����ʽ",
	"damage_type" : "����"
]),
([	"action" : "$N˫����ƮƮ������$n��ͻȻ�����Ϲ���һ��"HIW" ����̧�� "NOR"����$n��$l",
	"force" : 200,
	"dodge" : 10,
	"damage" : 30,
	"lvl" : 20,
	"skill_name" : "����̧��",
	"damage_type" : "����"
]),
([	"action" : "$N�����һ��"RED" ��Գ�׹� "NOR"��˫�ƻû�һƬ��Ӱ����$n�������ڡ�",
	"force" : 250,
	"dodge" : 30,
	"damage" : 35,
	"lvl" : 30,
	"skill_name" : "��Գ�׹�",
	"damage_type" : "����"
]),

([	"action" : "$Nһ��"RED" ������ "NOR"��˫�ַ׷ɣ�������ʽ��˫�ַ���$nȫ�������Ѩ",
	"force" : 300,
	"dodge" : 25,
	"damage" : 50,
	"lvl" : 40,
	"skill_name" : "������",
    "damage_type" : "����"
]),
([	"action" : "$Nһ��"HIY" ��ĥ���� "NOR"���й�ֱ����ֻ��һƬ��Ӱ����$n",
	"force" : 350,
	"dodge" : 20,
	"damage" : 60,
	"lvl" : 50,
	"skill_name" : "��ĥ����",
	"damage_type" : "����"
]),

([	"action" : "$N˫��ƽ�ӣ�һ��"HIY" ��Ƿ���� "NOR"����$n,��$n�޴��ɶ�.",
	"force" : 400,
	"dodge" : 25,
	"damage" : 70,
	"lvl" : 60,
	"skill_name" : "��Ƿ����",
            "damage_type" : "����"
]),
([	"action" : "$N�������࣬ͷ�½��ϣ�һ��"HIR" ��ϼ���� "NOR"����$n",
	"force" : 450,
	"dodge" : 30,
	"damage" : 80,
	"lvl" : 70,
	"skill_name" : "��ϼ����",
	"damage_type" : "����"
]),

([	"action" : "$N������Σ�����һ��"HIM" �ϵ紩�� "NOR"����$n����գ���δʹ����;�ж�����Եȴ����$n���Ҿ���",
	"force" : 500,
	"dodge" : 30,
	"damage" : 90,
	"lvl" : 80,
	"skill_name" : "�ϵ紩��",
           "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_combine(string combo) { return combo=="sanhuajuding"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������۶��Ʊ�����֡�\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷��������۶��ơ�\n");
	if ((int)me->query_skill("xiantian-gong",1)< 20)
		return notify_fail("�����������Ϊ�������޷��������۶��ơ�\n");	
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("sanhuajuding",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("������������������۶��ơ�\n");
	me->receive_damage("qi", 25);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"sanhuajuding/" + action;
}

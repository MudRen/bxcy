// lm-guanchong.c ������֮��������ָ�س彣

inherit SKILL;

mapping *action = ({
([	"action" : "$Nһʽ����̨���Ρ��������������䣬��������ָ����$n���ظ���",
	"force" : 60,
        "dodge" : -5,
        "parry" : -5,
	"damage": 10,
	"lvl" : 0,
	"weapon" : "���ν���",
	"damage_type" : "����"
]),
([	"action" : "$N���ƻ��أ�һʽ����Ϫˮ�䡹������ָ���˸��뻡���͵�һ˦������$n��$l",
	"force" : 120,
        "dodge" : 5,
        "parry" : 10,
	"damage": 20,
	"lvl" : 10,
	"weapon" : "���ν���",
        "damage_type" : "����"
]),
([	"action" : "$N����������һʽ����ɽ����������ָ�˲����һ�ɽ�����ֱ��$n��ҪѨ",
	"force" : 180,
        "dodge" : 10,
        "parry" : 20,
	"damage": 30,
	"lvl" : 20,
	"weapon" : "���ν���",
        "damage_type" : "����"
]),
([	"action" : "$N��ϥ������һʽ��ƽ����������������ȭ���⣬��������ָңң����$nһ��",
	"force" : 240,
        "dodge" : 20,
        "parry" : 30,
	"damage": 40,
	"lvl" : 30,
	"weapon" : "���ν���",
        "damage_type" : "����"
]),
([	"action" : "$N����Ծ�����Ƹ��أ������������ָ��һʽ����ˮ��ʯ������"+
		"һ�ֲ���\n�ֵ������ƻ�����$nͷ���ٻ�Ѩ��ȥ",
	"force" : 300,
        "dodge" : 30,
        "parry" : 40,
	"damage": 50,
	"lvl" : 40,
	"weapon" : "���ν���",
        "damage_type" : "����"
]),
([	"action" : "$Nһʽ��ƽˮ��ʯ������ָ�滺���磬����$nһ��",
	"force" : 360,
	"dodge" : 40,
	"parry" : 50,
	"damage": 60,
	"lvl" : 50,
	"weapon" : "���ν���",
	"damage_type" : "����"
]),
([	"action" : "$N�ֱ۲�����������紵����һ�С���ˮƮ����������$nȫ����Ѩ",
	"force" : 420,
	"dodge" : 40,
	"parry" : 50,
	"damage": 70,
	"lvl" : 60,
	"weapon" : "���ν���",
	"damage_type" : "����"
]),
([	"action" : "$Nٿ��֮���۽���ȥ��һ�С���ˮ��ľ������$n��һ������",
	"force" : 480,
        "dodge" : 60,
        "parry" : 60,
	"damage": 90,
	"lvl" : 80,
	"weapon" : "���ν���",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }	

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���س彣������֡�\n");
	if ((int)me->query("max_neili") < 150)
		return notify_fail("�������̫�����޷����س彣��\n");
	if ((int)me->query_skill("yiyang-zhi",1)<50)
		return notify_fail("���һ��ָ����������������һ��ָ�ɡ�\n");
	if (me->query_skill("liumai-shenjian",1)>0)
		return notify_fail("���������ϲ�����ʹ���ˣ��������һ����\n");
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
	level   = (int) me->query_skill("lm-guanchong", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[random(i)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("force") < 20)
		return notify_fail("������������ˡ�\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

int enable_factor() { return 20; }

int learn_bonus() { return 10; }

int practice_bonus() { return 10; }

int study_bonus() { return 10; }


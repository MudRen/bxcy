// yizhi-chan.c һ��ָ
// By Lgg,1998.10

inherit SKILL;

mapping *action = ({
([	"action" : "$N������ָ���أ�Сָ�͵ص���$n���ؿ�ҪѨ��ȴ��һ�С�����ͨ�̡�",
	"force" : 60,
        "dodge" : 0,
        "parry" : 0,
	"damage": 10,
	"lvl" : 0,
	"skill_name" : "����ͨ��",
	"damage_type" : "����"
]),
([	"action" : "$N����Сָ���˸�С���ߣ����Ż���$n��$l,��һ�С��岨���ۡ�",
	"force" : 60,
        "dodge" : 0,
        "parry" : 0,
	"damage": 20,
	"lvl" : 10,
	"skill_name" : "�岨����",
	"damage_type" : "����"
]),
([	"action" : "$Nת���ͷ��һʽ��̫�׺��������������ָ���ּ���$n��$l",
	"force" : 120,
        "dodge" : 10,
        "parry" : 15,
	"damage": 30,
	"lvl" : 20,
	"skill_name" : "̫�׺��",
        "damage_type" : "����"
]),
([	"action" : "$Nʹһʽ���ƺ�֮�ɡ�����������ָ��ƮƮ�ص���$n��$l",
	"force" : 120,
        "dodge" : 10,
        "parry" : 15,
	"damage": 45,
	"lvl" : 30,
	"skill_name" : "�ƺ�֮��",
        "damage_type" : "����"
]),
([	"action" : "$Nʹһ�С��ر�ɽ�ݡ���������ָ������Ȧ������$n��������ʮ��Ѩ",
	"force" : 240,
        "dodge" : 20,
        "parry" : 20,
	"damage": 60,
	"lvl" : 40,
	"skill_name" : "�ر�ɽ��",
        "damage_type" : "����"
]),
([	"action" : "$Nʹһ�С��������̡�������������Ȧ��������ָͻȻ��Ȧ�д�����ֱ��$n��$l",
	"force" : 240,
        "dodge" : 20,
        "parry" : 20,
	"damage": 75,
	"lvl" : 50,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N����ʳָ�������㣬�������$n�ı��Ĵ�Ѩ��ȴ��һʽ������ʯջ��",
	"force" : 240,
        "dodge" : 20,
        "parry" : 20,
	"damage": 95,
	"lvl" : 60,
	"skill_name" : "����ʯջ",
        "damage_type" : "����"
]),
([	"action" : "$Nʹ�����ָ��ߡ�����ʳָ�������$n���ؿڣ���$n�ؿڵ����д�Ѩ��������ָ��֮��",
	"force" : 240,
        "dodge" : 20,
        "parry" : 20,
	"damage": 115,
	"lvl" : 70,
	"skill_name" : "���ָ���",
        "damage_type" : "����"
]),
([	"action" : "$N����Ĵֱָ����ңң����$nһ�࣬һ������ֱ��$n��ȥ����һʽ���������ա�",
	"force" : 480,
        "dodge" : 40,
        "parry" : 30,
	"damage": 140,
	"lvl" : 80,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N���һ��������Ĵָ����$n�������ɵ���ȴ��һʽ���������¡�",
	"force" : 480,
        "dodge" : 40,
        "parry" : 30,
	"damage": 145,
	"lvl" : 90,
	"skill_name" : "��������",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_combine(string combo) { return combo=="haotian-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��һ��ָ������֡�\n");
	if ((int)me->query_skill("xiantian-qigong", 1) < 20)
		return notify_fail("�������������򲻹����޷�ѧһ��ָ��\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
	level   = (int) me->query_skill("yiyang-zhi",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 25)
		return notify_fail("�������������һ��ָ��\n");
	me->receive_damage("qi", 25);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"yiyang-zhi/" + action;
}


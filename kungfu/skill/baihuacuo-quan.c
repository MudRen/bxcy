// baihuacuo-quan.c �ٻ���ȭ
// by main 10/98
inherit SKILL;

mapping *action = ({
([	"action" : "$N���һ�ӣ�ʹһ�С���ת���ơ���˫�����������$n",
	"force" : 100,
	"dodge" : 50,
	"skill_name" : "��ת����",
	"lvl" : 0,
	"damage_type" : "����"
]),
([	"action" : "$Nʹһ�С����ƶϷ塹�����ֳ��ƣ���סǰ�أ����ֳ�ȭ������$n��$l",
	"force" : 120,
	"dodge" : 48,
	"skill_name" : "���ƶϷ�",
	"lvl" : 5,
	"damage_type" : "����"
]),
([	"action" : "$N������������ֽ��գ�ʹһ�С��ֻ���������ֱ���й�,��$n��$l��ȥ",
	"force" : 140,
	"dodge" : 46,
	"skill_name" : "�ֻ�����",
	"lvl" : 10,
        "damage_type" : "����"
]),
([	"action" : "$N˫��һ���������øգ��������ᣬʹһ�С��ߵ����������ֻ�$n��ǰ�غ�$l",
	"force" : 160,
	"dodge" : 44,
	"skill_name" : "�ߵ�����",
	"lvl" : 15,
        "damage_type" : "����"
]),
([	"action" : "$N˫��˫���Ƴ������������һת������һ����Ȧ��ʹһ�С�ҹս�˷���������$n��$l",
	"force" : 180,
	"dodge" : 42,
	"skill_name" : "ҹս�˷�",
	"lvl" : 20,
        "damage_type" : "����"
]),
([	"action" : "$NһԾ��ǰ��ʹһ�С��绢����������ȭ������$n��$l��ȥ",
	"force" : 200,
	"dodge" : 40,
	"skill_name" : "�绢����",
	"lvl" : 25,
        "damage_type" : "����"
]),
([	"action" : "$Nȭ��һ�֣�б���ϲ���һ�С�����������������$n��$l",
	"force" : 220,
	"dodge" : 38,
	"skill_name" : "��������",
	"lvl" : 30,
        "damage_type" : "����"
]),
([	"action" : "$N���ǰ̤�벽������ʹһ�С�������ӡ���ָ������$n��$l��ȥ",
	"force" : 240,
	"dodge" : 36,
	"skill_name" : "�������",
	"lvl" : 35,
        "damage_type" : "����"
]),
([	"action" : "$Nһ�С�ָ�컮�ء���С�ۻ��˰��Բ����˫�ƻ��������Ƴ�����$n��$l��ȥ",
	"force" : 260,
	"dodge" : 34,
	"skill_name" : "ָ�컮��",
	"lvl" : 40,
        "damage_type" : "����"
]),
([	"action" : "$N���ֺᵲ������һ�ӣ�����ʹһ�С�����б�ɡ�������$n��$l",
	"force" : 280,
	"dodge" : 32,
	"skill_name" : "����б��",
	"lvl" : 45,
        "damage_type" : "����"
]),
([	"action" : "$N�����鹥�����ֽ���,ʹһ�С��ƻ���ľ������$n��$l��ȥ",
	"force" : 300,
	"dodge" : 30,
	"skill_name" : "�ƻ���ľ",
	"lvl" : 50,
        "damage_type" : "����"
]),
([	"action" : "$N����ǰ�ˣ�һ�С������߶���ȭ�м��ȴ���$n��$l",
	"force" : 320,
	"dodge" : 28,
	"skill_name" : "�����߶�",
	"lvl" : 55,
        "damage_type" : "����"
]),
([	"action" : "$N������$n����һ�Σ�����һ�ǡ��ƺ����롹����$n��$l",
	"force" : 340,
	"dodge" : 26,
	"skill_name" : "�ƺ�����",
	"lvl" : 60,
        "damage_type" : "����"
]),
([	"action" : "$Nʩ�������ƻ�Ӱ�������β�ס������˫��ͬʱ����$n��$l",
	"force" : 360,
	"dodge" : 24,
	"skill_name" : "���ƻ�Ӱ",
	"lvl" : 65,
        "damage_type" : "����"
]),
([	"action" : "$N��������������������������������˫ȭ����$n��$l",
	"force" : 380,
	"dodge" : 22,
	"skill_name" : "��������",
	"lvl" : 70,
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���ٻ���ȭ������֡�\n");
if ((int)me->query_skill("honghua-shengong", 1) < 150)
		return notify_fail("��ĺ컨�񹦻�򲻹����޷�ѧ�ٻ���ȭ��\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷����ٻ���ȭ��\n");
	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

/* ----------------
mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}
-------------------*/

mapping query_action(object me, object weapon)
{
	int i, level;
  	level   = (int) me->query_skill("baihuacuo-quan",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
        return action[NewRandom(i, 5, level/5)];

}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("��������������ٻ���ȭ��\n");
	me->receive_damage("qi", 25);
	me->add("neili", -10);
	return 1;
}

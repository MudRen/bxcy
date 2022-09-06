// /kungfu/skill/cuixin-zhang.c
// adx 23:20 99-2-11
inherit SKILL;

mapping *action = ({
([	"action" : "$Nʹһ�С�������ӿ����˫��Ʈ�Ʋ�������$n$l",
	"force" : 160,
	"dodge" : 2,
	"skill_name" : "������ӿ",
	"lvl" : 10,
        "damage_type" : "����"
]),
([	"action" : "$Nٿ������$n��ǰ��һ�С��ﲨ���ˡ�ֱ��$n��$l",
	"force" : 240,
	"dodge" : 0,
	"skill_name" : "�ﲨ����",
	"lvl" : 30,
        "damage_type" : "����"
]),
([	"action" : "$N������$nһת��һ�С����ײ�����$n$l��������",
	"force" : 320,
	"dodge" : -2,
	"skill_name" : "���ײ���",
	"lvl" : 50,
        "damage_type" : "����"
]),
([	"action" : "$N���ΰ����ڰ��һ�С����羪�ס������ͻ�$n��$l",
	"force" : 400,
	"dodge" : -4,
	"skill_name" : "���羪��",
	"lvl" : 90,
        "damage_type" : "����"
]),
([	"action" : "$Nʹһ�С���ɳ��Ӱ������������ֱ��$n��$l",
	"force" : 500,
	"dodge" : -6,
	"skill_name" : "��ɳ��Ӱ",
	"lvl" : 120,
        "damage_type" : "����"
]),
([	"action" : "$Nһ�����ʹ�������Ǵ��ġ����ó�������Ӱ�����Ʋ���$n��$l",
	"force" : 620,
	"dodge" : -8,
	"skill_name" : "���Ǵ���",
	"lvl" : 150,
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������Ʊ�����֡�\n");
	if ((int)me->query_skill("bibo-shengong", 1) < 20)
		return notify_fail("��ı̲��񹦻�򲻹����޷�ѧ�����ơ�\n");
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
    level   = (int) me->query_skill("cuixin-zhang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 5, level/5)];

}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("������������������ơ�\n");
	me->receive_damage("qi", 25);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"cuixin-zhang/" + action;
}

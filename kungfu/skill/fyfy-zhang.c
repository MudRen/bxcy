// fyfy-zhang.c�����Ƹ����ƣ�

inherit SKILL;

mapping *action = ({
([      "action" : "$Nʹһ�С�������⡹��˫��Э��������������$n��$l��",
        "force" : 150,
        "dodge" : 30,
        "skill_name" : "�������",
        "damage_type" : "����"
]),
([      "action" : "$N�����鰴$n��$l�����ġ�����ͻ�䡹������������$n��$l��ȥ��",
        "force" : 250,
        "dodge" : 25,
        "skill_name" : "����ͻ��",
        "damage_type" : "����"
]),
([      "action" : "$N˫����ȭ����ǰ��ֱ𻮻���һ�С��׵罹��������$n�����ߡ�",
        "force" : 300,
        "dodge" : 50,
        "skill_name" : "�׵罹��",
        "damage_type" : "����"
]),
([      "action" : "$N�����黮�����ֵ��ơ�����Ϊ�ơ�����$n��$n��",
        "force" : 320,
        "dodge" : 30,
        "skill_name" : "����Ϊ��",
        "damage_type" : "����"
]),
([      "action" : "$Nʩ��������Ϊ�꡹��˫������һѹ����������������$n��$l��",
        "force" : 400,
        "dodge" : 45,
        "skill_name" : "����Ϊ��",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
        if ((int)me->query_skill("zhenfeng-xinfa", 1) < 10)
                return notify_fail("��ġ�����ķ�����򲻹����޷�ѧ�����Ƹ����ơ���\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�������Ƹ����ơ�������֡�\n");
        if ((int)me->query("qi") < 30)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("������������������Ƹ����ơ���\n");
        me->receive_damage("qi", 25);
        me->add("neili", -10);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"fyfy-zhang/" + action;
}


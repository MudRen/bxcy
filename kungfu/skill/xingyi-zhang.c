// xingyi-zhang.c ��ת������

inherit SKILL;

mapping *action = ({
([      "action" : "$Nʹһ�С����α�Ӱ����˫�ֻ��˸���Ȧ������$n��$l",
        "force" : 160,
        "dodge" : 10,
        "lvl" : 0,
        "damage" : 14,
        "skill_name" : "���α�Ӱ",
        "damage_type" : "����"
]),
([      "action" : "$N�����鰴������ʹһ�С����ǵ�㡹����$n��$l��ȥ",
        "force" : 250,
        "dodge" : 5,
        "lvl" : 15,
        "damage" : 30,
        "skill_name" : "���ǵ��",
        "damage_type" : "����"
]),
([      "action" : "$N˫����ȭ����ǰ��󻮻���һ�С������Ƕ�������$n��$l",
        "force" : 340,
        "dodge" : 10,
        "lvl" : 30,
        "damage" : 50,
        "skill_name" : "�����Ƕ�",
        "damage_type" : "����"
]),
([      "action" : "$N�����黮������һ�ǡ��嶷�ǳ�������$n������",
        "force" : 430,
        "dodge" : 15,
        "lvl" : 45,
        "damage" : 70,
        "skill_name" : "�嶷�ǳ�",
        "damage_type" : "����"
]),
([      "action" : "$Nʩ�����������ǡ������ֻ���$n��$l�����ֹ���$n���ɲ�",
        "force" : 520,
        "dodge" : 10,
        "lvl" : 60,
        "damage" : 90,
        "skill_name" : "��������",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }
int valid_combine(string combo) { return combo=="canhe-zhi"; }
int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����ת�����Ʊ�����֡�\n");
        if ((int)me->query_skill("shenyuan-gong", 1) < 15)
                return notify_fail("�����Ԫ����򲻹����޷�ѧ��ת�����ơ�\n");
        if ((int)me->query("max_neili") < 50)
                return notify_fail("�������̫�����޷�����ת�����ơ�\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
          if ((int)me->query("jing") < 30)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("���������������ת�����ơ�\n");
         me->receive_damage("jing", 25);
        me->add("neili", -7);
        return 1;
}

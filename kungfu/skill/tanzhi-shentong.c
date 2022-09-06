// tanzhi.c ��ָ��ͨ
inherit SKILL;
mapping *action = ({
([  "action" : "$N��ָ���˸���Ȧ��һʽ�������ѵء����϶��»���$n��ȫ��",
    "force" : 320,
    "dodge" : -5,
    "damage": 35,
    "lvl" : 20,
    "skill_name" : "�����ѵ�",
        "damage_type" : "����"
]),
([  "action" : "$N���ƻ��أ�һ�С��������ơ�����ָ��������ָ��$n�Ķ�ͷ",
    "force" : 280,
    "dodge" : 20,
    "lvl" : 0,
    "skill_name" : "��������",
    "damage_type" : "����"
]),
([  "action" : "$N˫�������һʽ��ǧ����ָ������ָ��$n��$l",
    "force" : 190,
    "dodge" : 15,
    "lvl" : 0,
    "skill_name" : "ǧ����ָ",
    "damage_type" : "����"
]),
([  "action" : "$N����һ̾��һ�С���ָ��������˫�ֻó�����ָӰ������$n��$l",
    "force" : 380,
    "dodge" : -5,
    "damage": 40,
    "lvl" : 50,
    "skill_name" : "��ָ����",
    "damage_type" : "����"
]),
([  "action" : "$Nһʽ��Цָ���ϡ���������ʽ����ָ����һ��ָ�����$n��$l",
    "force" : 240,
    "dodge" : 15,
    "damage": 10,
    "lvl" : 10,
    "skill_name" : "Цָ����",
    "damage_type" : "����"
]),
([  "action" : "$N�ó�������һָ�����ȫ��������һָ����$n��$l",
    "force" : 420,
    "dodge" : -40,
    "damage": 30,
    "lvl" : 80,
    "skill_name" : "����һָ",
    "damage_type" : "����"
]),
});
int valid_enable(string usage) { return usage=="parry" || usage=="unarmed" || usage=="finger"; }	
int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("����ָ��ͨ������֡�\n");
    if ((int)me->query_skill("bibo-shengong", 1) < 20)
        return notify_fail("��ı̲��񹦻�򲻹����޷�ѧ��ָ��ͨ��\n");
        if ((int)me->query("max_neili") < 100)
        return notify_fail("�������̫�����޷�����ָ��ͨ��\n");
if (me->query_skill("finger", 1) <= me->query_skill("tanzhi-shentong", 1))	
return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");	
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
    level   = (int) me->query_skill("tanzhi-shentong",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
        return notify_fail("���������������Ϣһ�������ɡ�\n");
        if ((int)me->query("neili") < 20)
        return notify_fail("���������������ָ��ͨ��\n");
    me->receive_damage("qi", 30);
        me->add("neili", -10);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"tanzhi-shentong/" + action;
}

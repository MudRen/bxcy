// taizu-quan ̫�泤ȭ

inherit SKILL;

mapping *action = ({
([     "action" : "$Nһʽ��ǧ����С���˫��ֱ��ֱ�£��͹���ǰ������$n��$l",
       "force" : 100,
        "dodge" : -20,
        "parry" : -50,
       "lvl" : 0,       
       "damage_type" : "����"
]),
([     "action" : "$N����ǰ�㣬��ȭֱ������һ������$n������һ�С�����ն����",
       "force" : 135,
        "dodge" : -20,
       "lvl" : 0,
        "damage_type" : "����"
]),
([     "action" : "$Nʹ�С���˷����������������һ�������ȭ����$n",
       "force" : 240,
        "dodge" : -10,
        "parry" : -25,
       "lvl" : 10,
        "damage_type" : "����"
]),
([     "action" : "$N˫ȭ����������������飬���͡�������ͨ��֮��",
       "force" : 350,
        "dodge" : -5,
        "parry" : -30,
       "lvl" : 10,
        "damage_type" : "����"
]),
([     "action" : "$N������������һת�������غ�˫ȭ���������$n��$l��������������",
       "force" : 400,
        "dodge" : -10,
        "parry" : -35,
       "lvl" : 30,
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
       if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
               return notify_fail("��̫�泤ȭ������֡�\n");
      
       if ((int)me->query("max_neili") < 100)
               return notify_fail("�������̫�����޷�������\n");
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
       level   = (int) me->query_skill("taizu-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
       if ((int)me->query("jingli") < 30)
               return notify_fail("�������̫���ˡ�\n");
       if ((int)me->query("neili") < 20)
               return notify_fail("�������������̫�泤ȭ��\n");
       me->receive_damage("jingli", 30);
       me->add("neili", -10);
       return 1;
}


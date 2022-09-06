// quanzhen-jianfa ȫ�潣��

inherit SKILL;

mapping *action = ({
([      "action" : "$N�����ζ���̤���ţ���ƫ�棬һʽ���ֻ�������������$n����в",
        "force" : 150,
        "dodge" : 20,
        "damage" : 40,
        "parry" : 10,
        "lvl" : 0,
        "skill_name" : "�ֻ�����",
        "damage_type" : "����"
]),
([      "action" : "$N��ǰԾ��һ�������ֽ���������$wʹ��һʽ������Į����ֱ��$n��$l",
        "force" : 170,
        "dodge" : 15,
        "damage" : 50,
        "parry" : 20,
        "lvl" : 10,
        "skill_name" : "����Į��",
        "damage_type" : "����"
]),
([      "action" : "$N�β�ͦ����һʽ����ɽ������������$w�����ޱȣ������ӽ�ײ��$n��$l",
        "force" : 190,
        "dodge" : 15,
        "damage" : 60,
        "parry" : 20,
        "lvl" : 25,
        "skill_name" : "��ɽ����",
        "damage_type" : "����"
]),
([      "action" : "$N����΢�࣬$w������һ���һ���󻡣�һʽ��˳ˮ���ۡ���ƽƽ����$n��$l��ȥ",
        "force" : 230,
        "dodge" : 10,
        "damage" : 70,
        "parry" : 10,
        "lvl" : 30,
        "skill_name" : "˳ˮ����",
        "damage_type" : "����"
]),
([      "action" : "$N����š���������鱧��Բ��һʽ�������仨����$w�й�ֱ��������$n���ؿ�",
        "force" : 280,
        "dodge" : 10,
        "damage" : 80,
        "parry" : 15,
        "lvl" : 50,
        "skill_name" : "�����仨",
        "damage_type" : "����"
]),
([      "action" : "$Nһʽ������ٵء���$w������������������ֱ����Ю����֮����Ȼն��$n��$l",
        "force" : 300,
        "dodge" : 5,
        "damage" : 90,
        "parry" : 20,
        "lvl" : 70,
        "skill_name" : "����ٵ�",
        "damage_type" : "����"
]),
([      "action" : "$N����ʩ�����׵罻�ӡ���$w����Ƴ�һ����â��������ƿ�����$n��$l",
        "force" : 330,
        "dodge" : 5,
        "damage" : 100,
        "parry" : 15,
        "lvl" : 90,
        "skill_name" : "�׵罻��",
        "damage_type" : "����"
]),
([      "action" : "$N˫�Ȱ�����ף�һʽ�����񹲷ߡ������⻮������ԲȦ����������������",
        "force" : 380,
        "dodge" : -5,
        "damage" : 120,
        "parry" : 25,
        "lvl" : 110,
        "skill_name" : "���񹲷�",
        "damage_type" : "����"
]),
});

int valid_enable(string usage)
{
   return (usage == "sword") || (usage == "parry"); 
}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("force", 1) < 40)
                return notify_fail("��Ļ����ڹ����̫ǳ��\n");
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
            level   = (int) me->query_skill("quanzhen-jianfa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
        object weapon;
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("neili") < 10)
                return notify_fail("�������������ȫ�潣����\n");
          if ((int)me->query("qi") < 40)
                return notify_fail("�������������ȫ�潣����\n");
          me->receive_damage("qi", 25);
        me->add("neili", -5);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"quanzhen-jianfa/" + action;
}


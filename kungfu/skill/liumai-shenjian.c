// liumai-shenjian.c ������
inherit SKILL;
mapping *action = ({
([      "action" :
    "$N�����ư��������,������ת��������Сָ,һ�С�"+RED+"����"+NOR+"����һ��ɭ���Ľ�������$n��$l",
        "force" : 320,
        "lvl" : 0,
        "skill_name" : "����",
        "damage_type" : "����"
]),
([      "action" : "$N������ָ΢�����������Ķ���,����ָ��"+HIW+"�ٳ彣"+NOR+"���������,ָ�˾����ƿն���,����$n����ǰ",
        "force" : 380,
        "lvl" : 10,
        "skill_name" : "�ٳ彣",
        "damage_type" : "����"
]),
([      "action" : "$N����һԾ,������ͨ����ָ�ᵯ������ʹ��һ�С�"+MAG+"�г彣"+NOR+"����һ��ǿ������Ľ����ƿ�����$n��$l",
        "force" : 440,
        "lvl" : 20,
        "damage_type" : "����"
]),
([      "action" : "$N����һ��,���֡�"+YEL+"�س彣"+NOR+"�����������$n��ȥ,��������,�벻��һ˿ɱ��,ȴ��������'��'��һ�����ƿ���",
        "force" : 440,
        "lvl" : 30,
        "skill_name" : "�س彣",
        "damage_type" : "����"
]),
([      "action" : "$N����ʳָ����,ʹ����"+CYN+"���̽�"+NOR+"��,ָ������������������õش���$n��$l", 
        "force" : 500,
        "lvl" : 42,
        "skill_name" : "���̽�",
        "damage_type" : "����"
]),
([      "action" : "$N���һ��,Ĵָһ�ﵤ��������ӿ������ʹ����"+BLU+"������"+NOR+"������$n��ɲʱ�佣���ݺᣬ����������Ѹ�׼����໥��ײ��",     
  
        "force" : 560,
        "lvl" : 56,
        "skill_name" : "������",
        "damage_type" : "����"
]),
([      "action" : "$N������Ȼ�ӿ�,���֡�"+HIG+"�ٳ彣"+NOR+"�������$n����·ȫ����ɱ�����֡�"+MAG+"���̽�"+NOR+"������$n�ؿ�",
        "force" : 620,
        "lvl" : 72,
        "skill_name" : "����һ��",
        "damage_type" : "����"
]),
([      "action" : "$N�ͺ�һ��,����ȫ������,˫��Ĵָһ��,һ�ɳ��ȸ��͵Ľ������ڵ�������$n��ɲʱ������Ѹ�׼��磬�໥��ײ��,�����ɵ�",   
        "force" : 680,
        "lvl" : 90,
        "skill_name" : "˫�����",
        "damage_type" : "����"
]),
([      "action" : "$N�������˾Ŵ�����,ȫ��������ӯ,���²���,���֡�"+MAG+"����"+NOR+"������"+RED+"�ٳ彣"+NOR+"������"+HIC+"�г彣"+NOR+"����һ�����$n",     
        "force" : 740,
        "lvl" : 120,
        "skill_name" : "Ʈ������",
        "damage_type" : "����"
]),
([      "action" : "$NĬ������,������ָ������һ�ӡ�"+YEL+"������"+NOR+"������$n",     
        "force" : 800,
        "lvl" : 150,
        "skill_name" : "������",
        "damage_type" : "����"
]),

([      "action" : "$Nɱ������,ƴ�����й���,��"+BLU+"����"+NOR+"������"+YEL+"������"+NOR+"������"+WHT+"�ٳ彣"+NOR+"������"+RED+"�г彣"+NOR+"������"+HIC+"���̽�"+NOR+"������"+CYN+"�س彣"+NOR+"��һ��һ����һ��һ����һ��һ�µ�����$n��$l",     
        "force" : 860,
        "lvl" : 180,
        "skill_name" : "�鸣����",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="unarmed"; }
int practice_level(){   return 130;  }
int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�������񽣱�����֡�\n");
        if ((int)me->query_skill("force", 1) < 500)
                return notify_fail("��Ļ����ڹ���򲻹����޷�ѧ�����񽣡�\n");
        if ((int)me->query("max_neili") < 1500)
                return notify_fail("�������̫�����޷��������񽣡�\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("liumai-shenjian", 1))
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
    mapping a_action;
    int i, level;
    level   = (int) me->query_skill("liumai-shenjian", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["parry"]  = 0-level*3;
    a_action["attack"]  = level/2;
    a_action["damage"] = level*2;
    return a_action;

}


int practice_skill(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�������񽣱�����֡�\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 80)
                return notify_fail("�������������������!\n");
        me->receive_damage("qi", 40);
        me->add("neili", -70);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"liumai-shenjian/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 100 ) return 0;
       if (me->query_skill("liumai-shenjian",1)>100)
        if( random(me->query("neili")) > victim->query("max_neili") ) {
                victim->receive_wound("qi", (damage_bonus - 100) / 2 , me);
                return notify_fail("���������͡���һ�����죬��Ȼ�ǽ���������Դ�������\n");
  }      
}
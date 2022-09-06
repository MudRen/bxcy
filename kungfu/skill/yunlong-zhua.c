// yunlong-zhua.c -����צ
inherit SKILL;
mapping *action = ({
([  "action" : "$Nȫ��εض��𣬰����һ�����һʽ��"+YEL+"��ӥϮ��"+NOR+"����Ѹ�͵�ץ��$n��$l",
    "force" : 150,
    "lvl" : 0,
    "skills_name" : YEL "��ӥϮ��" NOR,
    "damage_type" : "ץ��"
]),
([  "action" : "$N����ֱ����˫��ƽ�죬һʽ��"+RED+"��ӥչ��"+NOR+"����˫צһǰһ��£��$n��$l",
    "force" : 220,
    "lvl" : 10,
    "skills_name" : RED "��ӥչ��" NOR,
        "damage_type" : "ץ��"
]),
([  "action" : "$Nһʽ��"+MAG+"�γ�ӥ��"+NOR+"����ȫ����б��ƽ�ɣ�����һ����˫צ����$n�ļ�ͷ",
    "force" : 250,
    "lvl" : 20,
    "skills_name" : MAG "�γ�ӥ��" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N˫צ�����Ͼ٣�ʹһʽ��"+WHT+"ӭ������"+NOR+"����һ�����ֱ�Ϯ��$n����Ҹ����",
    "force" : 290,
    "lvl" : 30,
    "skills_name" : WHT "ӭ������" NOR,
        "damage_type" : "����"
]),
([  "action" : "$Nȫ�������ǰ��һʽ��"+CYN+"������צ"+NOR+"������צͻ�������Ȱ�ץ��$n���ؿ�",
    "force" : 350,
    "lvl" : 40,
    "skills_name" : CYN "������צ" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N���ػ��У�һʽ��"+HIB+"��������"+NOR+"��������Ϯ�����д�Ѩ�����ַ�ץ$n���ɲ�",
    "force" : 350,
    "lvl" : 50,
    "skills_name" : HIB "��������" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N��������צ���棬һʽ��"+GRN+"��������"+NOR+"���������������ƿն�����Ѹ���ޱȵػ���$n",
    "force" : 380,
    "lvl" : 60,
    "skills_name" : GRN "��������" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N�ڿո߷����ɣ�һʽ��"+HIB+"ӥ������"+NOR+"��������ж�ʱ�Գ�һ������צӰ����������$n",
    "force" : 430,
    "lvl" : 60,
    "skills_name" : HIB "ӥ������" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N���Ĳ��ض���ʹһʽ��"+MAG+"������ˮ"+NOR+"�������λ���һ����������$n",
    "force" : 470,
    "lvl" : 70,
    "skills_name" : MAG "������ˮ" NOR,
        "damage_type" : "����"
]),
([  "action" : "$N΢΢һЦ��ʹһʽ��"+YEL+"�����"+NOR+"����˫�ֻó�������,ֱ����$n��$l",
    "force" : 470,
    "lvl" : 80,
    "skills_name" : YEL "�����" NOR,
        "damage_type" : "����"
])
});
int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }
int practice_level(){   return 80;  }
int valid_combine(string combo) { return combo=="yunlong-shou"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("������צ������֡�\n");
    if ((int)me->query_skill("yunlong-shengong", 1) < 50)
        return notify_fail("��������񹦻�򲻹����޷�ѧ����צ��\n");
    if ((int)me->query_skill("force", 1) < 50)
        return notify_fail("��Ļ����ڹ���򲻹����޷�ѧ����צ��\n");
    if ((int)me->query("max_neili") < 350)
        return notify_fail("�������̫�����޷�������צ��\n");
    if ((int)me->query_skill("unarmed",1) <40)
        return notify_fail("��Ļ���צ����򲻹����޷�ѧ����צ��\n");
    if (2*(int)me->query_skill("yunlong-xinfa",1) <(int)me->query_skill("yunlong-zhua",1))
        return notify_fail("�������צ����򲻹����޷�����ѧ����צ��\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("yunlong-zhua", 1))
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
    level   = (int) me->query_skill("yunlong-zhua",1);
    for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level;
    a_action["attack"]  = level/2;
    a_action["damage"] = level;
    return a_action;
}

int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("������צ������֡�\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("�����������������צ��\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        if(me->query_skill("yunlong-shengong") > 70 ) {
        if( random(me->query_skill("yunlong-zhua")) > 30 ) {
            victim->apply_condition("zhua_poison", random(me->query_skill("ningxue-shenzhua")/10) + 1 +
            victim->query_condition("zhua_poison"));
    }
    }
}
string perform_action_file(string action)
{
    return __DIR__"yunlong-zhua/" + action;
}

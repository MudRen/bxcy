// luoying-zhang.c ��Ӣ����
// by victori
inherit SKILL;
mapping *action = ({
([      "action" : "$N˫��ƽ�죬�����ӳ���һʽ��"+RED+"����էչ"+NOR+"����ָ����ӯƯ�������ᷴ��$n��$l",
        "force" : 100,
        "dodge" : 15,
        "damage_type" : "����",
        "lvl" : 10,
        "skill_name" : "����էչ"
]),
([      "action" : "$N������ָ����һ�գ�һʽ��"+MAG+"�ط����"+NOR+"������ָ��Ȼңң����$n��
$nֻ������ɼ���Ϯ���Լ��崦��Ѩ",
        "force" : 110,
        "dodge" : 10,
        "damage_type" : "����",
        "lvl" : 0,
        "skill_name" : "�ط����"
]),
([      "action" : "$NͻȻ����Ծ���գ�һ������ת���������䣬
һʽ��"+BLK+"���Ƿɻ�"+NOR+"��������$n��ͷ��",
        "force" : 120,
        "dodge" : 15,
        "damage_type" : "����",
        "lvl" : 10,
        "skill_name" : "���Ƿɻ�"
]),
([      "action" : "$NͻȻԾ��˫�������������罣�����缲�������
һʽ��"+HIC+"�꼱���"+NOR+"��������$n��ȫ��",
        "force" : 130,
        "dodge" : 15,
        "damage_type" : "����",
        "lvl" : 10,
        "skill_name" : "�꼱���"
]),
([      "action" : "$N���ֻ������ĳ��죬������ֲ�£ʳָ��ָ�����������
һʽ��"+HIM+"�Ǻ�����"+NOR+"����ֱָ$n������",
        "force" : 140,
        "dodge" : 20,
        "damage_type" : "����",
        "lvl" : 20,
        "skill_name" : "�Ǻ�����"
]),
([      "action" : "$NͻȻ������ˣ�����һʽ��"+HIM+"�����׷�"+NOR+"����ƽ�����˫����$n�ĺ�����������",
        "force" : 140,
        "dodge" : 35,
        "damage_type" : "����",
        "lvl" : 30,
        "skill_name" : "�����׷�"
]),
([      "action" : "$NͻȻ����Ծ������Ю�ž�����ӿ�ĳ����������������ƺ�ͻ�������
һʽ��"+HIR+"����׷��"+NOR+"����������ǰ��$n��$l��ȥ",
        "force" : 150,
        "dodge" : 35,
        "damage_type" : "����",
        "lvl" : 30,
        "skill_name" : "����׷��"
]),
([      "action" : "$Nʹһʽ��"+HIG+"�����®"+NOR+"����ȫ��ͻȻ������ת��˫�ƺ�ǰ�����͵�����$n���ؿ�",
        "force" : 160,
        "dodge" : 30,
        "damage_type" : "����",
        "lvl" : 40,
        "skill_name" : "�����®"
]),
([      "action" : "$Nǰ��һ�࣬һʽ��"HIC+"���ƺ��"+NOR+"���������罣��һ����������Ϯ��$n������",
        "force" : 170,
        "dodge" : 35,
        "damage_type" : "����",
        "lvl" : 50,
        "skill_name" : "���ƺ��"
]),
([      "action" : "$Nʹһʽ��"HIW+"�׺羭��"+NOR+"����˫���������Ȧ������һ������$n��$l�ȥ",
        "force" : 180,
        "parry" : 15,
        "dodge" : 35,
        "damage_type" : "����",
        "lvl" : 70,
        "skill_name" : "�׺羭��"
]),
([      "action" : "$N˫��ʳָ����ָһ�ͣ�һʽ��"MAG+"��������"+NOR+"����һ��ǿ�ҵ�����ӿ��$n��ȫ��",
        "force" : 190,
        "parry" : -5,
        "dodge" : 20,
        "damage_type" : "����",
        "lvl" : 60,
        "skill_name" : "��������"
]),
([      "action" : "$Nһʽ��"BLU+"��Ӣ����"+NOR+"����˫������ǰ��ת���ƻ����裬
����ǵ�ֱָ��$n��$nֻ�������ƻ����ۻ����ҡ�",
        "force" : 200,
        "parry" : -20,
        "dodge" : -15,
        "damage_type" : "����",
        "lvl" : 99,
        "skill_name" : "��Ӣ����"
])
});
int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; } 
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("����Ӣ���Ʊ�����֡�\n");
    if ((int)me->query_skill("bibo-shengong", 1) < 100)
        return notify_fail("��ı̲��񹦻�򲻹����޷�ѧ��Ӣ���ơ�\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������̫�����޷�����Ӣ���ơ�\n");
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
    level = (int)me->query_skill("luoying-zhang", 1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
       return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 20)
       return notify_fail("���������������Ӣ���ơ�\n");
    me->receive_damage("qi", 20);
    me->add("neili", -1);
    return 1;
}    
string perform_action_file(string action)
{
        return __DIR__"luoying-zhang/" + action;
}

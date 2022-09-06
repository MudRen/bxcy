// huashan-jianfa.c ��ɽ����
// Modified by Venus Oct.1997

mapping *action = ({
([  "action" : "$Nһ�С����Ƴ�ᶡ�������$w����$n��$l",
    "damage" : 20,
    "damage_type" : "����"
]),
([  "action" : "$Nʹ�����з����ǡ���$w��˸����������$n��$l",
    "damage" : 25,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�����������$w���϶��»���һ���󻡣���$n������ȥ",  
    "damage" : 30,
    "damage_type" : "����"
]),
([  "action" : "$N��ǰ����һ��������$wʹ�����׺���ա�ֱ��$n��$l",
    "damage" : 35,
    "damage_type" : "����"
]),
([  "action" : "$N���е�$wһ�Σ�ʹ��������ӭ�͡�ֱ��$n��$l",
    "damage" : 50,
    "damage_type" : "����"
]),
});

;

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry")
; }

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
   return notify_fail("�������������\n");
    if ((int)me->query_skill("zixia-shengong", 1) < 20)
   return notify_fail("�����ϼ�񹦻��̫ǳ��\n");
    if ((int)me->query_skill("huashan-ken", 1) < 20)
   return notify_fail("��Ļ�ɽȭ���̫ǳ��\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
   return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
   return notify_fail("���������������ɽ������\n");
    me->receive_damage("qi", 30);
    return 1;
}

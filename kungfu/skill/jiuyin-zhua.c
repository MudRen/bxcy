// jiuyin-zhua.c -�����׹�צ
// Modified by Venus Oct.1997

inherit SKILL;

mapping *action = ({
([  "action" : "$N����΢�Σ�һ�С���˼����ǡ���ʮָ��ꪣ�����$n��˫������",
    "force" : 200,
    "dodge" : 10,
    "damage_type" : "����",
    "lvl"   : 0,
    "skill_name" : "��˼�����" ,
]),
([  "action" : "$N������磬ʮָ΢΢������һ�С������Ѻ��ѡ�ץ��$n��ǰ��",  
    "force" : 220,
    "dodge" : 20,
    "damage_type" : "����",
    "lvl"   : 10,
    "skill_name" : "�����Ѻ���" ,
]),
([  "action" : "$N˫�ֺ������֣�һ�С���ָ�Ʋ����������Ȱ��ץ��$n�ļ�ͷ",  
    "force" : 250,
    "dodge" : 30,
    "damage_type" : "����",
    "lvl"   : 20,
    "skill_name" : "��ָ�Ʋ���" ,
]),
([  "action" : "$N���ֵ��ػ��������ּ�����һ�С����µ����ա����͵�ץ��$n�Ķ�
ͷ",
    "force" : 290,
    "dodge" : 25,
    "damage_type" : "����",
    "lvl"   : 31,
    "skill_name" : "���µ�����" ,
]),
([  "action" : "$Nʹһ�С��������ķ�������������ľ��磬ײ��$n",
    "force" : 340,
    "dodge" : 40,
    "damage_type" : "����",
    "lvl"   : 43,
    "skill_name" : "�������ķ�" ,
]),
([  "action" : "$NͻȻ˫��ƽ�٣�$nһ�������ڲ²�䣬���$Nವ�һ�½�˫��    
�ջ���ǰ������һ�С�ɭȻ���׹ǡ�����ָ�繳��ֱץ��$n������",
    "force" : 400,
    "dodge" : 35,
    "damage_type" : "����",
    "lvl"   : 56,
    "skill_name" : "ɭȻ���׹�" ,
]),
([  "action" : "$Nʹ���������Բ�ɢ������Ȼ�������ϣ�����$n��ת��Ȧ��$n����  
�����Ҽ䣬$N����Ȼͣ��$n�������ֻ���һ����Ȧ���������ֳ����Ȧ��ץ$n�ĺ�",  
    "force" : 430,
    "parry" : 20,
    "dodge" : 20,
    "damage_type" : "����",
    "lvl"   : 71,
    "skill_name" : "�����Բ�ɢ" ,
]),
([  "action" : "$N���ޱ��飬˫�ۺ�����ҵؼ��ӣ�ʹ���������ѻ��֡���ʮָ    
���������Ѹ���ޱȵ�Ϯ��$nȫ��������Ѩ",
    "force" : 460,
    "parry" : 5,
    "dodge" : 30,
    "damage_type" : "����",
    "lvl"   : 87,
    "skill_name" : "�����ѻ���" ,
]),
([  "action" : "$N������ӣ������������磬һ�����������$N�������ѱ�����  
ɫ�����ż��о���ʩչ����צ�ֹ������������ŵ�צӰ����$n��ͷ��",
    "force" : 520,
    "parry" : 10,
    "dodge" : 20,
    "damage_type" : "����",
    "lvl"   : 110,
    "skill_name" : "צ�ֹ�����" ,
]),
});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }  

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
   return notify_fail("�������׹�צ������֡�\n");
    if ((int)me->query_skill("force", 1) < 50)
   return notify_fail("����ڹ��ķ���򲻹����������׹�צ���߻���ħ
��\n");
    if ((int)me->query("max_neili") < 300)
   return notify_fail("�������̫�����޷��������׹�צ��\n");
    return 1;
}


string query_skill_name(int level)
{
    int i;
    for(i = sizeof(action)-1; i >= 0; i--)
   if(level >= action[i-1]["lvl"])
   return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int)me->query_skill("jiuyin-zhua",1);
    for(i = sizeof(action); i > 0; i--)
   if(level > action[i-1]["lvl"])
   return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
   return notify_fail("�������̫���ˡ�\n");
    if ((int)me->query("neili") < 8)
   return notify_fail("������������������׹�צ��\n");
    if (me->query_skill("jiuyin-zhua", 1) < 60)
   me->receive_damage("qi", 15);
    else
    me->receive_damage("qi", 30);
    me->add("neili", -5);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"jiuyin-zhua/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
    if( random(me->query_skill("jiuyin-zhua",1)) > 50) {
    victim->apply_condition("jy_poison", random(2) + 1 +
   victim->query_condition("jy_poison"));
    }
}
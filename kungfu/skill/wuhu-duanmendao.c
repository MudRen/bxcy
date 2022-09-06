// wuhu-duanmendao.c �廢���ŵ�
inherit SKILL;
mapping *action = ({
([  "action" : "$N����$wбָ��һ�С�"+RED+"ֱ��ֱȥ"+NOR+"��������һ�٣�һ����$n��$l��ȥ",
    "force" : 70,
    "damage_type" : "����",
    "lvl" : 0,
]),
([  "action" : "$Nһ�С�"+BLU+"ͯ�ӹһ�"+NOR+"������������㣬$wһ��һ�գ�ƽ�л���$n�ľ���",
    "force" : 90,
    "lvl" : 20,
    "damage_type" : "����"
]),
([  "action" : "$Nչ���鲽������Ծ�䣬һ�С�"+HIW+"�ƴ�����"+NOR+"��������һ������ն��$n",
    "force" : 110,
    "lvl" : 50,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+WHT+"������ɽ"+NOR+"����$w�󿪴��أ����϶��»���һ�����磬ֱ����$n",
    "force" : 130,
    "lvl" : 100,
    "damage_type" : "����"
]),
([  "action" : "$N����$wһ����һ�С�"+CYN+"��Ϫ����"+NOR+"����˫�ֳ����������У�����$n���ؿ�",
    "force" : 140,
    "lvl" : 150,
    "damage_type" : "����"
]),
([  "action" : "$N����$w��ʹ��һ�С�"+MAG+"�Ź�����"+NOR+"�����������ã����ҿ�����������$n",
    "force" : 170,
    "lvl" : 200,
    "damage_type" : "����"
]),
([  "action" : "$Nһ�С�"+HIC+"��������"+NOR+"�������Ծ����أ�$w˳����ǰ��Ю��������$n��$l",
    "force" : 210,
    "lvl" : 250,
    "damage_type" : "����"
]),
([  "action" : "$N����פ�أ�һ�С�"+HIB+"������Ϣ"+NOR+"�����ӳ�һƬ�����ĵ�Ӱ����$n��ȫ��ӿȥ",
    "force" : 220,
    "lvl" : 300,
    "damage_type" : "����"
]),
([  "action" : "$N���ֺ󳷣�����һ����һ�С�"+YEL+"׳ʿ����"+NOR+"������ʱһ���׹�ֱն��$n���ֱ�",
    "force" : 240,
    "lvl" : 350,
    "damage_type" : "����"
]),
([  "action" : "$N�߸�Ծ��һ�С�"+HIY+"��ͷ���"+NOR+"��������$wֱ����$n�ľ���",
    "force" : 250,
    "lvl" : 400,
    "damage_type" : "����"
]),
([  "action" : "$N���ػ��У�һ�С�"+RED+"���Ӿ���"+NOR+"��������$wֱ��ȥ$n���ɲ�",
    "force" : 260,
    "lvl" : 450,
    "damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }
int practice_level(){   return 140;  }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������������\n");
    if ((int)me->query_skill("blade", 1) < 20)
        return notify_fail("��Ļ����������̫ǳ��\n");
    if (me->query_skill("blade", 1) <=me->query_skill("wuhu-duanmendao", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
        mapping a_action;
        int i, level;
        level   = (int) me->query_skill("wuhu-duanmendao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    if ( me->query_temp("perform_duan")) level+=level;
    a_action["dodge"]  = 0-level;
    a_action["parry"]  = 0-level*2;
    a_action["attack"]  = level;
    a_action["damage"] = level*4;
    return a_action;
}

int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "blade")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("��������������廢���ŵ�����\n");
    me->receive_damage("qi", 30);
    return 1;
}


string perform_action_file(string action)
{
    return __DIR__"wuhu-duanmendao/" + action;
}

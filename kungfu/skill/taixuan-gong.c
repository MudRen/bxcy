// taixuan-gong.c ���͵�̫����
// Jay 4/5/96
// modified by Venus Oct.1997
inherit FORCE;	

string *dodge_msg = ({
   HIG "$n�����ĳ������絽������$N��һ�ߡ�\n",NOR
   HIG "$nʹ��һ�С���ա���������Ʈȥ��˲��������$N��ǰ \n",NOR    
   HIG "$n�ֱۻ�ת��ץס$N����һ�ƣ���$NԶԶ������\n",NOR
   HIG "$nʹ��һ�С����Կա���˫��һ�㣬Ծ������֮�� \n",NOR
   HIG "$n������ţ���Ծ��������������ʮ�����⡣\n",NOR
   HIG "$Nֻ����ǰһ����ֻ����$n����һ�ϣ��Լ���������ȻĪ�����������ˡ�\n",NOR
   HIG "$nʹ��һ�С��Ŀա�����������Ʈȥ \n", NOR
});

mapping *action = ({
([  "action":"$N˫��һ�٣�һ�ɾ���������ӿ�������Ƶ�$n���Ժ���",
    "force" : 200,
    "dodge" : 20,
    "damage_type":  "����"
]),
([  "action":"$N�����������$n�۰���Ѹ���ޱȵ�һ����$nһ�ӵ��˳�ȥ",    
    "force" : 220,
    "dodge" : 20,
    "damage_type":  "����"
]),
([  "action":"$N���һ�����ſ�һ��������$n������ȥ",
    "force" : 400,
    "dodge" : 30,
    "damage_type":  "����"
]),
([  "action":"$N�����ϣ�˫���͵�����$n",
    "force" : 225,
    "dodge" : 30,
    "damage_type":  "����"
]),
([  "action":"$N����΢�࣬ͻȻ����һ�ţ�����$n����·���ŵ���;���͵�һ̧������$n����",
    "force" : 230,
    "dodge" : 40,
    "damage_type":  "����"
]),
([  "action":"$NͻȻ������һ�࣬��ס$n��·������������ӿ����",
    "force" : 230,
    "dodge" : 40,
    "damage_type":  "����"
]),
(["action" : "$Nһ��"HIW" �����ʽ "NOR"������бб������$n��$l",
        "force" : 300,
        "dodge" : 20,
        "skill_name" : "�����ʽ",
        "damage_type" : "����"
]),
(["action" : "$N˫����ƮƮ������$n��ͻȻ�����Ϲ���һ��"HIW" ����̧�� "NOR"����$n��$l",
        "force" : 350,
        "dodge" : 10,
         "skill_name" : "����̧��",
        "damage_type" : "����"
]),
(["action" : "$N�����һ��"RED" ��Գ�׹� "NOR"��˫�ƻû�һƬ��Ӱ����$n�������ڡ�",
        "force" : 400,
        "dodge" : 30,
        "skill_name" : "��Գ�׹�",
        "damage_type" : "����"
]),

(["action" : "$Nһ��"RED" ������ "NOR"��˫�ַ׷ɣ�������ʽ��˫�ַ���$nȫ�������Ѩ",
        "force" : 450,
        "dodge" : 25,
         "skill_name" : "������",
    "damage_type" : "����"
]),
(["action" : "$Nһ��"HIY" ��ĥ���� "NOR"���й�ֱ����ֻ��һƬ��Ӱ����$n",
        "force" : 500,
        "dodge" : 20,
        "skill_name" : "��ĥ����",
        "damage_type" : "����"
]),

(["action" : "$N˫��ƽ�ӣ�һ��"HIY" ��Ƿ���� "NOR"����$n,��$n�޴��ɶ�.",
        "force" : 550,
        "dodge" : 25,
         "skill_name" : "��Ƿ����",
            "damage_type" : "����"
]),
(["action" : "$N�������࣬ͷ�½��ϣ�һ��"HIR" ��ϼ���� "NOR"����$n",
        "force" : 600,
        "dodge" : 30,
         "skill_name" : "��ϼ����",
        "damage_type" : "����"
]),

(["action" : "$N������Σ�����һ��"HIM" �ϵ紩�� "NOR"����$n����գ���δʹ����;�ж�����Եȴ����$n���Ҿ���",
        "force" : 650,
        "dodge" : 30,
         "skill_name" : "�ϵ紩��",
           "damage_type" : "����"
])

});

int valid_enable(string usage)
{
    return usage == "unarmed" || usage == "dodge" || usage == "parry" || usage == "force";
}

mapping query_action(object me, object weapon)
{
    mapping a_action;
    int i, level;
level   = (int) me->query_skill("taixuan-gong", 1); //lisa �޸���2003.6.25 ����Ϊliumai-shenjian
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/2)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["parry"]  = 0-level*4;
    a_action["attack"]  = level/3;
    a_action["damage"] = level*4;
    return a_action;

}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 100 ) return 0;
         if (me->query_skill("taixuan-gong",1)>100)
if( random(me->query("neili")) > random(victim->query("neili"))) {
                victim->receive_wound("qi", (damage_bonus - 100)*2 , me);
                return HIW "̫����Ǳ�ص����������˳�����$n �е���ͷһ���³�һ��"HIR"��Ѫ"HIW"��\n" NOR;
        }
}

string query_dodge_msg(string limb)
{ 
      return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
 if (random(this_player()->query("kar")) > 19 && this_player()->query("kar") > 23)
        return 1;
    return notify_fail("�����ʯ��ڤ˼������һ�ᣬ��Ŀ������Ŀ������ۻ����ҡ�\n");
}
string exert_function_file(string func)
{
    return __DIR__"taixuan-gong/" + func;
}



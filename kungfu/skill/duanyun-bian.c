// duanyun-bian.c ���Ʊ޷�

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action":"$Nһ��"HIR" �ۻ� "NOR",�����������$w��$n����Χס������һ�£���Ȧ������С��",
        "force":        (int)this_player()->query("max_neili")/4,
        "dodge":        -10,
        "damage":       (int)this_player()->query("shen")/2500,
        "skill_name" : "�ۻ�",
        "damage_type":  "����"
]),
([      "action":"$N������ã�����$wһ��"HIC" ��� "NOR",����$w����һ������Ѹ�ٻ���$n��",
        "force":        (int)this_player()->query("max_neili")/4,
        "dodge":        5,
        "damage":       (int)this_player()->query("shen")/2500,
        "skill_name" : "���",
        "damage_type":  "����"
]),
([      "action":"$N�ڿն�������$w���Բ����һ��"HIB" ���� "NOR"ѹ��$n,��$n�޴��ɶ㡣",
        "force":        (int)this_player()->query("max_neili")/4,
        "dodge":        10,
        "damage":       (int)this_player()->query("shen")/2500,
        "skill_name" : "����",
        "damage_type":  "����"
]),
([      "action":"$N������ң�һ��"HIR" ���� "NOR"������$w��������Ӱ����ɽ������ɨ��$nȫ��",
        "force":        (int)this_player()->query("max_neili")/4,
        "dodge":        -5,
        "damage":       (int)this_player()->query("shen")/2500,
        "skill_name" : "����",
        "damage_type":  "����"
]),
([      "action":"$N��ǰһ��, ����$N����һת��һ��"HIC" �Ƶ� "NOR"������$w�����һ�㣬��֪��������Ϯ��$n��$l��",
        "force":        (int)this_player()->query("max_neili")/4,
        "dodge":        -10,
        "damage":       (int)this_player()->query("shen")/2500,
        "skill_name" : "�Ƶ�",
        "damage_type":  "����"
]),
([      "action":"$N�ֳ�$w,������ԣ�һ��"HIR" ���� "NOR"����$w����ʺ�����$n,�ѽ�$n�����ڱ��¡�",
        "force":        (int)this_player()->query("max_neili")/4,
        "dodge":        -20,
        "damage":       (int)this_player()->query("shen")/2500,
        "skill_name":  "����",
        "damage_type":  "����"
]),
([      "action":"$N������Σ��ҽ�ͻȻ��ǰ������һ��"CYN" ֹ�� "NOR"������$w��ͬ����һ��������Ϣ�Ĵ���$n!",
        "force":        (int)this_player()->query("max_neili")/4,
        "dodge":        0,
        "damage":       (int)this_player()->query("shen")/2500,
        "skill_name" : "ֹ��",
        "damage_type":  "����"
]),
([      "action":"$N��ǰ�ݳ�������ɹ�$nͷ����һ��"HIW" ���� "NOR"����$w����$n��$l",
        "force":        (int)this_player()->query("max_neili")/4,
        "dodge":        100,
        "damage":       (int)this_player()->query("shen")/2500,
        "skill_name" : "����",
        "damage_type":  "����"
]),
([      "action":"$N����$w�γ������Ӱ��һ��"HIB" ���� "NOR"����ʵʵ�ı�Ӱ������ǵصĻ���$n",
        "force":        (int)this_player()->query("max_neili")/4,
        "dodge":        50,
        "damage":       (int)this_player()->query("shen")/2500,
        "skill_name" : "����",
        "damage_type":  "����"
]),
([      "action":"$Nһ��"YEL" ���� "NOR"����$w�����������Ʒɻ�$w�ܲ�͸�������$n��",
        "force":        (int)this_player()->query("max_neili")/4,
        "dodge":        40,
        "damage":       (int)this_player()->query("shen")/2500,
        "skill_name" : "����",
        "damage_type":  "����"
]),
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
        object weapon;
        int lvl = (int)me->query_skill("duanyun-bian", 1);
        int t = 1, j;
        if( (int)me->query("max_neili") < 500 )
                return notify_fail("����������㣬û�а취�����Ʊ޷�, ����Щ���������ɡ�\n");

        if ((int)me->query_skill("xiantian-gong", 1) < 200)
                return notify_fail("��������񹦻��̫ǳ��\n");

        if ( !objectp(weapon = me->query_temp("weapon"))
        || ( string)weapon->query("skill_type") != "whip" )
                return notify_fail("���������һ�����Ӳ������޷���\n");
        if(lvl<=100)
        {
                if (lvl > 10 && (int)me->query("shen") < t * 100) 
                        return notify_fail("�����������̫���ˡ�\n");
        }
        else
        {
                if ((int)me->query("shen") < (51200 + (lvl - 100) * 1000)) 
                        return notify_fail("�����������̫���ˡ�\n");
        }
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
        level   = (int) me->query_skill("duanyun-bian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("����������������Ʊ޷���\n");
        me->receive_damage("qi", 5);
        return 1;
}

string perform_action_file(string action)
{
        if ( this_player()->query_skill("duanyun-bian", 1) >= 50 )
                return __DIR__"duanyun-bian/" + action;
}


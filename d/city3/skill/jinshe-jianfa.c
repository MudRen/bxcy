// jinshe-jianfa.c ���߽���
// by enter
// modified by wind

#include <ansi.h>

inherit SKILL;

string *parry_msg = ({
        HIC "ͻȻ֮�䣬$n�����߶�����󻬳������������$N��һ�С�\n", NOR
        HIC "$n�ֱۻ�ת������$w�����߰���˹�����\n", NOR
        HIC "$n��$w�����֣�������$N�ļ��ϴ��˹�ȥ��$N���ɾ���һ�����⡣\n", NOR
        HIC "$n����Ʈ�����Ʋ���$N�����󣬶����$N��һ�С�\n", NOR
        HIC "$N���һ�����͵ع��˹�ȥ��ȴ��$n���岻��˼���ת�˼����䣬��������С�\n", NOR
        HIC "$N�۾�һ����$nͻȻ�������״����������������С�\n", NOR 
});


mapping *action = ({
([      "action": "$NͻȻ������΢Ц������Խ��Խ�����������˵��ϣ�����$wȴֱ��$n��ǰ��",
        "force" : 80,
        "dodge" : 40,
        "damage": 40,
        "lvl" : 0,
        "skill_name" : "���΢Ц",
        "damage_type":  "����"
]),
([      "action":"$N�����߶�������$w�Ӳ���˼��ĽǶ���$n�ĺ󱳴�ȥ",
        "force" : 80,
        "dodge" : 60,
        "damage": 70,
        "lvl" : 25,
        "skill_name" : "�����߶�",
        "damage_type":  "����"
]),
([      "action": HIY "ͻȻ�䣬$N���Ϸ������ɽ�⣬$w���ʶ�������$n��ǰ�ػ�ȥ" NOR,
        "force" : 140,
        "dodge" : 20,
        "damage": 100,
        "lvl" : 100,
        "skill_name" :  "���ɽ��",
        "damage_type":  "����"
]),
([      "action":"$Ņ�����죬״��������$w��������ֱ��$nͷ����$nһ���ҽ�",
        "force" : 180,
        "dodge" : 60,
        "damage": 160,
        "lvl" : 110,
        "skill_name" : "̧������",
        "damage_type":  "����"
]),
});


int valid_enable(string usage) 
{ 
    return usage == "sword" || usage == "parry"; 
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
        level   = (int) me->query_skill("jinshe-jianfa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

string query_parry_msg(string limb)
{
        return parry_msg[random(sizeof(parry_msg))];
}

int valid_learn(object me)
{
        return notify_fail("���߽���ֻ��ͨ����ϰ�����߽��ס���ѧϰ��\n");
}
string perform_action_file(string action)
{
        return __DIR__"jinshe-jianfa/" + action;
}
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$N������$w��ӣ�һʽ����ɨǧ������$w����һ�ɷ�������ʻ��$n���ʺ�",
        "skill_name" : "��ɨǧ��",
        "force" : 150,
        "dodge" : 20,
        "parry" : 20,
        "lvl" : 30,
        "damage" : 100,
        "damage_type" : "����",
]),
([      "action" : "$N˫�ֳ�$w�ٹ�ͷ������Ȼ�ӳ����콵�����\nֻ��һ��ǿ����������$w�Կն�����Ϯ��$n",
        "skill_name" : "�콵���",
        "force" : 180,
        "dodge" : 30,
        "parry" : 30,
        "lvl" : 60,
        "damage" : 150,
        "damage_type" : "����",
]),
([      "action" : "$N��ߤ$w�����������������߳����첽��\n��ʱ������������$N����������$wն��$n��ͷ­�����Ż����������ħ��",
        "skill_name" : "�����ħ",
        "force" : 220,
        "dodge" : 50,
        "parry" : 30,
        "lvl" : 100,
        "damage" : 200,
        "damage_type" : "����",
]),
/*
([      "action" : HIR"ֻ��$N����̫�ͣ�$w����׹�䣬$N��æ����ȥ��\n$n������˴��ʱ������ϷŹ���һ������׼��ʩչ�ֶ�\n$n��֪��������ʥ����ľ��С�����Ϣ�ġ���ֻ��$NͻȻһ�����ӷ�����$nֻ�е��ؿڱ�������ʱ����$w���������ദ��"NOR,
        "skill_name" : "����Ϣ��",
        "force" : 300,
        "dodge" : 100,
        "parry" : 100,
        "lvl" : 120,
        "damage" : 500,
        "damage_type" : "����",
]),
*/
});


int valid_enable(string usage) { return usage == "lingfa"; }

//int valid_combine(string combo) { return combo=="mingwang-jian"; }

int valid_learn(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
           ||(string)weapon->query("skill_type") != "lingfa")
                return notify_fail("�����ʹ��ʥ����ſ�������ʥ�����\n");
        if ((int)me->query_skill("lingfa", 1) < 30)
                return notify_fail("��Ļ����̫���ˣ�������ʥ�����\n");
        if ((int)me->query_skill("shenghuo-xinfa", 1) < 30)
                return notify_fail("���ʥ���ķ������򲻹����޷�ѧʥ�����\n");
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
        if (random(me->query_skill("lingfa")) > 120 &&
            me->query_skill("force") > 120 &&
            me->query("neili") > 1000 &&
            (string)weapon->query("id") == "shenghuo-ling" ) {
                me->add("neili", -200);
                return ([
          "action" : "ֻ��$N����̫�ͣ�$w����׹�䣬$N��æ����ȥ��\n$n������˴��ʱ������ϷŹ���һ������׼��ʩչ�ֶ�\n$n��֪��������ʥ����ľ��С�����Ϣ�ġ�\nֻ��$NͻȻһ�����ӷ�����$w���¶��ϼ�����$n��ȥ��",
        "skill_name" : "����Ϣ��",
//        "force" : 300,
//        "dodge" : 100,
//        "parry" : 100,
//       "lvl" : 120,
        "damage" : 500,
        "damage_type" : "����",
                       ]);
        }
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 50)
                return notify_fail("�������������������ʥ�����\n");
        if ((int)me->query("neili") < 600)
                return notify_fail("�������������ʥ�����\n");
        me->receive_damage("qi", 30);
        me->add("neili", -10);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"shenghuo-lingfa/" + action;
}
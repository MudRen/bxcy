// kuangfeng-jianfa ��罣��
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N�ս�����$wһ��[37m��������⡹[0m����$n��$l",
        "force" : 50,
        "dodge" : 40,
        "damage" : 20,
        "skill_name" : "��������⡹",
        "lvl"    : 0,
        "damage_type" : "����"
]),
([      "action" : "$Nһ��[1;34m�����ذ���[0m������$w���´̳���ֱ��$n��ȥ",
        "force" : 70,
        "dodge" : 10,
        "damage" : 30,
        "skill_name" : "�����ذ���",
        "lvl"    : 20,
        "damage_type" : "����"
]),
([      "action" : "$N��ǰ����һ��������$wʹ��[1;33m���������[0mֱ��$n�ĺ�",
        "force" : 90,
        "dodge" : 80,
        "damage" : 60,
        "skill_name" : "���������",
        "lvl"    : 40,
        "damage_type" : "����"
]),
([      "action" : "$N���һ����ʹ��[36m��������ʵ��[0m����$wֱ��$n�ĺ�",
        "force" : 90,
        "dodge" : 80,
        "damage" : 80,
        "skill_name" : "��������ʵ��",
        "lvl"    : 60,
        "damage_type" : "����"
]),
([      "action" : "ֻ��$N�������е�$w��ʹ��[31m��[1;33m��[1;35mâ[35m��[1;31m��[31m��[0m�����ֱ��$n",
        "force" : 90,
        "dodge" : 70,
        "damage" : 100,
        "skill_name" : "����â���ɡ�",
        "lvl"    : 80,
        "damage_type" : "����"
]),
([      "action" : "$N�������е�$w��ʹ��[1;35m������ҽ���[0m��������ֱ��$n",
        "force" : 120,
        "dodge" : 60,
        "damage" : 140,
        "skill_name" : "������ҽ���",
        "lvl"    : 100,
        "damage_type" : "����"
]),
([      "action" : "$Nʹ��[37m�������硹[0m������$w�������һ����˸����������$n",
        "force" : 200,
        "dodge" : 100,
        "damage" : 130,
        "skill_name" : "�������硹",
        "lvl"    : 120,
        "damage_type" : "����"
]),
([      "action" : "$Nʹ����罣��֮����[37m�������Ű��[0m������$w�������һ������ǵصĴ���$n",
        "force" : 500,
        "dodge" : 200,
        "damage" : 200,
        "lvl"    : 501,
        "skill_name" : "�������Ű��",
        "damage_type" : "����"
]),
([      "action" : HIY"$Nʹ����罣��֮���վ������˽���һ���������˻���һ�ѽ𽣷���$n"NOR,
        "force" : 500,
        "dodge" : 400,
        "damage" : 400,
        "lvl"    : 801,
        "skill_name" : HIY"���˽���һ��"NOR,
        "damage_type" : "����"
]),



});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query_skill("zhenfeng-xinfa", 1) < 80)
                return notify_fail("��ġ�����ķ�����򲻹����޷�ѧ����罣������\n");
        if ((int)me->query("max_neili") < 500)
                return notify_fail("�������̫�����޷�������罣������\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
/*
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
*/
mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("kuangfeng-jianfa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];

}
int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("�����������������罣������\n");
        if ((int)me->query("neili") < 50)
                return notify_fail("�����������������罣������\n");
        me->receive_damage("qi", 40);
        me->add("neili",-15);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"kuangfeng-jianfa/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 100 ) return 0;

        if( random(damage_bonus/2) > victim->query_str() ) {
//                victim->add("qi", 1 - damage_bonus - 100 * 3 );
                victim->receive_wound("qi", (damage_bonus - 100) / 2 );
                return HIR "��������ৡ�һ�����������һ��紵������Ȼ��$nѪð���ɣ���$N�������ˣ�\n" NOR;
        }
}



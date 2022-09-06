// meinu-quan ��Ůȭ��
#include <ansi.h>;
inherit SKILL;

mapping *action = ({
([      "action" : "$Nʹһ�С��������¡�������һ�ӣ���$n��$l��ȥ����Ե��$n��$lһն",
        "force" : 150,
        "dodge" : 30,
        "skill_name" : "��������",
        "lvl" : 0,
        "damage_type" : "ն��"
]),
([      "action" : "$N˫ȭ���أ���������ʹһ�С���ʩ���ġ�����$n��$l��ȥ",
        "force" : 250,
        "dodge" : 25,
        "skill_name" : "��ʩ����",
        "lvl" : 10,
        "damage_type" : "����"
]),
([      "action" : "$N����б�٣�������ָ���𣬷��Ƶ�ϰ����һ�㣬���Ѿ���������ָ�ַ���
$n��ȥ", 
        "force" : 300,
        "dodge" : 20,
        "skill_name" : "�Ѿ�����",
        "lvl" : 20,
        "damage_type" : "����"
]),
([      "action" : "$N����һ����˫�ֺ�ȭ����̧ȥ��һ�С�������١�����$n���°�",
        "force" : 320,
        "dodge" : 15,
        "skill_name" : "�������",
        "lvl" : 30,
        "damage_type" : "ײ��"
]),
([      "action" : "$Nʩ������Ů֯�󡹣����ֻ����������ң���Ͷ��֯��֮״��һ��һ�ͣ�
����$l",
        "force" : 370,
        "dodge" : 10,
        "skill_name" : "��Ů֯��",
        "lvl" : 50,
        "damage_type" : "����"
]),
([      "action" : "$Nʩ�������촹����������ǰ�ˣ�˫���Դ���֮������������ն��$n��˫��",
        "force" : 150,
        "dodge" : 30,
        "skill_name" : "���촹��",
        "lvl" : 70,
        "damage_type" : "����"
]),
([      "action" : "$N��¶΢Ц��������ͷ��һ�ᣬ��ָ�硸������ױ��������ӽ���ȥ������$n
���ؿ�",
        "force" : 250,
        "dodge" : 25,
        "skill_name" : "������ױ",
        "lvl" : 90,
        "damage_type" : "����"
]),
([      "action" : "$N˫�ֻ��ģ�����������ٲȻһ�С�������ġ����ַ�����$n$l",
        "force" : 300,
        "dodge" : 20,
        "skill_name" : "�������",
        "lvl" : 110,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�Ū�����һָ���죬һָ�Եأ���Ŀ���ף���Ȼ�������������
$nȫ��Ҫ��",
        "force" : 500,
        "dodge" : 5,
        "skill_name" : "Ū����",
        "lvl" : 120,
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("���ַ�����ϰ��Ůȭ����\n");
if (me->query("gender") != "Ů��") 
return notify_fail("���޷������Ůȭ���ľ�Ҫ��\n");
        if ((int)me->query_skill("yunu-xinjing", 1) < 10)
                return notify_fail("��Ů�ľ����򲻹����޷���ϰ��Ůȭ����\n");
        if ((int)me->query_skill("dodge", 1) < 20)
                return notify_fail("����Ṧ̫��޷�����Ůȭ����\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon,object ob)
{
        int i, level;         
        level = (int) me->query_skill("meinu-quanfa",1);         
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("���������������Ůȭ���ˡ�\n");
        me->receive_damage("qi", 25);
        me->add("neili", -5);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        string msg;
        int level= (int) me->query_skill("meinu-quanfa",1);  
        if( damage_bonus < 100 ) return 0;
        if ((me->query_per()) > 24 && random(10) > 5 &&
          level > 120 && me->query("neili") > 500 && !victim->is_busy()){
           msg= HIY"\n$N��������������֧�ã���������ӳ�����̾һ�������ּ���֮�⡣\n"NOR;
        if (random(me->query_per()) > random(victim->query_per()) /3 * 2){
           me->add("neili", -30);
           victim->start_busy(random(10));
           msg +=CYN"\n$n��$N�ĸ�Ⱦ������ԭ�������۷�ֱ��һ��������\n\n"NOR;
           }
       else {
           me->add("neili", -10);
           me->start_busy(random(2));
           msg +=CYN"\n���$n��$N�ı����޶����ԡ�\n\n"NOR;
           }
         message_vision(msg, me, victim);
         return;
         }

}
string perform_action_file(string action)	
{
return __DIR__"meinu-quanfa/" + action;	
}

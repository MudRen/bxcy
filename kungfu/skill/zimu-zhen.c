// zimu-zhen.c ��ĸ�뷨

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"action":		"$N˫���������裬һ�С������롹��$wֱ��$n���ظ�Ҫ��",
	"dodge":		-10,
	"damage":		200,
	"poison": 30,
	"lvl" : 0,
	"skill_name" : "������",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"����"
]),
([	"action":		"$N���λζ���һ�С������롹������$w��һ�����ߣ���$n�ʺ��ȥ",
	"dodge":		-20,
	"damage":		300,
	"poison": 40,
	"lvl" : 60,
	"skill_name" : "������",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"����"
]),
([	"action":		"$N��ָ΢�ţ�һ�С���Ѫ�롹������$w���ð���$nȫ��ȥ",
	"dodge":		-40,
	"damage":		400,
	"poison": 50,
 	"lvl" : 90,
	"skill_name" : "��Ѫ��",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"����"
]),
([	"action":		"$N���һ����һ�С�����롹��$w�û�����Ŀ����������$n",
	"dodge":		-50,
	"damage":		500,
	"poison": 60,
	"lvl" : 100,
	"skill_name" : "�����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"����"
]),
([	"action":		"$N��һԾ��һ�С������롹��$w�����������磬����$nȫ��",
	"dodge":		-60,
	"damage":		600,
	"poison": 70,
 	"lvl" : 110,
	"skill_name" : "������",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"����"
]),
([	"action":		"$N˫Ŀ��â������һ�С�����롹������$wȫ�����ַɳ�����ɽ���������$nȫ��",
	"dodge":		-60,
	"damage":		700,
	"poison": 80,
	"lvl" : 120,
	"skill_name":  "�����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"����"
]),
([	"action":		"$N������Х��һ�С���ħ�롹��$w��Ȼ����һ��ǿ�Ҿ��磬ɨ��$n",
	"dodge":		-70,
	"damage":		800,
	"poison": 90,
	"lvl" : 130,
	"skill_name" : "��ħ��",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"����"
]),
([	"action":		"$N����ɱ��ͻȻ��ʢ��һ�С���ɷ�롹��$w�ɻȰ����$nȫ��",
	"dodge":		100,
	"damage":		900,
	"poison": 100,
	"lvl" : 200,
	"skill_name" : "��ɷ��",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"����"
]),
});

int valid_enable(string usage) { return (usage == "throwing") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if( (int)me->query("max_neili") < 500 )
		return notify_fail("�������������ĸ������, �ٶ������ɡ�\n");

	if ((int)me->query_skill("biyun-xinfa", 1) < 100)
		return notify_fail("��ı����ķ����̫ǳ��\n");

	if ( !objectp(weapon = me->query_temp("weapon"))
	|| ( string)weapon->query("skill_type") != "throwing" )
		return notify_fail("�����ϲ�û�а�������ô����\n");

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
	level   = (int) me->query_skill("zimu-zhen",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("���������������ĸ�뷨��\n");
	me->receive_damage("qi", 5);
	return 1;
}

string perform_action_file(string action)
{
	if ( this_player()->query_skill("zimu-zhen", 1) >= 50 )
		return __DIR__"zimu-zhen/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{object weapon;weapon=me->query_temp("weapon");
              
        if(weapon->query("name")=="��ĸ����" && weapon->query("id")=="zimuzhen" && me->query_temp("marks/��ĸ��") ){
          victim->apply_condition("zm_poison", random(me->query_skill("zimu-zhen")) + 10 +
	  victim->query_condition("zm_poison"));
	}
}

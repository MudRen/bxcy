//  ��Ȼ������
//  fyue-quan.c

#include <ansi.h>;
inherit SKILL;

mapping *action = ({
([      "action" : 
HIG"�ľ�����\n\n"
"$N���۸��ᣬ��ĿԶ���������鸡����ǰ�Ż�����������$n�۽�֮ʱ��$N��С�����������\nͬʱ�ؿ�����һ����ٿ�ص���"NOR,
	"force" : 240,
        "dodge" : 20,
        "parry" : 20,
	"damage": 150000,
	"lvl" : 5,
	"skill_name" : "�ľ�����",
        "damage_type" : "����"
]),
([	"action" : 
HIC"�������\n\n"
"$Ņͷ���죬����һ�����Լ�ͷ���տ��ĳ�������б�£��������ɻ��Σ���ɢ���¡������®��Բת�㱻"NOR,
	"force" : 280,
        "dodge" : 30,
        "parry" : 30,
	"damage": 250000,
	"lvl" : 15,
	"skill_name" : "�������",
        "damage_type" : "����"
]),
([	"action" : 
HIW"��������\n\n"
"$N�ֱ��´������ް�������ʽ������$n�����������ͻȻ�������붯���������䡢˫��ͷ����\n�����ر�������������ʽ��������һ�������˵�"NOR,
	"force" : 320,
        "dodge" : 40,
        "parry" : 40,
	"damage": 400000,
	"lvl" : 30,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : 
HIR"�����ˮ\n\n"
"$N��������Ʈ����������ˮ������ȴ����֮�������ƴ��ż�ǧ����ɳһ�㣬������$n��ȥ"NOR,
	"force" : 360,
        "dodge" : 50,
        "parry" : 50,
	"damage": 500000,
	"lvl" : 40,
	"skill_name" : "�����ˮ",
        "damage_type" : "����"
]),
([	"action" : 
HIY"������ʩ\n\n"
"$NͻȻͷ�½��ϣ��������ӣ��ĳ�һ�ƣ��˵��ǳ�����ʤ"NOR,
	"force" : 400,
        "dodge" : 60,
        "parry" : 60,
	"damage": 650000,
	"lvl" : 55,
	"skill_name" : "������ʩ",
        "damage_type" : "����"
]),
([	"action" : 
CYN"¹��˭��\n\n"
"$N����ǰ���������ȣ��Կ������һ��ת���Ѿ�ת����$n�����һ������$n�Ĵ�׵Ѩ"NOR,
	"force" : 440,
        "dodge" : 70,
        "parry" : 70,
	"damage": 800000,
	"lvl" : 70,
	"skill_name" : "¹��˭��",
        "damage_type" : "����"
]),
([	"action" : 
HIB"�ǻ��չ�\n\n"
"$N�������ߣ���������Ŀ�ģ�ͻȻ����Ծ�𣬻ó�ǧ����Ӱ����$n��������"NOR,
	"force" : 460,
        "dodge" : 80,
        "parry" : 80,
	"damage": 900000,
	"lvl" : 80,
	"skill_name" : "�ǻ��չ�",
        "damage_type" : "����"
]),
([	"action" : 
MAG"������ɫ\n\n"
"$N����ϲŭ���֣���״�ٳ���$nһ��֮�¶�ʱ������ң��������ƣ����ϵ���ʽ��������\n������������$N�û�����ǰ��һ�ƻ���$n"NOR,
	"force" : 500,
        "dodge" : 90,
        "parry" : 90,
	"damage": 1000000,
	"lvl" : 100,
	"skill_name" : "������ɫ",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry" ; }

int valid_combine(string combo) { return combo=="meinv-quanfa"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����Ȼ�����Ʊ�����֡�\n");
	if ((int)me->query_skill("zixia-shengong", 1) < 20)
		return notify_fail("�����ϼ�񹦻�򲻹����޷�ѧ��Ԫ�ơ�\n");
	if ((int)me->query("max_neili") < 300)
		return notify_fail("�������̫�����޷�����Ȼ�����ơ�\n");
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
	level   = (int) me->query_skill("fyue-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 60)
		return notify_fail("���������������Ȼ�����ơ�\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"fyue-quan/" + action;
}


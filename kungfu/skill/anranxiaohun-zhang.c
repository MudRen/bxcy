//anranxiaohun-zhang.c ��Ȼ������
// By Kayin @ CuteRabbit Studio 99-4-16 16:22 new

inherit SKILL;
#include <ansi.h>
mapping *action = ({
([	"action" : "$Nһ��"HIW" ������� "NOR"̧ͷ���죬��������������һ�����Լ�ͷ���տ��ĳ�������б�£��������ɻ��Σ���ɢ��������$n��$l��",
	"force" : 200,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"dodge" : (int)this_player()->query_skill("dodge"),
	"damage" : (int)this_player()->query("age")*10,
	"lvl" : 0,
	"skill_name" : "�������",
	"damage_type" : "����"
]),
([	"action" : "$Nһ��"HIG" �������� "NOR"�ֱ��´������ް�������ʽ��ͻȻ�������붯���������䡢˫��ͷ���������ر�������������ʽ����ײ��$n.",
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"dodge" : (int)this_player()->query_skill("dodge"),
	"force" : 300,
	"damage" : (int)this_player()->query("age")*11,
	"lvl" : 10,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$Nһ��"HIB" �����ˮ "NOR"��������Ʈ����������ˮ������ȴ����֮�������ƴ��ż�ǧ����ɳһ�㣬�����빥$n��",
	"force" : 400,
	"dodge" : (int)this_player()->query_skill("dodge"),
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*12,
	"lvl" : 20,
	"skill_name" : "�����ˮ",
	"damage_type" : "����"
]),

([	"action" : "$Nһ��"HIY" �������� "NOR"�����ո���ͷ�������£��Ų����ص�����$n,���������������$n��$l��",
	"force" : 500,
	"damage" : (int)this_player()->query("age")*13,
	"dodge" : (int)this_player()->query_skill("dodge"),
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"lvl" : 30,
	"skill_name" : "��������",
    "damage_type" : "����"
]),
([	"action" : "$Nһ��"HIR" ��ʬ���� "NOR"�߳�һ�š���һ�ŷ���ʱ�л��㱣�����ԼԼ���������޵�����$n",
	"force" : 600,
	"damage" : (int)this_player()->query("age")*14,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"dodge" : (int)this_player()->query_skill("dodge"),
	"lvl" : 40,
	"skill_name" : "��ʬ����",
	"damage_type" : "����"
]),
([	"action" : "$N˫��ƽ�У�һ��"HIM" ӹ������ "NOR"û����ɵ�����$n��$l.",
	"force" : 700,
	"dodge" : (int)this_player()->query_skill("dodge"),
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*15,
	"lvl" : 50,
	"skill_name" : "ӹ������",
            "damage_type" : "����"
]),
([	"action" : "$Nһ��"RED" ������ʩ "NOR"ͻȻ�������࣬ͷ�½��ϣ��������ӣ�һ������$n��$l",
	"force" : 800,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"dodge" : (int)this_player()->query_skill("dodge"),
	"damage" : (int)this_player()->query("age")*16,
	"lvl" : 60,
	"skill_name" : "������ʩ",
	"damage_type" : "����"
]),
([	"action" : "$Nһ��"YEL" �ľ����� "NOR"��ĿԶ���������鸡����ǰ�Ż�������ȫ����ʽ����ѧ�и������޲��Ǻϡ�",
	"force" : 900,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"dodge" : (int)this_player()->query_skill("dodge"),
	"damage" : (int)this_player()->query("age")*17,
	"lvl" : 70,
	"skill_name" : "�ľ�����",
           "damage_type" : "����"
]),
([	"action" : "$Nһ��"BLU" ������ʳ "NOR"�����鸡�����缸�첻�Բ�˯��ĽŲ��ʲյ�Ϯ��$n�����ԣ�������ȭ����$n��$l��",
	"force" : 1000,
	"dodge" : (int)this_player()->query_skill("dodge"),
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*18,
	"lvl" : 80,
	"skill_name" : "������ʳ",
           "damage_type" : "����"
]),
([	"action" : "$Nһ��"HIC" �ǻ��չ� "NOR"���Ҵ�����ʵʵ�Ĺ���$n��$l��",
	"force" : 1100,
	"dodge" : (int)this_player()->query_skill("dodge"),
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*19,
	"lvl" : 90,
	"skill_name" : "�ǻ��չ�",
           "damage_type" : "����"
]),
([	"action" : "$Nһ��"CYN" �������� "NOR"����������״������бб����$n��$l��",
	"force" : 1200,
	"dodge" : (int)this_player()->query_skill("dodge"),
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*20,
	"lvl" : 100,
	"skill_name" : "��������",
           "damage_type" : "����"
]),
([	"action" : "$Nһ��"MAG" ���񲻰� "NOR"�������ݼ�ת��չ���ṦΧ��$n�������ߣ���Ȼ�����������$n��$l��",
	"force" : 1300,
	"dodge" : (int)this_player()->query_skill("dodge"),
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*21,
	"lvl" : 110,
	"skill_name" : "���񲻰�",
           "damage_type" : "����"
]),
([	"action" : "$Nһ��"WHT" ��;ĩ· "NOR"����$n���ԣ����ƾٵ���ǰƽ�ƶ�������������бб����$n��$l��",
	"force" : 1400,
	"dodge" : (int)this_player()->query_skill("dodge"),
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*22,
	"lvl" : 120,
	"skill_name" : "��;ĩ·",
           "damage_type" : "����"
]),
([	"action" : "$Nһ��"HIY" ����ľ�� "NOR"˫Ŀֱֱ�Ķ���$n�����嶯Ҳ����һ�µķ���$n",
	"force" : 1500,
	"dodge" : (int)this_player()->query_skill("dodge"),
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*23,
	"lvl" : 130,
	"skill_name" : "����ľ��",
           "damage_type" : "����"
]),
([	"action" : "$N��ͷڤ�룬һ��"HIB" ������ʧ "NOR"��������ƽƽ����$n��$l��",
	"force" : 1600,
	"dodge" : (int)this_player()->query_skill("dodge"),
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*24,
	"lvl" : 140,
	"skill_name" : "������ʧ",
           "damage_type" : "����"
]),
([	"action" : "$Nһ��"HIB" ��ͨ�˴� "NOR"˫�ƻγ�ǧ����Ӱ��$n����������֮�¡�",
	"force" : 1700,
	"dodge" : (int)this_player()->query_skill("dodge"),
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*25,
	"lvl" : 150,
	"skill_name" : "��ͨ�˴�",
           "damage_type" : "����"
]),
([	"action" : "$N����ǰ��һ��"HIB" ¹��˭�� "NOR"�������ȣ��Կ������һ��ת���Ѿ�ת����$n�������ָ������$n�Ĵ�׵Ѩ��",
	"force" : 1800,
	"dodge" : (int)this_player()->query_skill("dodge"),
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*26,
	"lvl" : 160,
	"skill_name" : "¹��˭��",
           "damage_type" : "��Ѩ"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_combine(string combo) { return combo=="anranxiaohun-zhang"; }

int valid_learn(object me)
{
	if(!me->query("couple/have_couple")) 
		return notify_fail("�㻹û���������ˣ�����������еľ�Ҫ��\n");
if (me->query_skill("anranxiaohun-zhang", 1) >= 300)
return notify_fail("�������Ȼ���������Լ��ڼ���ϰ����\n");
	if (me->query("gender") != "����") 
                return notify_fail("����᲻������˼��һ���˵����顣\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����Ȼ�����Ʊ�����֡�\n");
if ((int)me->query("max_neili") < 30000)	
		return notify_fail("�������̫�����޷�����Ȼ�����ơ�\n");
	if ((int)me->query_str()< 40)
		return notify_fail("��ı���̫�����޷�����Ȼ�����ơ�\n");	
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("anranxiaohun-zhang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 50, level)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
if (me->query_skill("unarmed", 1) <= me->query_skill("anranxiaohun-zhang",1))
return notify_fail("��Ļ����������޷���ϰ��Ȼ�����ơ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("���������������Ȼ�����ơ�\n");
	me->receive_damage("qi", 25);
	me->add("neili", -30);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 100 ) return 0;

	if( damage_bonus/2 > victim->query_str() ) {
		victim->receive_wound("qi", (damage_bonus - 100) / 2 );
		return HIR "ֻ�������ۡ���һ����"+ victim->name()+"�����һ�����Ѫ��\n" NOR;
	}
}
string perform_action_file(string action)
{
	return __DIR__"anranxiaohun-zhang/" + action;
}

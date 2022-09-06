// jinding-mianzhang.c -������
// create bye cuer
inherit SKILL;
mapping *action = ({
([	"action" : "$Nһʽ��������̩���������أ�����Ʈ����ͻȻһ���߳����������Ҽл�������$n",
	"force" : 200,
        "dodge" : 5,
	"damage_type" : "����",
	"lvl" : 0,
	"skill_name" : "������̩"
]),
([	"action" : "$Nһʽ���������项�����ƻ�һ��Բ����ס�ؿڣ�������˿����������$n��������",
	"force" : 220,
        "dodge" : 5,
        "damage_type" : "����",
	"lvl" : 9,
	"skill_name" : "��������"
]),
([	"action" : "$N�����������಻������ǰ�Ƴ���һ���������Ʒ�Ϯ��$n��ǰ�أ�����һʽ������ơ�",
	"force" : 240,
        "dodge" : 5,
        "damage_type" : "����",
	"lvl" : 19,
	"skill_name" : "�����"
]),
([	"action" : "$N���һ�㣬����ǰ����һʽ��������ɳ����������$n��ǰ����ȥ",
	"force" : 260,
        "dodge" : -5,
        "damage": 5,
        "damage_type" : "����",
	"lvl" : 29,
	"skill_name" : "������ɳ"
]),
([	"action" : "$N����һ����ʹһʽ���׶���������ȫ�������ת��˫��һǰһ��ȫ������$n���ؿ�",
	"force" : 280,
        "dodge" : 5,
        "damage_type" : "����",
	"lvl" : 39,
	"skill_name" : "�׶�����"
]),
([	"action" : "$N΢һ������һʽ���𶥷�⡹��Ծ����У�˫���ĳ�������Ӱ��Ʈ��$n",
	"force" : 300,
        "dodge" : 5,
        "damage_type" : "����",
	"lvl" : 49,
	"skill_name" : "�𶥷��"
]),
([	"action" : "$Nһ�����ݣ�˫�۹۱ǣ����ֺ�ʲ��һ�С����Ľ�ħ�������ַ�ת��$n�����Ƴ�",                       
	"force" : 300,
        "dodge" : 5,
        "damage": 5,
        "damage_type" : "����",
	"lvl" : 69,
	"skill_name" : "���Ľ�ħ"
]),
([	"action" : "$Nʹһʽ������˻ġ���Ʈ���գ�˫�ƻ���ԲȦ��������Ӱ������$n��ȫ��",
	"force" : 400,
        "dodge" : 10,
        "damage": 10,
        "damage_type" : "����",
	"lvl" : 109,
	"skill_name" : "����˻�"
])
});
int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }
int valid_combine(string combo) { return combo=="tiangang-zhi"; }
int valid_learn(object me)
{       
        if (me->query("class")!="bonze" && (int)me->query_skill("jinding-mianzhang",1) >99 )
                return notify_fail("�����㲻�Ƿ������ˣ��������������������Ƶľ���֮����\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������Ʊ�����֡�\n");
	if ((int)me->query_skill("linji-zhuang", 1) < 10)
		return notify_fail("����ټ�ʮ��ׯ��򲻹����޷�ѧ�����ơ�\n");
	if ((int)me->query("max_neili") < 20)
		return notify_fail("�������̫�����޷��������ơ�\n");
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
	level = (int)me->query_skill("jinding-mianzhang", 1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
	if (me->query("class")!="bonze" && (int)me->query_skill("jinding-mianzhang",1) >99 )
                return notify_fail("�����㲻�Ƿ������ˣ������������������ķ����书��\n");
        if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("������������������ơ�\n");
	me->receive_damage("qi", 25);
	me->add("neili", -5);
	return 1;
}

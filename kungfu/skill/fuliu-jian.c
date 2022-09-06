// fuliu-jian.c �ط������
//create bye cuer
inherit SKILL;
mapping *action = ({
([	"action" : "$N������裬һ�С����Ϯ�¡�������$w���������һ��������$n��$l",
	"force" : 180,
	"dodge" : 20,
	"damage" : 40,
        "lvl" : 0,
	"damage_type" : "����"
]),
([	"action" : "$N̨�����죬����$wʹ��һʽ��Ʈѩ���ơ�Ʈ�������Ĵ���$n��$l",
	"force" : 100,
	"dodge" : 15,
	"damage" : 10,
        "lvl" : 0,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�ǧ�徺�㡹������$w������������ؽ�Ӱ��ƽƽ����$n��$l��ȥ",
	"force" : 120,
	"dodge" : 15,
	"damage" : 30,
        "lvl" : 9,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С��������ڡ�������$w���������ؽ�Ӱ�϶�Ϊһ��һ���ǳɵع���$n��$l",
	"force" : 130,
	"dodge" : 10,
	"damage" : 40,
        "lvl" : 29,
	"damage_type" : "����"
]),
([	"action" : "$Nʹ����������������$w���������Ĺ�Ȧ�������������ת����$n��$l",
	"force" : 140,
	"dodge" : 5,
	"damage" : 60,
        "lvl" : 39,
	"damage_type" : "����"
]),
([	"action" : "$N���̤ʵ���ҽ���㣬һ�С�������ɳ��������$w����һ�Ž���������$n��$l",
	"force" : 150,
	"dodge" : 5,
	"damage" : 80,
        "lvl" : 59,
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�����������������$w΢����$w������˸��������ʵ��������$n��$l",
	"force" : 200,
	"dodge" : -5,
	"damage" : 90,
        "lvl" : 79,
	"damage_type" : "����"
]),
([	"action" : "$N����΢һ��أ�Ծ���գ�һ�С���غ��衹��������£�����ֱָ$n��$l",
	"force" : 200,
	"dodge" : -5,
	"damage" : 100,
        "lvl" : 99,
	"damage_type" : "����"
])
});
int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }
int valid_combine(string combo) {return combo=="yanxing-dao";}
int valid_learn(object me)
{
	if (me->query("class")!="bonze" && (int)me->query_skill("fuliu-jian",1) >99 )
                return notify_fail("�����㲻�Ƿ������ˣ����������������ط�������ľ���֮����\n");
        if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("linji-zhuang", 1) < 20)
		return notify_fail("����ټ�ʮ��ׯ���̫ǳ��\n");
	if ((int)me->query_skill("jinding-mianzhang", 1) < 20)
		return notify_fail("��Ľ����ƻ��̫ǳ��\n");
	return 1;
}
mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("fuliu-jian",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
	object weapon;
        if (me->query("class")!="bonze" && (int)me->query_skill("fuliu-jian",1) >99 )
                return notify_fail("�����㲻�Ƿ������ˣ������������������ķ����书��\n");
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("��������������ط����������\n");
	me->receive_damage("qi", 30);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"fuliu-jian/" + action;
}

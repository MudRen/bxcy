// qingdie-shenfa.c �����
// pal 1997.05.26

inherit SKILL;

string *dodge_msg = ({
	"ֻ��$nһ�С�����Ȫ�ߡ�������Ʈ�������������$N��һ�С�\n",
	"$nһʽ��ƾ���ٷ硹�����λζ�����һ��Ʈ�����ܿ���$N��һ�С���\n"
	"$nʹ���������ɡ���һ�����Ľ��󷭳����ܿ���$N���������ơ�\n",
	"$nһ�С�˫��������������ת��$Nֻ����ǰһ����$n������$N�����\n",
});

int valid_enable(string usage)
{
	return (usage == "dodge") || (usage == "move");
}

int valid_learn(object me)
{
	if(me->query_skill("dodge",1)<20)
		return notify_fail("��Ļ����Ṧ��򲻹���\n");
	return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("�������̫���ˣ���������������\n");
        me->receive_damage("qi", 30);
        return 1;
}


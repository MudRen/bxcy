// pmshenfa.c Ʈ����
// written by Xiang

inherit SKILL;

string *dodge_msg = ({
        "ֻ��$n������ת��һŤ����Ʈ��$N���󣬶������һ�С�\n",
        "$n������ħ������Ӱ���缲�����ܣ���$N�Ĺ���ȫ����ա�\n",
        "$Nֻ����ǰһ����$n�ѻû�������������ɢ���䡣\n"
        "$n��Ӱͻ�����ݼ�ת���γ����ҵ��������У�������ǽ��$N�����޴����֡�\n",
});

int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("�������̫���ˣ�������Ʈ������\n");
        me->receive_damage("qi", 30);
        return 1;
}

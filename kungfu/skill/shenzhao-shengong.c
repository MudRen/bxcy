// shenzhao-shengong ������


// inherit ;


inherit FORCE;
int valid_enable(string usage) {return usage == "force"; }


int valid_learn(object me)
{
	int lvl = (int)me->query_skill("shenzhao-shengong", 1);
	int t = 1, j;
	if (lvl<=100)
		for (j = 1; j < lvl / 10; j++)
			t*=2;


	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ���򻹲�����\n");

	return 1;

}

int practice_skill(object me)
{
	return notify_fail("������ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"shenzhao-shengong/" + func;
}
string perform_action_file(string action)
{
	return __DIR__"shenzhao-shengong/" + action;
}

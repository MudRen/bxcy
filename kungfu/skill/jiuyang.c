// jiuyang-shengong.c ������
// cleansword

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("jiuyang", 1);

				    
	if ( me->query("gender") == "����" && lvl > 49)
		return notify_fail("���޸����ԣ���������������������ľ����񹦡�\n");

	if ((int)me->query_skill("force", 1) < 30)
		return notify_fail("��Ļ����ڹ���򻹲������޷��������񹦡�\n");



	return 1;
}

string exert_function_file(string func)
{
	return __DIR__"jiuyang/" + func;
}

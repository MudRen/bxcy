// quanzhen-xinfa.c  ȫ���ķ�

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
	int i, nk, nf, nh, ns, ts;
	nk = (int)me->query_skill("kurong-changong", 1);
	nf = (int)me->query_skill("force", 1);
	nh = (int)me->query_skill("quanzhen-xinfa", 1);
	ns = (int)me->query("guilty");

	if ( nf < 200)
		return notify_fail("��Ŀ���������򻹲������޷����ȫ���ķ���\n");

	if ( ns > 0 ) 
		return notify_fail("���ŷ�ɮ�����䣬�޷����������ȫ���ķ���\n");

        if ( me->query("gender") == "����" && lvl > 49)
		return notify_fail("���޸����ԣ����������������������ȫ���ķ���\n");

	return 1;
}


int practice_skill(object me)
{
     	return notify_fail("ȫ���ķ�ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return "/kungfu/skill/quanzhen-xinfa/" + func;
}

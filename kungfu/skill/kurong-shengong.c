// kurong-shengong.c ������
// by jackyboy@cctx

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("kurong-shengong", 1);

	if ( me->query("gender") == "����" && lvl > 49)
		return notify_fail("���޸����ԣ���������������������Ŀ����񹦡�\n");
	if ( me->query_skill("force",1)<100)
		return notify_fail("��Ļ����ڹ���򲻵����޷���ϰ�����񹦡�\n");
	if ( me->query_skill("tianlong-shengong",1)<40)
		return notify_fail("����������������Ϊ�����ģ�����������������񹦡�\n");
	return 1;
}

int practice_skill(object me)
{
    return notify_fail("������ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}


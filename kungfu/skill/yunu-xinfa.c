// yunu-xinfa.c ��Ů�ķ�
// Kayin @ CuteRabbit 1999/3/13 new

inherit FORCE;
int valid_enable(string usage) { return usage == "force"; }
int valid_learn(object me)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "��Ĺ��"))
		return notify_fail("�㲻�ǹ�Ĺ�ɵĵ���,����ѧϰ��Ů�ľ�?\n");

	if(me->query("gender") ==! "Ů��")
		return notify_fail("�����һ�������������Ժ���ԭ���㲻��Ů�ģ��޷������������֮��\n");

	if ( me->query_skill("bibo-shengong",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("biyun-xinfa",1)
	|| me->query_skill("xuedao-xinfa",1)
	|| me->query_skill("shenzhao-shengong",1)
	|| me->query_skill("tianlong-shengong",1)
	|| me->query_skill("bahuang-gong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
  	|| me->query_skill("jiuyang-shengong",1)
  	|| me->query_skill("xiantian-gong",1)
  	|| me->query_skill("wudu-xinfa",1)
  	|| me->query_skill("hunyuan-yiqi",1)
  	|| me->query_skill("yijing-force",1)
	|| me->query_skill("longxiang",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yunlong-shengong",1)
	|| me->query_skill("zixia-shengong",1)
	|| me->query_skill("taiji-shengong",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��Ů�ķ�����\n");

	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("��Ů�ķ�ֻ�ܿ�ѧϰ(learn)����ߡ�\n");
}
string exert_function_file(string func)
{
	return __DIR__"yunu-xinfa/" + func;
}

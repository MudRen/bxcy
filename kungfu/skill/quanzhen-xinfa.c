// quanzhen-xinfa.c  全真心法

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
		return notify_fail("你的枯荣禅功火候还不够，无法领会全真心法。\n");

	if ( ns > 0 ) 
		return notify_fail("你屡犯僧家数戒，无法领会更高深的全真心法。\n");

        if ( me->query("gender") == "无性" && lvl > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的全真心法。\n");

	return 1;
}


int practice_skill(object me)
{
     	return notify_fail("全真心法只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return "/kungfu/skill/quanzhen-xinfa/" + func;
}

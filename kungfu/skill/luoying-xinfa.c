// luoying-xinfa.c ��Ӣ�ķ�
// written by deaner
// modified by Venus Oct.1997
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
    return 1;
}

int practice_skill(object me)
{
    return notify_fail("��Ӣ�ķ�ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
    return SKILL_D("luoying-xinfa/") + func;
}
// huashan-neigong.c ��ɽ�ڹ�
// Modified by Venus Oct.1997

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
    int i = (int)me->query_skill("huashan-neigong", 1);
    if ((int)me->query_skill("zixia-shengong", 1) < 10)
   return notify_fail("�����ϼ�񹦻�򻹲�����\n");
//    if ((int)me->query("shen") < (int)pow(i/10, 2) * 100)
//   return notify_fail("�����̫���ˡ�\n");
    return 1;
}

int practice_skill(object me)
{
    return notify_fail("��ɽ����ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
    return SKILL_D(__DIR__"huashan-neigong/") + func;
}


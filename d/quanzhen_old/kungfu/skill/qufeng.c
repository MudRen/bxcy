// qufeng.c ����֮��
// By Lgg,1998.9

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int practice_skill(object me)
{	
	return notify_fail("����֮��ֻ�ܿ�ѧϰ����ߡ�\n");
}

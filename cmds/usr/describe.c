// describe.c
inherit F_CLEAN_UP;
int help(object me);
int main(object me, string arg)
{
	string *txt;
	if (!arg || arg=="?" || arg=="/?")	return help(me);
	txt = explode(arg, "\n");
	if( sizeof(txt) > 8 )
		return notify_fail("�뽫�����Լ������������ڰ������ڡ�\n");
	arg = implode(txt, "\n") + "\n";
	me->set("long", arg);
	write("Ok.\n");
	return 1;
}
int help(object me)
{
	write(@TEXT
ָ���ʽ��describe <����>
���ָ�������趨�������� look ָ���ʱ�������������ͨ������
����������һ��ʱ������ to describe �ķ�ʽ�����롣
TEXT
	);
	return 1;
}

// expell.c
inherit F_CLEAN_UP;
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
	object ob;
	int i;
	if( !arg || !ob = present(arg, environment(me)) )
		return notify_fail("��Ҫ����˭�����ݣ�\n");
	if( !ob->is_character() )
		return notify_fail("���𲻶�����\n");
	if( !userp(ob) )
		return notify_fail("��ֻ��������������ݵ�����Ȩ����\n");
	if((int)me->query("guild/tisheng")>=2)
		return notify_fail("�����ĳ����Ѿ����ˡ�\n");
if((int)ob->query("guild/generation")==2)
		return notify_fail("" + ob->name() + "�Ѿ��������ĳ����ˡ�\n");
	if( (int)me->query("guild/generation")<2
	&&	(string)me->query("guild/name")==(string)ob->query("guild/name") ) {
		message_vision("\n$N����$n˵�����ӽ������������"
			+ me->query("guild/name") + "�ĳ����ˣ��úøɣ�\n\n",
			me, ob);
		tell_object(ob, "\n" + me->name() + "�����Ȩ������Ϊ���ϡ�\n\n");
	} else
		return notify_fail("����˲������С�ܡ�\n");
	ob->set("guild/generation",2);
	me->add("guild/tisheng",1);
	return 1;
}
int help(object me)
{
	write(@HELP
ָ���ʽ : fengren <ĳ��>
 
���ָ����������������µ�����
 
HELP
	);
	return 1;
}
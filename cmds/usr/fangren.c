// expell.c
inherit F_CLEAN_UP;
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
	object ob;
	int i;
	if( !arg || !ob = present(arg, environment(me)) )
		return notify_fail("��Ҫ�ָ�˭���ο���ݣ�\n");
	if( !ob->is_character() )
		return notify_fail("���𲻶�����\n");
	if( !userp(ob) )
		return notify_fail("��ֻ�ָܻ���������ݵ����\n");
	if( (int)me->query("guild/generation")<=2
&& (int)me->query("guild/generation")!=(int)ob->query("guild/generation")
	&&	(string)me->query("guild/name")==(string)ob->query("guild/name") ) {
		message_vision("\n$N����$n˵�����ӽ���������Ҳ������"
			+ me->query("guild/name") + "���ֵ��ˣ����߰ɣ�\n\n",
			me, ob);
		tell_object(ob, "\n��ָ�����֮����Ҳ���ÿ�������ɫ�ˣ�\n\n");
	} else
		return notify_fail("����˲�����ĵ��ӡ�\n");
if((int)ob->query("guild/generation")==2)
		me->add("guild/tisheng",-1);
	ob->delete("guild");
	return 1;
}
int help(object me)
{
	write(@HELP
ָ���ʽ : fengren <ĳ��>
 
���ָ���������ָ����µ��ο����
 
HELP
	);
	return 1;
}

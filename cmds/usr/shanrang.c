inherit F_CLEAN_UP;
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
object ob;
int i;
if( !arg || !ob = present(arg, environment(me)) )
return notify_fail("��Ҫ����˭����ݣ�\n");
if( !ob->is_character() )
return notify_fail("���𲻶�����\n");
if( ob==me ) return notify_fail("���Լ������֣�������....����ûʲô�á�\n");
if( !userp(ob) )
return notify_fail("��ֻ��������Ұ��ݵĽ�ɫȨ�ޡ�\n");
if( (int)me->query("guild/generation")<2
&&	(string)me->query("guild/name")==(string)ob->query("guild/name") ) {
message_vision("\n$N����$n˵�����ӽ������������"
+ me->query("guild/name") + "�İ����ˣ��úøɣ�\n\n",
me, ob);
tell_object(ob, "\n" + me->name() + "������֮λ�������㡣\n\n");
message("system",
HIM"\n"+me->name()+"��ʽ��"+me->query("guild/name")+"����֮λ������"+ob->name()+"��\n"NOR,users()); 
} else
return notify_fail("����˲������С�ܡ�\n");
i=me->query("guild/tisheng");
ob->set("guild/generation",1);
ob->set("guild/tisheng",i);
me->delete("guild/tisheng");
me->set("guild/generation",3);
return 1;
}
int help(object me)
{
write(@HELP
ָ���ʽ : shanrang <ĳ��>
���ָ���������Ѱ���֮λ���ø����£���λ���㽫��Ϊһ����ͨ���ڡ�
HELP
);
return 1;
}

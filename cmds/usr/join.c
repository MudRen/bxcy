// apprentice.c
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object ob, old_app;
        string temp;
        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");
	if( !arg ) 
		return notify_fail("ָ���ʽ��join [cancel]|<����>\n");
	if( arg=="cancel" ) {
		old_app = me->query_temp("pending/join");
		if( !objectp(old_app) )
			return notify_fail("�����ڲ�û�м����κΰ��ɵ���˼��\n");
		write("��ı����ⲻ�����" + old_app->name() + "�İ����ˡ�\n");
		tell_object(old_app, me->name() + "�ı����ⲻ�������İ����ˡ�\n");
		me->delete_temp("pending/join");
		return 1;
	}
	if( !(ob = present(arg, environment(me)))
	||	!ob->is_character() )
		return notify_fail("�������˭�İ��ɣ�\n");
	if( !living(ob) ) 
		return notify_fail("������Ȱ�" + ob->name() + "Ū�ѡ�\n");
	if( ob==me ) 
		return notify_fail("���Լ�Ϊ�ϴ󣿺�����....����û���á�\n");
	if (me->query("guild/name")==ob->query("guild/name"))	
if ((int)me->query("guild/generation")>(int)ob->query("guild/generation")
&& me->query("guild/name")==ob->query("guild/name")){
		message_vision("$N���˸�Ҿ��$n�밲���е������ϴ�ã���\n", me, ob);
		return 1;
	}
    if (me->name() != me->name(1))
    return notify_fail(ob->name()+"������һ�ۣ����ɣ�����˭ѽ��\n");
		
	if( !mapp( ob->query("guild") ) )
		return notify_fail(ob->name() + "�Ȳ�����κΰ��ɣ�Ҳû�п�ɽ���ɣ����ܼ��롣\n");
	if( mapp(me->query("guild")))
		return notify_fail("���������Ҫ�����Լ��İ��ɣ����Ұ������ϣ�\n");
	// If the target is willing to recruit us already, we do it.
	if (me->query("age")<ob->query("age"))
		temp=me->query("ganger")=="Ů��"?"С��":"С��";
	else
		temp=me->query("ganger")=="Ů��"?"���":"���";
	if (me->query("guild/name")==ob->query("guild/name"))	
		return notify_fail(CYN+ob->name() + "����Ц��Ц��"+temp+"��Ҫ���ҿ������Ц��\n"NOR);
	if( (object)ob->query_temp("pending/shou") == me )
	{
			message_vision(
				"$N������$nΪ�ϴ�\n\n"
				"$N��$n�������������˸�Ҿ���е������ϴ󣡡�\n\n",
				me, ob);
		me->set("guild/id",ob->query("guild/id"));
		me->set("guild/name",ob->query("guild/name"));
		me->set("guild/generation",3);
		ob->delete_temp("pending/shou");
		tell_object(ob, "��ϲ��������һλ�������֣�\n");
		printf("��ϲ������%s��\n", 
			me->query("guild/name"));
		return 1;
	
	} else {
		old_app = me->query_temp("pending/join");
		if( ob==old_app )
			return notify_fail("�������" + ob->name() + "�İ��ɣ����ǶԷ���û�д�Ӧ��\n");
		else if( objectp(old_app) ) {
			write("��ı����ⲻ�����" + old_app->name() + "�İ����ˡ�\n");
			tell_object(old_app, me->name() + "�ı����ⲻ�������İ����ˡ�\n");
		}
		message_vision("$N��Ҫ����$n�İ��ɡ�\n", me, ob);
		me->set_temp("pending/join", ob );
		if( userp(ob) ) 
			tell_object(ob, YEL "�����Ը����" + me->name() + "Ϊ�Լ��İ��ڣ����� shou ָ�\n" NOR);
		return 1;
	}
}
int help(object me)
{
        write(@HELP
ָ���ʽ : join [cancel]|<����>
 
���ָ�����������ĳ�˵İ��ɣ�����Է�Ҳ��ӦҪ����Ļ����ͻ�������
����֮�񣬷���Ҫ�ȵ��Է��� shou ָ������Ϊ���ڲ�����ʽ���š�

�������ĳ���ʹ�����ָ����������밲��
 
��ο����ָ�� fangren��shou
HELP
        );
        return 1;
}

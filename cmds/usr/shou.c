// recruit.c
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object ob, old_rec;
	if( !arg ) 
		return notify_fail("ָ���ʽ��shou [cancel]|<����>\n");
if ((int)me->query("guild/generation")>2)
return notify_fail("ֻ�а������ϲ�����С�ܣ�\n");
	if( arg=="cancel" ) {
		old_rec = me->query_temp("pending/shou");
		if( !objectp(old_rec) )
			return notify_fail("�����ڲ�û����¼�κ���Ϊ���µ���˼��\n");
		write("��ı����ⲻ����" + old_rec->name() + "Ϊ�����ˡ�\n");
		tell_object(old_rec, me->name() + "�ı����ⲻ������Ϊ�����ˡ�\n");
		me->delete_temp("pending/shou");
		return 1;
	}
	if( !(ob = present(arg, environment(me))) )
		return notify_fail("������˭�����֣�\n");
	if( ob==me ) return notify_fail("���Լ������֣�������....����ûʲô�á�\n");
if ((int)me->query("guild/generation")<(int)ob->query("guild/generation")
&& me->query("guild/name")==ob->query("guild/name")){
		message_vision("$N����$n��ͷ��˵�������úøɣ���\n", me, ob);
		return 1;
	}
if (wizardp(me)&&!wizardp(ob)) return notify_fail("��ʦ������С��!\n");
	if( !me->query("guild") )
		return notify_fail("�㲢�������κΰ��ɣ�������ȼ���һ�����ɣ����Լ���һ��������С�ܡ�\n");
	// If the target is willing to apprentice us already, we do it.
	if( (object)ob->query_temp("pending/join") == me ) {
		if( !living(ob) ) {
			message_vision(
				"$N������$n���š�\n\n"
				"����������$n��Ȼû�а취������֮��\n\n",
				me, ob);
			return 1;
		}
	// follow modified by elon 09-10-95 to fix a bug in 1st time recruit
			message_vision(
				"$N������$nΪ���ӡ�\n\n"
				"$n��$N�������������˸�Ҿ���е������ϴ󣡡�\n",
				me, ob);
		ob->set("guild/id",me->query("guild/id"));
		ob->set("guild/name",me->query("guild/name"));
		ob->set("guild/generation",3);
		ob->delete_temp("pending/join");
		write("��ϲ��������һ�����ڣ�\n");
tell_object(ob, "��ϲ������"+me->query("guild/name")+"��\n");
		return 1;
	
	} else {
		old_rec = me->query_temp("pending/shou");
		if( ob==old_rec )
			return notify_fail("��������" + ob->name() + "������İ��ɣ����ǶԷ���û�д�Ӧ��\n");
		else if( objectp(old_rec) ) {
			write("��ı����ⲻ����" + old_rec->name() + "�����ˡ�\n");
			tell_object(old_rec, me->name() + "�ı����ⲻ�����������ˡ�\n");
		}
		me->set_temp("pending/shou", ob );
		message_vision("\n$N��Ҫ��$n���š�\n", me, ob);
		tell_object(ob, YEL "�����Ը�����" + me->name() + "�İ��ɣ��� join ָ�\n" NOR);
		return 1;
	}
}
int help(object me)
{
        write(@HELP
ָ���ʽ : shou [cancel]|<����>
 
���ָ����������ĳ��Ϊ�Լ�����, ����Է�Ҳ��ӦҪ������İ��ɵĻ�.
 
See Also:	join
HELP
        );
        return 1;
}

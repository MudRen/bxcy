// apprentice.c
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object ob, old_app;
        mapping family;
        string temp;
        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");
	if( !arg ) 
		return notify_fail("ָ���ʽ��apprentice | bai [cancel]|<����>\n");
	if( arg=="cancel" ) {
		old_app = me->query_temp("pending/apprentice");
		if( !objectp(old_app) )
			return notify_fail("�����ڲ�û�а��κ���Ϊʦ����˼��\n");
		write("��ı����ⲻ���" + old_app->name() + "Ϊʦ�ˡ�\n");
		tell_object(old_app, me->name() + "�ı����ⲻ�����Ϊʦ�ˡ�\n");
		me->delete_temp("pending/apprentice");
		me->delete_temp("pended");
		return 1;
	}
	if( !(ob = present(arg, environment(me)))
	||	!ob->is_character() )
		return notify_fail("�����˭Ϊʦ��\n");
	if( !living(ob) ) 
		return notify_fail("������Ȱ�" + ob->name() + "Ū�ѡ�\n");
	if( ob==me ) 
		return notify_fail("���Լ�Ϊʦ��������....����û���á�\n");
	if( me->is_apprentice_of(ob) ) {
		message_vision("$N������������$n��ͷ�밲���е�����ʦ������\n", me, ob);
		return 1;
	}
	if (me->is_fighting() || ob->is_fighting())
		return notify_fail("����������𾢣������а�ʦ֮���ʱ��\n");
    if (me->name() != me->name(1))
    return notify_fail(ob->name()+"������һ�ۣ���ʦ������˭ѽ��\n");
		
	if( !mapp( ob->query("family") ) )
		return notify_fail(ob->name() + "�Ȳ�����κ����ɣ�Ҳû�п�ɽ���ɣ����ܰ�ʦ��\n");
	if( !me->query_temp("pended") && mapp(me->query("family")) && (string)me->query("family/family_name") != (string)ob->query("family/family_name") ){
		me->set_temp("pended",1);
		return notify_fail("���������Ҫ��ʦ������Ҫ��սʤ�Լ���ʦ���������Ϊ���������ܡ�\n�����һ��Ҫ��ô����������һ������������\n");
	}
	me->delete_temp("pended");
	// If the target is willing to recruit us already, we do it.
	if (me->query("age")<ob->query("age"))
		temp=me->query("ganger")=="Ů��"?"ʦ��":"ʦ��";
	else
		temp=me->query("ganger")=="Ů��"?"ʦ��":"ʦ��";
	if (me->query("family/family_name")==ob->query("family/family_name"))
		if (me->query("family/generation")<=ob->query("family/generation"))
			return notify_fail(CYN+ob->name() + "����Ц��Ц��"+temp+"��Ҫ���ҿ������Ц��\n"NOR);
	if( (object)ob->query_temp("pending/recruit") == me )
	{
           if (mapp(me->query("family")) && ( (string)me->query("family/family_name") != (string)ob->query("family/family_name") ) ){
			message_vision(
				"$N��������ʦ�ţ���Ͷ��$n���£���\n\n"
				"$N����������$n���������ؿ����ĸ���ͷ���е�����ʦ������\n\n",
				me, ob);
			me->add("betrayer", 1);
		} else
			message_vision(
				"$N������$nΪʦ��\n\n"
				"$N����������$n���������ؿ����ĸ���ͷ���е�����ʦ������\n\n",
				me, ob);
		ob->recruit_apprentice(me);
		ob->delete_temp("pending/recruit");
		tell_object(ob, "��ϲ��������һ�����ӣ�\n");
		family = me->query("family");
		printf("��ϲ����Ϊ%s�ĵ�%s�����ӡ�\n", 
			me->query("family/family_name"),
			chinese_number( me->query("family/generation")));
		return 1;
	
	} else {
		old_app = me->query_temp("pending/apprentice");
		if( ob==old_app )
			return notify_fail("�����" + ob->name() + "Ϊʦ�����ǶԷ���û�д�Ӧ��\n");
		else if( objectp(old_app) ) {
			write("��ı����ⲻ���" + old_app->name() + "Ϊʦ�ˡ�\n");
			tell_object(old_app, me->name() + "�ı����ⲻ�����Ϊʦ�ˡ�\n");
		}
		message_vision("$N��Ҫ��$nΪʦ��\n", me, ob);
		me->set_temp("pending/apprentice", ob );
		if( userp(ob) ) {
			tell_object(ob, YEL "�����Ը����" + me->name() + "Ϊ���ӣ��� recruit ָ�\n" NOR);
		} else 
			ob->attempt_apprentice(me);
		return 1;
	}
}
int help(object me)
{
        write(@HELP
ָ���ʽ : apprentice|bai [cancel]|<����>
 
���ָ���������ĳ��Ϊʦ������Է�Ҳ��ӦҪ����Ϊͽ�Ļ����ͻ�������
��ʦ֮�񣬷���Ҫ�ȵ��Է��� recruit ָ������Ϊ���Ӳ�����ʽ��ʦ��
��ע�����Ѿ�����ʦ�����ֱ���ʦ��Ͷ��������£���ʦ���������������
���
��������ʦ��ʹ�����ָ�������ʦ���밲��
 
��ο����ָ�� expell��recruit
HELP
        );
        return 1;
}
// expell.c
#include <skill.h>
inherit F_CLEAN_UP;
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
	object ob;
	string *skname;
	mapping skills;
	int i;
	if( !userp(ob) )
		return notify_fail("��ֻ�ܿ�����������ݵ����\n");
	if( me->query("ttt")== 1
	 ) {
		message_vision("\n$N����$n˵�����ӽ���������Ҳ������"
			+ me->query("family/family_name") + "�ĵ����ˣ����߰ɣ�\n\n",
			me, ob);
		} else if( ob->is_apprentice_of(me) ) {
		message_vision("\n$N����$n˵�����ӽ���������ʦͽ������������߰ɣ�\n\n",
			me, ob);
		tell_object(ob, "\n�㱻ʦ�������ʦ���ˣ�\n\n");
	} else
		return notify_fail("����˲�����ĵ��ӡ�\n");
	ob->delete("family");
	ob->delete("title");
	ob->set("score", 0);
	skills = ob->query_skills();
	if( mapp(skills) ) {
		skname = keys(skills);
		for(i=0; i<sizeof(skname); i++)
			skills[skname[i]] *= 2;
	}
	return 1;
}
int help(object me)
{
	write(@HELP
ָ���ʽ : expell <ĳ��>
 
���ָ��������㿪�����ɲŵĵ��ӣ��������ĵ������м��ܶ��ή��ԭ��
��һ�룬�����ۺ�����һ������㣬�����һ�����������һ����������
���ء��Ĵ���������ڿ���һ������֮ǰ����������ǡ�
 
HELP
	);
	return 1;
}

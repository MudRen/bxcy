// exert.c
#include <skill.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        string force,str1,str2;
	        
        seteuid(getuid());
        if( me->is_busy() )
                return notify_fail("( ����һ��������û����ɣ�����ʩ���ڹ���)\n");
        if( !arg ) return notify_fail("��Ҫ���ڹ���ʲ�᣿\n");
    if( environment(me)->query("no_fight") )
        return notify_fail("�������Ƿ�֮�أ����ɾ������������ˣ����߰ɣ�\n");
	if (sscanf(arg,"%s %s",str1,str2)!=2)
		str1=arg;
        if(stringp(force = me->query_skill_mapped("force")) ) 
	if (file_size(SKILL_D(force)->exert_function_file(str1)+".c")>0)
                if( SKILL_D(force)->exert_function(me, arg) ) {
if(force=="kuihua-xinfa"&&(int)me->query_skill(force,1)>=450) return 1;
if( (int)me->query_skill(force,1)>=2000) return 1;
                        if( (int)me->query_skill(force,1)>100
						&& (int)me->query_skill(force,1) < (int)me->query_skill("force",1) )
                                me->improve_skill(force,random(me->query_con())+1,0);
			else
                                me->improve_skill(force,random(me->query_con())+1,1);
                        return 1;
	        }else return SKILL_D(force)->exert_function(me, arg);
	if (file_size(SKILL_D("force")->exert_function_file(str1)+".c")>0)
		return SKILL_D("force")->exert_function(me, arg);
	else
		return notify_fail("����ѧ���ڹ���û�����ֹ��ܡ�\n");
}
int help (object me)
{
        write(@HELP
ָ���ʽ��exert <��������> [<ʩ�ö���>]
����������һЩ���칦�ܣ������Ҫָ��<��������>��<ʩ�ö���>����п��ޡ�
����ʹ��ĳһ���ڹ������칦��֮ǰ����������� enable ָ����ָ����Ҫʹ��
���ڹ���
��ο� help force �ɵ�֪һЩ�󲿷��ڹ����еĹ��ܣ����������õ��ڹ�����
��û�иù��ܣ���һ�Ի�ο�����˵����֪��
ע�������ı��Լ����ڹ�����ԭ�����������������ֱ��ת����ȥ������
    �ӣ���ʼ��
HELP
        );
        return 1;
}

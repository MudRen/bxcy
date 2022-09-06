// perform.c
inherit F_CLEAN_UP;

int main(object me, string arg)
{
    object weapon;
    mapping smap;
    string martial, skill, str;
    
    seteuid(getuid());
    
    smap = me->query_skill_map();
    if( me->is_busy() )
        return notify_fail("( ����һ��������û����ɣ�����ʩ���⹦��)\n");
    if( !arg ) return notify_fail("��Ҫ���⹦��ʲ�᣿\n");
    if( sscanf(arg, "%s.%s", martial, str)!=2 ) {
        str=arg;
        if( weapon = me->query_temp("weapon") )
            martial = weapon->query("skill_type");
        else martial = "unarmed";
    }
    if( stringp(skill = me->query_skill_mapped(martial)) ) {
	if (file_size(SKILL_D(skill)->perform_action_file(str)+".c")>0){
        notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");
        if( SKILL_D(skill)->perform_action(me, str) ) {
            if( random(120) < (int)me->query_skill(skill) )
                me->improve_skill(skill, 1, 1);
            return 1;
        } else if( SKILL_D(martial)->perform_action(me, str) ) {
            if( random(120) < (int)me->query_skill(martial, 1) )
                me->improve_skill(martial, 1, 1);
            return 1;
        }
        return 0;
	}
    }
    if( sscanf(arg, "%s.%s", martial, str)!=2 ) {
        str=arg;
        if( weapon = me->query_temp("secondary_weapon") )
            martial = weapon->query("skill_type");
        else martial = "unarmed";
    }
    if( stringp(skill = me->query_skill_mapped(martial)) ) {
        notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");
        if( SKILL_D(skill)->perform_action(me, str) ) {
            if( random(120) < (int)me->query_skill(skill) )
                me->improve_skill(skill, 1, 1);
            return 1;
        } else if( SKILL_D(martial)->perform_action(me, str) ) {
            if( random(120) < (int)me->query_skill(martial, 1) )
                me->improve_skill(martial, 1, 1);
            return 1;
        }
        return 0;
    }
    return notify_fail("�������� enable ָ��ѡ����Ҫʹ�õ��⹦��\n");
}
int help (object me)
{
        write(@HELP
ָ���ʽ��perfrom [<�书����>.]<��ʽ����> [<ʩ�ö���>]
�������ѧ���⹦(ȭ�š�����������....)��һЩ����Ĺ�����ʽ����ʽ������
�����ָ����ʹ�ã���������� enable ָ��ָ����ʹ�õ��书����ָ���书��
��ʱ�����ֵ��⹦��ָ���ȭ�Ź���ʹ������ʱ���Ǳ��е��书��
��������⹦�������಻ͬ��������ʽ������ͬ�ģ����߲����ȭ�Ÿ���������
���书(���Ṧ)�������� <�书>.<��ʽ>  �ķ�ʽָ�����磺
perform taiji-jian.chan
or
perform chan
���仰˵��ֻҪ�� enable �е��书��������ʽ�ģ������������ָ��ʹ�á�
HELP
        );
        return 1;
}

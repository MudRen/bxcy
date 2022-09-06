// ----/cmds/skill/practice.c ----

// practice.c
#pragma save_binary
int help(object me);
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        object where = environment(me);
        string skillname;
        int skill, skill_basic;
        seteuid(getuid());
        if (where->query("pigging"))
                return notify_fail("�㻹��ר�Ĺ���ɣ�\n");
        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");
    if( environment(me)->query("no_fight") )
        return notify_fail("�������Ƿ�֮�أ����ɾ������������ˣ����߰ɣ�\n");
// if ((me->query_temp("pker_starttime")+3600*me->query_temp("pker_time")) > me->query("mud_age"))
//                return notify_fail("�ٸ�����ͨ���㣬�����񲻶��޷�ר��������\n");
        if( me->is_fighting() )
                return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");
        if( !arg ) return help(me);
        if( !stringp(skillname = me->query_skill_mapped(arg)) || arg=="parry" )
                return notify_fail("��ֻ����ϰ�� enable ָ�������⼼�ܡ�\n");
        skill_basic = me->query_skill(arg, 1);
        skill = me->query_skill(skillname, 1);
        if( skill < 1 )
                return notify_fail("�����û��ѧ������ܰɣ������ȥ��̱��ˡ�\n");
        if( skill_basic < 1 )
                return notify_fail("����ⷽ��ļ��ܻ���һ�ϲ�ͨ����ô��ȴӻ���ѧ��\n");
        if( skill_basic <= skill )
                return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");
        notify_fail("��������ϰ" + to_chinese(skillname) + "�����ǲ�û���κν�����\n");
        if( SKILL_D(skillname)->practice_skill(me) ) {
                if (skill >= SKILL_D(skillname)->practice_level())
                        me->improve_skill(skillname, skill_basic/5 +1, skill_basic > skill? 0: 1);
                else
                        me->improve_skill(skillname, skill_basic/5 +1,  1);
                write( HIY "���" + to_chinese(skillname) + "�����ˣ�\n" NOR);
                return 1;
        }
        else return 0;
}
int help(object me)
{
        write(@TEXT
ָ���ʽ��practice <��������>
���ָ��������ϰĳ������ļ��ܣ�������ܱ����Ǿ��� enable ��רҵ���ܡ�
�������ⷽ��Ļ������ܹ��ߣ����Ծ�����ϰֱ����������������������ֻ��
��������ܵĵȼ��йأ����仰˵���ڼ���ϰ��ʹ�����ѧ���������ʤ������
��Ψһ;������Ȼ������֮ǰ������ʵ�������л���㹻�ľ�����������Ļ�
�����ܡ�
TEXT
        );
        return 1;
}


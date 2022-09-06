
// Code of ShenZhou
// mem.c
// naihe 05-10-21 11:56 ��ǿ���Ӳ��� -all �鿴���������ϸ�ڴ�ռ�������
// naihe 05-10-24 11:20 ����Ŀǰ��Ҫ��ǿһ�¡�

#include <ansi.h>
inherit F_CLEAN_UP;

string memory_expression(int m);
private varargs void check_mem( string file );
private void check_memory_info();

int main(object me, string arg)
{
    object obj;
    string file;

    if( me != this_player(1) || !wizardp(me) )
        return 0;

    if ( !arg )
    {
        check_memory_info();
        return 1;
    }

    if( arg=="-m" ) {
        write(malloc_status()+"\n");
        return 1;
    }
    if( arg=="-all" )
    {
        if( wizhood(me) != "(admin)"
         && wizhood(me) != "(arch-a)"
         && wizhood(me) != "(arch-b)"
        )
            return notify_fail("���ָ�����ֻ���ɸ߼���ʦʹ�á�\n");

        check_mem();
        return 1;
    }
    if( sscanf( arg, "-all %s", file) == 1 )
    {
        check_mem( file );
        return 1;
    }
    seteuid(geteuid(me));
    obj = find_object(arg);
    if ( !obj || !me->visible(obj) )
        obj = present(arg, me);
    if ( !obj || !me->visible(obj) )
        obj = present(arg, environment(me));
    if ( !obj || !me->visible(obj) )
        obj = find_object( resolve_path(me->query("cwd"), arg) );
    if ( !obj || !me->visible(obj) )
        return notify_fail("�޷�ͨ�� find_object() �ҵ������������Я�������������������Ҳû���ҵ����������\n");
    printf( "%O ��ʹ�� %s bytes �����塣\n", obj, memory_expression(memory_info(obj)));
    return 1;
}

string memory_expression(int m)
{
    float mem;

    mem = m;
    if( mem<1024 ) return m + "";
    if( mem<1024*1024 )
        return sprintf("%.2f K", (float)mem / 1024);
    return sprintf("%.3f M", (float)mem / (1024*1024));
}

private void check_memory_info()
{
    write( sprintf( "%sĿǰ��ʹ�� %s bytes �����塣\n", MUD_NAME, memory_expression(memory_info()) ) );
}

private varargs void check_mem( string file )
{
    object me = this_player();
    object *objs, ob;
    mixed groups;
    int i, j, size, tmp_mem, all_mem, shout_msg;
    string msg = "", tmp_msg;

    if( file )
    {
        if( file[<2..<1] == ".c" )
            file = file[0..<3];
        objs = children( file +".c" );
        if( !sizeof( objs ) )
        {
            write( "δ�����κα��ļ������ļ���"+ file +"\n");
            return;
        }
        else
            groups = unique_array( objs, (: base_name( $1 ) : ) );
    }
    else
    {
        shout_msg = 1;
        objs = objects();
        groups = unique_array( objs, (: base_name( $1 ) :) );
    }
    if( shout_msg )
    {
        shout( "\n"HIW + MUD_NAME+ " ���ڼ�����ݣ����ܻ����һЩ���ͣ������ĵȴ�����\n\n"NOR );
        write( "\n"HIW + MUD_NAME+ " ���ڼ�����ݣ����ܻ����һЩ���ͣ������ĵȴ�����\n\n"NOR );
    }
    write( sprintf( "�������� %d ���ļ����ɵ� %d ������������\n", sizeof( groups ), sizeof( objs ),  ) );
    write( "��ϸ���£�\n\n" );
    for( i=sizeof(groups)-1; i>=0; i-- )
    {
        tmp_mem = 0;
        size = sizeof( groups[i] );
        for( j=size-1; j>=0; j-- )
        {
            tmp_mem += memory_info( groups[i][j] );
        }
        all_mem += tmp_mem;
        tmp_msg = sprintf( "%12s", memory_expression( tmp_mem ) );
        tmp_msg = replace_string( tmp_msg, "K", HIC"K"NOR );
        tmp_msg = replace_string( tmp_msg, "M", HIR"M"NOR );
        msg += sprintf( "%-50s  %5d ��  %s    %14s / %14s\n",
            base_name( groups[i][0] ), size, tmp_msg,
            size != 1 ? memory_expression( memory_info(groups[i][0]) ) : "--",
            size != 1 ? memory_expression( tmp_mem / size ) : "--",
        );
    }
    write( sprintf( "%|50s  %8s  %s    %14s / %14s\n",
            "��    ��    ��",
            "���Ƽ�����",
            "�ڴ�ռ���ܶ�",
            "��һռ��(�ο�)",
            "ƽ��ÿ��ռ��",
    ));
    me->start_more( msg );
    write( "���Ϻϼ�ʹ���ڴ棺" + memory_expression( all_mem ) + "��   "HIR"����ʹ��"NOR"��\n" );
    check_memory_info();
    if( shout_msg )
    {
        shout( "\n"HIW + MUD_NAME+ " ���������ϡ�\n\n"NOR );
        write( "\n"HIW + MUD_NAME+ " ���������ϡ�\n\n"NOR );
    }
}

int help(object me)
{
    write(@HELP
ָ���ʽ : mem [-all] [�����(id)���ļ���]

���ָ������鿴����վ��(��ĳ���)ռ�õ��ڴ���Ϣ��

�Ӳ��� -all ʱ��
    �������������ʱ��������ʾ����վ��������������ڴ�ռ����Ϣ��
    �����������ʱ����ʾ����������и����������ڴ�ռ����Ϣ��

���Ӳ��� -all ʱ��
    �����������������ʾ MUD Ŀǰռ�õ��ڴ�������
    ���������������ʾ�����ռ�õ��ڴ�����
HELP
    );
    return 1;
}


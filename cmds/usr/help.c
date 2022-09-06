#include "/doc/help.h"
inherit F_CLEAN_UP;
string *default_search = DEFAULT_SEARCH_PATHS;
string *wizard_search = DEFAULT_WIZARD_PATHS;
int main(object me, string arg)
{
        int i;
        string file, *search;
        // If no topic specified, give the topics.
        if( !arg ) {
                cat(HELP_DIR + "help/topics");
                write("\n");
                return 1;
        }
        // Else, try if a command name is specified.
        seteuid(getuid());
        if( stringp(file = me->find_command(arg)) ) {
                notify_fail("�����ָ����ڣ����ǲ�û����ϸ��˵���ļ���\n");
                return file->help(me);
        }
        // Search the individual search path first.
        if( pointerp(search = me->query("help_search_path")) ) {
                i = sizeof(search);
                while(i--) if( file_size(search[i] + arg)>0 ) {
			if( file_size(search[i] + arg)>8190 )
	                        me->start_more( read_file(search[i] + arg) );
			else	write( read_file(search[i] + arg) );
                        return 1;
                }
        }
        // Finally, search the default search paths.
        if( pointerp(default_search) ) {
                i = sizeof(default_search);
                while(i--) if( file_size(default_search[i] + arg)>0 ) {
                        if (default_search[i]=="/doc/skill/" &&!wizardp(me))
                                if( !me->query_skill(arg, 1) )
                                        return notify_fail("�㲻�����ּ��ܡ�\n");
	                        me->start_more( read_file(default_search[i] + arg) );

                        return 1;
                }
        }
        // Support efun/lfun help with same name as other topics such as
        // ed() and ed command.
        if (wizardp(me)){
                sscanf(arg, "%s()", arg);
                if( pointerp(wizard_search) ) {
                        i = sizeof(wizard_search);
                        while(i--) if( file_size(wizard_search[i] + arg)>0 ) {
//                                if( file_size(wizard_search[i] + arg)>8190 )
                                me->start_more( read_file(wizard_search[i] + arg) );
//                                else write( read_file(wizard_search[i] + arg) );
                                return 1;
                        }
                }
        }
        return notify_fail("û��������������˵���ļ���\n");
}
int help(object me)
{
        write(@HELP
ָ���ʽ��help <����>              ���磺> help cmds
<wizard>  help <��������>()        ���磺> help call_out()
���ָ���ṩ�����ĳһ�������ϸ˵���ļ������ǲ�ָ�����⣬���ṩ���й�
������ļ���
HELP
        );
        return 1;
}

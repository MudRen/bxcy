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
                notify_fail("有这个指令存在，但是并没有详细的说明文件。\n");
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
                                        return notify_fail("你不会这种技能。\n");
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
        return notify_fail("没有针对这项主题的说明文件。\n");
}
int help(object me)
{
        write(@HELP
指令格式：help <主题>              例如：> help cmds
<wizard>  help <函数名称>()        例如：> help call_out()
这个指令提供你针对某一主题的详细说明文件，若是不指定主题，则提供你有关
主题的文件。
HELP
        );
        return 1;
}

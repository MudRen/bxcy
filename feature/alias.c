// alias.c
// #pragma save_binary
#include <command.h>
#define MAX_REPEAT 50
#define MAX_ALIASES 40
#define HISTORY_BUFFER_SIZE 10
mapping alias;
nosave string *history, last_input;
nosave int last_cmd, repeat_cnt = 0;
nosave int last_cmd_time,cmd_time=0,kill_time=0;
string process_input(string str)
{
    string *args, command, argstr,verb,arg,file,cmd;
    int i, j;
    object ob,dest;
    object me = this_player();
if (strsrch(str,"//")!=-1)   return HIR"非法输入？\n"NOR;
    if( me->query_temp("disable_inputs") )   return HIR"什麽？\n"NOR;
    cmd_time++;
    if (time()-last_cmd_time<1){
            if (kill_time>4){
                tell_object( this_object(),RED "\n\n侮天鬼王突然在一阵烟雾中出现。\n\n\n\n侮天鬼王喝道：你老在吵我睡觉，你去死吧!!!\n\n" NOR);
                    seteuid(getuid());
                    dest = this_player();
if (!dest->is_fighting()&&!dest->is_busy()&&!dest->query_condition("killer")){
dest->set("kickout_time",time());
dest->kick();
} else {
                    if (!ob=present("demogorgon"))
                        ob = new("/clone/npc/demogorgon");
                    if (userp(ob))
                        ob = new("/clone/npc/demogorgon");
                    ob->move(environment(dest));
                    ob->kill_ob(dest);
                    ob->set_leader(dest);
                    dest->kill_ob(ob);
                    cmd_time=0;
                    kill_time=0;
}
            }
                        if (cmd_time>14){
                tell_object( this_object(),RED "\n\n侮天鬼王突然在一阵烟雾中出现。\n\n\n\n侮天鬼王喝道：你再这样吵我睡觉，我就不客气了!!!\n\n" NOR );
                cmd_time=0;
                kill_time++;
            }
    }else   {
        cmd_time=0;
        if (time()-last_cmd_time>1)
                kill_time>0?kill_time--:0;
          else
                kill_time=0;
    }
    last_cmd_time=time();

    if( str==last_input ) {
        repeat_cnt++;
        if( repeat_cnt > MAX_REPEAT && !wizardp(this_object())) {
            tell_object( this_object(),
                RED "\n\n侮天鬼王突然在一阵烟雾中出现。\n\n"
                "\n\n侮天鬼王喝道：你是机器人!!! 连我也看不惯了，滚吧!!!\n\n" NOR);
        if(domain_file(base_name(environment(this_object())))=="death"){
        	this_object()->kick();
        	return "";
        }
            this_object()->unconcious();
          return "";
        }
    } else {
        repeat_cnt = 0;
        last_input = str;
    }
    if( str[0]=='!' ) {
        if( pointerp(history) && sizeof(history) ) {
            if( sscanf(str, "!%d", i) )
                str = (string)history[(HISTORY_BUFFER_SIZE + last_cmd - i) % HISTORY_BUFFER_SIZE];
            else
                str = history[last_cmd];
        } else
            return "";
    } else {
        if( !pointerp(history) ) history = allocate(HISTORY_BUFFER_SIZE);
        last_cmd = (last_cmd + 1) % HISTORY_BUFFER_SIZE;
        history[last_cmd] = str;
    }
    if( mapp(alias) ) {
        if( !undefinedp(alias[str]) )
            return replace_string( alias[str], "$*", "" );
        if( sscanf(str, "%s %s", cmd, argstr)==2 && !undefinedp(alias[cmd]) ) {
            cmd = replace_string( alias[cmd], "$*", argstr );
            args = explode(argstr, " ");
            if( (j = sizeof(args)) )
                for(i=0; i<j; i++)
                    cmd = replace_string( cmd, "$" + (i+1), args[i] );
            return cmd;
        }
    }
    command=(string)ALIAS_D->process_global_alias(str);

    if (this_object()->query_temp("big5") )
    command=LANGUAGE_D->Big52GB(command);

    if (!living(this_object())){
        if (sscanf(command,"%s %s",verb,arg)!=2) verb=command;
        file="/cmds/usr/"+verb+".c";
      if (file_size(file)>0){
         file->main(this_object(),arg);
         return "";
      }
        else if( EMOTE_D->do_emote( this_object(), verb, arg ) )
            return "";
        else if( CHANNEL_D->do_channel( this_object(), verb, arg ) )
            return "";
    }
    return command;
}
int set_alias(string verb, string replace)
{
    if( !replace ) {
        if( mapp(alias) ) map_delete(alias, verb);
        return 1;
    } else {
        if( !mapp(alias) ) alias = ([ verb:replace ]);
        else if( sizeof(alias) > MAX_ALIASES )
            return notify_fail("您设定的 alias 太多了，请先删掉一些不常用的。\n");
        else alias[verb] = replace;
        return 1;
    }
}
mapping query_all_alias()
{
    return alias;
}

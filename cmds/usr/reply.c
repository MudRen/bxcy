// reply.c
#include <net/dns.h>
inherit F_CLEAN_UP;
int help(object me);


#define DEBUG "wyz"
#ifdef DEBUG
void debug(string x)
{
    object monitor;
    if (!stringp(x) || !stringp(DEBUG))     return;
    monitor=find_player(DEBUG);
    if(monitor && monitor->query("env/debug"))     tell_object(monitor,x+"\n");
}
#else
#define debug(x)
#endif

object find_player(string target)
{
        int i;
        object *str;
        str=users();
        for (i=0;i<sizeof(str);i++)
                if (str[i]->query("id")==target)
                        return str[i];
        return 0;
}
int main(object me, string arg)
{
        string target, mud;
        object obj;
        if( !arg || arg=="" )
                return notify_fail("你要回答什麽？\n");
        if( !stringp(target = me->query_temp("reply")) )
                return notify_fail("刚才没有人和你说过话。\n");
    if( userp(me) && !wizardp(me)) {
        if (me->query("chblk_tell")+300>time())
            return notify_fail("你现在喉咙嘶哑,半句话也说不出了。\n");
       me->add_temp("tell_msg_cnt", 1);
       if (me->query_temp("tell_msg_cnt")>5)
            if (time()-me->query_temp("tell_time")<2)
                me->set("chblk_tell",time());
            else
                me->delete_temp("tell_msg_cnt");
    }

        if( sscanf(target, "%s@%s", target, mud)==2 ) {
                GTELL->send_gtell(lower_case(mud), lower_case(target), me, arg);
                write("网路讯息已送出，可能要稍候才能得到回应。\n");
                return 1;
        }
        obj = find_player(target);
        if( !obj ||!interactive(obj) || !environment(obj) )
                return notify_fail("刚才和你说话的人现在无法听见你，或者已经离开游戏了。\n");
    debug(sprintf( YEL "%s(%s)回答%s(%s)：%s" NOR,me->name(1),me->query("id"),obj->name(1),obj->query("id"), arg));
    write(BOLD "你腹语耳密" + obj->name(1) + "：" + arg + "\n" NOR);
        if (me->id(obj->query("env/no_tell")) )
                return notify_fail("很显然，"+obj->name(1)+"在生你的闷气，不想和你说话....。\n");
    tell_object(obj, sprintf(BOLD"%s腹语耳密你：%s\n"NOR,me->name(1), arg ));
        if (query_idle(obj)>120) write(YEL+"但是"+obj->name(1)+"已经发呆"+query_idle(obj)/60+"分钟，看来不会马上回答你哟！\n"+NOR);
        obj->set_temp("reply", me->query("id"));
        return 1;
}
int help(object me)
{
        write(@HELP
指令格式：reply <讯息>
你可以用这个指令和刚才用 tell 和你说话的使用者说话。
see also : tell
HELP
        );
        return 1;
}


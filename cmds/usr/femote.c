#include "/doc/help.h"
#include <ansi.h>
inherit F_CLEAN_UP;
int help(object me);
int main(object me, string arg)
{
        mapping emote;
        string *e, *loop;
        string result="", msg;
        int i,count=0;

        loop = ({ "others_target", "others_self", "others" });
        if( !arg )
                return help(me);

        e = sort_array( EMOTE_D->query_all_emote(), 1);

        for(i=0; i<sizeof(e); i++) {
                emote = EMOTE_D->query_emote(e[i]);
                for( int j=0; j<sizeof(loop); j++ ) {
                        msg = emote[ loop[j] ];
                        if( msg && strsrch(msg, arg) >=0 ) {
                                result += sprintf("emote 名: %s\n动作: %s\n", e[i], msg);
                                count ++;
                        }
                }
        }
        if(  result == "" )
                return notify_fail(MUD_NAME" 中无符合查询条件的 emote.\n");
        else
                result = "\n查询结果"
                                "\n------------------------------------------------------------\n"
                                + result;
        result = replace_string(result, "$n", "(对方)");
        result = replace_string(result, "$N", me->name(1));
        result = replace_string(result, "$P", "你");
        result = replace_string(result, "$p", "(他/她)");
        result = replace_string(result, "$S", RANK_D->query_self(me));
        result = replace_string(result, "$s", RANK_D->query_self_rude(me));
        result = replace_string(result, "$R", "(对方的尊称)");
        result = replace_string(result, "$r", "(对方的辱称)");
        result = replace_string(result, "$C", "(自己的呢称)");
        result = replace_string(result, "$c", "(对方的呢称)");

        result += "------------------------------------------------------------\n";
        result += sprintf("在%s中，包含“%s”的 emote 共有 %d 个。\n",
                                        MUD_NAME, arg, count );
        me->start_more(result);
        return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : zhao 关键字
功能：列出目前所有含指定关键字的 emote.

HELP
    );
    return 1;
}

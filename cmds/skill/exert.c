// exert.c
#include <skill.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        string force,str1,str2;
	        
        seteuid(getuid());
        if( me->is_busy() )
                return notify_fail("( 你上一个动作还没有完成，不能施用内功。)\n");
        if( !arg ) return notify_fail("你要用内功做什麽？\n");
    if( environment(me)->query("no_fight") )
        return notify_fail("这里是是非之地，不可久留，别练功了，快走吧！\n");
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
		return notify_fail("你所学的内功中没有这种功能。\n");
}
int help (object me)
{
        write(@HELP
指令格式：exert <功能名称> [<施用对象>]
用内力进行一些特异功能，你必需要指定<功能名称>，<施用对象>则可有可无。
在你使用某一种内功的特异功能之前，你必须先用 enable 指令来指定你要使用
的内功。
请参考 help force 可得知一些大部分内功都有的功能，至于你所用的内功到底
有没有该功能，试一试或参考其他说明便知。
注：如果你改变自己的内功，你原本蓄积的内力并不能直接转换过去，必须
    从０开始。
HELP
        );
        return 1;
}

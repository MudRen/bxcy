// halt.c
#include "/doc/help.h"
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object ob;
	if (!arg){
	if( !me->is_fighting() )
		return notify_fail("你现在并没有在战斗。\n");
	me->remove_all_killer();
	message_vision("$N用巫师的神力停止了这场打斗。\n", me);
	}else{
		if (ob=present(arg, environment(me))){
			if (!ob->is_character() || ob->is_corpse())
				return notify_fail(ob->name()+"也会战斗？别笑掉我的大牙！\n");
			if( !ob->is_fighting() )
				return notify_fail(ob->name()+"现在并没有在战斗。\n");
			ob->remove_all_killer();
			message_vision("$N用巫师的神力停止了$n的这场打斗。\n", me,ob);
		}
	}
	write("Ok.\n");
	return 1;
}
int help(object me)
{
   write(@HELP
指令格式: halt <某人>
可以停止所有与你(或某人)有关的战斗。
HELP
   );
   return 1;
}

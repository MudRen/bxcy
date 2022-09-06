// expell.c
inherit F_CLEAN_UP;
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
	object ob;
	int i;
	if( !arg || !ob = present(arg, environment(me)) )
		return notify_fail("你要恢复谁的游客身份？\n");
	if( !ob->is_character() )
		return notify_fail("你逐不动他。\n");
	if( !userp(ob) )
		return notify_fail("你只能恢复玩家所扮演的人物。\n");
	if( (int)me->query("guild/generation")<=2
&& (int)me->query("guild/generation")!=(int)ob->query("guild/generation")
	&&	(string)me->query("guild/name")==(string)ob->query("guild/name") ) {
		message_vision("\n$N对着$n说道：从今天起，你再也不是我"
			+ me->query("guild/name") + "的兄弟了，你走吧！\n\n",
			me, ob);
		tell_object(ob, "\n你恢复自由之身，再也不用看帮主脸色了！\n\n");
	} else
		return notify_fail("这个人不是你的弟子。\n");
if((int)ob->query("guild/generation")==2)
		me->add("guild/tisheng",-1);
	ob->delete("guild");
	return 1;
}
int help(object me)
{
	write(@HELP
指令格式 : fengren <某人>
 
这个指令可以让你恢复手下的游客身份
 
HELP
	);
	return 1;
}

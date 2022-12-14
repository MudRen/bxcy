// whisper.c
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string dest, msg;
	object ob;
	if( !arg || sscanf(arg, "%s %s", dest, msg)!=2 )
		return notify_fail("你要对谁耳语些什么？\n");
	ob = present(dest, environment(me));
	if( !ob || !ob->is_character() )
		return notify_fail("你要对谁耳语？\n");
	if (ob==me)	return notify_fail("你用力把嘴巴拉长，艰难地伸到自己的耳边，大喊一声：喂！\n");
	if (userp(ob) && !interactive(ob))	return notify_fail("没看见"+ob->name()+"断线了吗？你说什么也是白说！\n");
	write( BOLD "你在" + ob->name() + "的耳边悄声说道：" + msg + "\n" NOR);
	tell_room( environment(me), me->name() + "在" + ob->name()
		+ "耳边小声地说了些话。\n", ({ me, ob }) );
	if( !userp(ob) ) ob->relay_whisper(me, msg);
	else
		tell_object( ob, BOLD + me->name() + "在你的耳边悄声说道：" + msg + "\n" NOR);
	return 1;
}
int help(object me)
{
	write( @TEXT
指令格式：whisper <某人> <讯息>
这个指令可以用来和同一房间中的人耳语，包括 NPC 在内。
TEXT
	);
	return 1;
}

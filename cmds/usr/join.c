// apprentice.c
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object ob, old_app;
        string temp;
        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");
	if( !arg ) 
		return notify_fail("指令格式：join [cancel]|<对象>\n");
	if( arg=="cancel" ) {
		old_app = me->query_temp("pending/join");
		if( !objectp(old_app) )
			return notify_fail("你现在并没有加入任何帮派的意思。\n");
		write("你改变主意不想加入" + old_app->name() + "的帮派了。\n");
		tell_object(old_app, me->name() + "改变主意不想加入你的帮派了。\n");
		me->delete_temp("pending/join");
		return 1;
	}
	if( !(ob = present(arg, environment(me)))
	||	!ob->is_character() )
		return notify_fail("你想加入谁的帮派？\n");
	if( !living(ob) ) 
		return notify_fail("你必须先把" + ob->name() + "弄醒。\n");
	if( ob==me ) 
		return notify_fail("封自己为老大？好主意....不过没有用。\n");
	if (me->query("guild/name")==ob->query("guild/name"))	
if ((int)me->query("guild/generation")>(int)ob->query("guild/generation")
&& me->query("guild/name")==ob->query("guild/name")){
		message_vision("$N做了个揖向$n请安，叫道：「老大好！」\n", me, ob);
		return 1;
	}
    if (me->name() != me->name(1))
    return notify_fail(ob->name()+"瞪了你一眼，入派？你是谁呀？\n");
		
	if( !mapp( ob->query("guild") ) )
		return notify_fail(ob->name() + "既不属於任何帮派，也没有开山立派，不能加入。\n");
	if( mapp(me->query("guild")))
		return notify_fail("你如果决定要脱离自己的帮派，请找帮主或长老！\n");
	// If the target is willing to recruit us already, we do it.
	if (me->query("age")<ob->query("age"))
		temp=me->query("ganger")=="女性"?"小妹":"小弟";
	else
		temp=me->query("ganger")=="女性"?"大姐":"大哥";
	if (me->query("guild/name")==ob->query("guild/name"))	
		return notify_fail(CYN+ob->name() + "对你笑了笑，"+temp+"不要和我开这个玩笑。\n"NOR);
	if( (object)ob->query_temp("pending/shou") == me )
	{
			message_vision(
				"$N决定拜$n为老大。\n\n"
				"$N向$n恭恭敬敬地做了个揖，叫道：「老大！」\n\n",
				me, ob);
		me->set("guild/id",ob->query("guild/id"));
		me->set("guild/name",ob->query("guild/name"));
		me->set("guild/generation",3);
		ob->delete_temp("pending/shou");
		tell_object(ob, "恭喜你新收了一位得力助手！\n");
		printf("恭喜您加入%s。\n", 
			me->query("guild/name"));
		return 1;
	
	} else {
		old_app = me->query_temp("pending/join");
		if( ob==old_app )
			return notify_fail("你想加入" + ob->name() + "的帮派，但是对方还没有答应。\n");
		else if( objectp(old_app) ) {
			write("你改变主意不想加入" + old_app->name() + "的帮派了。\n");
			tell_object(old_app, me->name() + "改变主意不想加入你的帮派了。\n");
		}
		message_vision("$N想要加入$n的帮派。\n", me, ob);
		me->set_temp("pending/join", ob );
		if( userp(ob) ) 
			tell_object(ob, YEL "如果你愿意收" + me->name() + "为自己的帮众，请用 shou 指令。\n" NOR);
		return 1;
	}
}
int help(object me)
{
        write(@HELP
指令格式 : join [cancel]|<对象>
 
这个指令能让你加入某人的帮派，如果对方也答应要收你的话，就会立即行
入门之礼，否则要等到对方用 shou 指令收你为帮众才能正式入门。

如果对你的长老使用这个指令，会变成向长老请安。
 
请参考相关指令 fangren、shou
HELP
        );
        return 1;
}

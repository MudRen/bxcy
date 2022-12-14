// recruit.c
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object ob, old_rec;
	if( !arg ) 
		return notify_fail("指令格式：shou [cancel]|<对象>\n");
if ((int)me->query("guild/generation")>2)
return notify_fail("只有帮主或长老才能收小弟！\n");
	if( arg=="cancel" ) {
		old_rec = me->query_temp("pending/shou");
		if( !objectp(old_rec) )
			return notify_fail("你现在并没有收录任何人为手下的意思。\n");
		write("你改变主意不想收" + old_rec->name() + "为手下了。\n");
		tell_object(old_rec, me->name() + "改变主意不想收你为手下了。\n");
		me->delete_temp("pending/shou");
		return 1;
	}
	if( !(ob = present(arg, environment(me))) )
		return notify_fail("你想收谁作助手？\n");
	if( ob==me ) return notify_fail("做自己的助手？好主意....不过没什么用。\n");
if ((int)me->query("guild/generation")<(int)ob->query("guild/generation")
&& me->query("guild/name")==ob->query("guild/name")){
		message_vision("$N拍拍$n的头，说道：「好好干！」\n", me, ob);
		return 1;
	}
if (wizardp(me)&&!wizardp(ob)) return notify_fail("巫师不能收小弟!\n");
	if( !me->query("guild") )
		return notify_fail("你并不属于任何帮派，你必须先加入一个帮派，或自己创一个才能收小弟。\n");
	// If the target is willing to apprentice us already, we do it.
	if( (object)ob->query_temp("pending/join") == me ) {
		if( !living(ob) ) {
			message_vision(
				"$N决定收$n入门。\n\n"
				"不过看样子$n显然没有办法行入门之礼。\n\n",
				me, ob);
			return 1;
		}
	// follow modified by elon 09-10-95 to fix a bug in 1st time recruit
			message_vision(
				"$N决定收$n为弟子。\n\n"
				"$n向$N恭恭敬敬地做了个揖，叫道：「老大！」\n",
				me, ob);
		ob->set("guild/id",me->query("guild/id"));
		ob->set("guild/name",me->query("guild/name"));
		ob->set("guild/generation",3);
		ob->delete_temp("pending/join");
		write("恭喜你新收了一名帮众！\n");
tell_object(ob, "恭喜您加入"+me->query("guild/name")+"！\n");
		return 1;
	
	} else {
		old_rec = me->query_temp("pending/shou");
		if( ob==old_rec )
			return notify_fail("你想邀请" + ob->name() + "加入你的帮派，但是对方还没有答应。\n");
		else if( objectp(old_rec) ) {
			write("你改变主意不想收" + old_rec->name() + "入门了。\n");
			tell_object(old_rec, me->name() + "改变主意不想收你入门了。\n");
		}
		me->set_temp("pending/shou", ob );
		message_vision("\n$N想要收$n入门。\n", me, ob);
		tell_object(ob, YEL "如果你愿意加入" + me->name() + "的帮派，用 join 指令。\n" NOR);
		return 1;
	}
}
int help(object me)
{
        write(@HELP
指令格式 : shou [cancel]|<对象>
 
这个指令能让你收某人为自己帮众, 如果对方也答应要加入你的帮派的话.
 
See Also:	join
HELP
        );
        return 1;
}

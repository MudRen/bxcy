inherit F_CLEAN_UP;
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
object ob;
int i;
if( !arg || !ob = present(arg, environment(me)) )
return notify_fail("你要提升谁的身份？\n");
if( !ob->is_character() )
return notify_fail("你逐不动他。\n");
if( ob==me ) return notify_fail("做自己的助手？好主意....不过没什么用。\n");
if( !userp(ob) )
return notify_fail("你只能提升玩家扮演的角色权限。\n");
if( (int)me->query("guild/generation")<2
&&	(string)me->query("guild/name")==(string)ob->query("guild/name") ) {
message_vision("\n$N对着$n说道：从今天起，你就是我"
+ me->query("guild/name") + "的帮主了，好好干！\n\n",
me, ob);
tell_object(ob, "\n" + me->name() + "将帮主之位禅让与你。\n\n");
message("system",
HIM"\n"+me->name()+"正式将"+me->query("guild/name")+"帮主之位禅让于"+ob->name()+"。\n"NOR,users()); 
} else
return notify_fail("这个人不是你的小弟。\n");
i=me->query("guild/tisheng");
ob->set("guild/generation",1);
ob->set("guild/tisheng",i);
me->delete("guild/tisheng");
me->set("guild/generation",3);
return 1;
}
int help(object me)
{
write(@HELP
指令格式 : shanrang <某人>
这个指令可以让你把帮主之位禅让给手下，让位后，你将成为一名普通帮众。
HELP
);
return 1;
}

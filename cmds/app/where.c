// where.c
// 06-14-95
inherit F_CLEAN_UP;
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
int main(object me, string str)
{
	object ob, where, *ob_list;
	int i;
	if (!str)
		return notify_fail("指令格式：where <人物或档名>\n"); 
	ob = find_player(str);
	if( !ob ) ob = find_living(str);
	if( !ob || !me->visible(ob)) {
		str = resolve_path(me->query("cwd"), str);
		ob_list = children(str);
		for(i=0; i<sizeof(ob_list); i++) {
			if( !ob = environment(ob_list[i]) ) continue;
		}
		return notify_fail("这个人不知道在那里耶...\n");
	}
	if (!ob) return notify_fail("现在没这个人.\n");
	where = environment(ob);
	if (!where) return notify_fail("这个人不知道在那里耶...\n");
	printf(YEL"\n你拿出水晶球，往里一看，哦！%s(%s)现在在...\n\n"NOR,
		(string)ob->name(),
		(string)ob->query("id"));
	"/cmds/std/look.c"->look_room(me,where);
	return 1;
}
int help(object me)
{
	write(@HELP
指令格式: where <玩家的 ID>
这个指令是用来得知玩家目前所在的位置.
HELP
	);
	return 1;
}

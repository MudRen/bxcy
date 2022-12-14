// quest.c
inherit F_CLEAN_UP;
int help(object me);
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
string time_period(int timep)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;
        if(d)
                time = chinese_number(d) + "天";
        else
                time = "";
        if(h)
                time += chinese_number(h) + "小时";
        if(m)
                time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";
        return time;
}
int main(object me, string arg)
{
	object ob;
	string str;
	mapping quest;
	if( wizardp(me) && arg ) {
		ob = find_player(arg);
		if( !ob ) ob = find_living(arg);
		if( !ob ) ob = present(arg, environment(me));
	}
	if( !ob ) ob = me;
	if (!mapp(quest=ob->query("quest"))){
		printf("%s目前没有任何任务！\n",ob==me?"你":ob->query("name"));
		return 1;
	}
	str=sprintf("%s的任务是：在%s内%s%s，",ob==me?"你":ob->query("name"),time_period(quest["time"]),quest["quest_type"],quest["quest"]);
	if (quest["task_time"]<time())
		str+=sprintf("%s已经没有足够的时间完成它了。\n",ob==me?"你":ob->query("name"));
	else
		str+=sprintf("%s还有%s的时间去完成它。\n",ob==me?"你":ob->query("name"),time_period(quest["task_time"]-time()));
	write(str);
	return 1;
}
int help(object me)
{
	write(@HELP
指令格式：quest <某人>
你可以用这个指令查询你目前的任务。
HELP
	);
	return 1;
}

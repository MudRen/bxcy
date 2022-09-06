// give.c
inherit F_CLEAN_UP;
int do_give(object me, object obj, object who,int amount);
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
	string target, item,str;
	object obj, who, *inv, obj2;
	int i, amount;
	if(!arg) return notify_fail("你要给谁什麽东西？\n");
	if( sscanf(arg, "%s to %s", str, target)==2
	|| sscanf(arg, "%s %s", target, str)==2 );
	else return notify_fail("你要给谁什麽东西？\n");
	if(!objectp(who = present(target, environment(me))))
		return notify_fail("这里没有这个人。\n");
	if (who==me) return notify_fail("给自己东西？好主意，不过没用！\n");
        if(me->is_busy())
         return notify_fail("还是先将你手上的事情做完了再给吧!\n");
         

    if( !who->is_character() || who->is_corpse() )
        return notify_fail("看清楚一点，那并不是活物。\n");

       if (!living(who)) return notify_fail("嗯!很显然,"+who->name()+"现在正躺着,不能马上爬起来接受你的馈赠!\n");
	if (who->query("env/no_accept")) return notify_fail(who->query("name")+"现在不打算接受别人的馈赠！\n");
			if (objectp(obj=present("thousand-gold",me))&&query_ip_name(me)==query_ip_name(who)&&str=="thousand-gold")
                return notify_fail("你想将金票给别人，可是想了想又有点舍不得!！\n");
	if(sscanf(str, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )	
			return notify_fail("你身上没有这样东西。\n");
			
	
		if( obj->query("no_drop") && !wizardp(me) )
			return notify_fail("这样东西不能随便给人。\n");
		        if (query_ip_name(me)==query_ip_name(who)&&obj->query("id")=="thousand-gold")
                return notify_fail("嘿嘿，你想干什么?！\n");
		if( amount < 1 )	return notify_fail("东西的数量至少是一个。\n");
		if(obj->query_amount() ){
			if( amount > obj->query_amount() ) return notify_fail("你没有那麽多的" + obj->name() + "。\n");
			else if( amount == (int)obj->query_amount() )	return do_give(me, obj, who,1);
			else {
				
				obj->set_amount( (int)obj->query_amount() - amount );
				obj2 = new(base_name(obj));
				obj2->set_amount(amount);
				if (!do_give(me, obj2, who,1)){
					obj->add_amount(amount );
					return 1;
				}return 1;
			}
		}		
                else return do_give(me, obj, who,amount);
	}
	if(sscanf(str, "all %s",item)==1) {
			
		if( !objectp(obj = present(item, me)) )
			return notify_fail("你身上没有这样东西。\n");
         
		return do_give(me, obj, who,1000);
	}
	
	 
	 if(str=="all") {
	 	if(objectp(obj = present("thousand-gold",me)) && query_ip_name(me)==query_ip_name(who))
	{write("哇， 连金票一起给，是不是搞错了？!\n");
	 return 1;}
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			do_give(me, inv[i], who,1);
		}
		write("Ok.\n");
		return 1;
	}
	if( !objectp(obj = present(str, me)) )
		return notify_fail("你身上没有这样东西。\n");
	return do_give(me, obj, who,1);
}
int do_give(object me, object obj, object who,int amount)
{
	string arg,str;
	int i=1;

        if( obj->query("no_drop") && (!wizardp(me)) && interactive(who))
		return notify_fail("这样东西不能随便给人。\n");
	arg=obj->query("id");
	str=obj->query("unit")+obj->name();
	if( !interactive(who) && !who->accept_object(me, obj) )
	 if (QUEST->quest_give (me, who, obj)) {
                     message_vision("$N给$n一"+obj->query("unit")+obj->name()+"。\n",me,who);
                        message_vision("$N由衷地向$n道谢。\n",who,me);
                        destruct(obj);
                        return 1;
                } else
		return notify_fail("你只能把东西送给其他玩家操纵的人物。\n");
	    
	if (obj){
		for (i=0;i<amount;i++){
			if (!userp(who) && !who->query("accept"))	destruct(obj);
			else if(! obj->move(who)) { return obj->move(who);}
			if( !objectp(obj = present(arg, me)) ){i++;break;}
		}
	}
	message_vision(sprintf("$N给$n%s%s。\n",CHINESE_D->chinese_number(i),str),me,who);
	return 1;
}
int help(object me)
{
write(@HELP
指令格式 : give <物品名称> to <某人>
      或 : give <某人> <物品名称>
 
这个指令可以让你将某样物品给别人, 当然, 首先你要拥有这样物品.
 
HELP
    );
    return 1;
}

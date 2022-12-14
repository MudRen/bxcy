// drop.c
// #pragma save_binary
inherit F_CLEAN_UP;
int do_drop(object me, object obj,int amount);
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
	object obj, *inv, obj2;
	int i, amount;
	string item;
	if(!arg) return notify_fail("你要丢弃什麽东西？\n");
	if(sscanf(arg, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("你身上没有这样东西。\n");
		if( stringp(obj->query("no_drop")) )
			return notify_fail( (string)obj->query("no_drop") );
		if( obj->query_amount() ){
			if( amount < 1 )  return notify_fail("东西的数量至少是一个。\n");
			if( amount > obj->query_amount() ) return notify_fail("你没有那麽多的" + obj->name() + "。\n");
			else if( amount == (int)obj->query_amount() )
				return do_drop(me, obj,1);
			else {
				obj->set_amount( (int)obj->query_amount() - amount );
				obj2 = new(base_name(obj));
				obj2->set_amount(amount);
				return do_drop(me, obj2,1);
			}
		}else{
			return do_drop(me, obj,amount);
		}
	}
	if(sscanf(arg, "all %s",item)==1) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("你身上没有这样东西。\n");
		return do_drop(me, obj,1000);
	}
	if(arg=="all") {
		inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++) {
                        if (i>49)  break;
			do_drop(me, inv[i],1);
		}
		write("Ok.\n");
		return 1;
	}
	if( !objectp(obj = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");
	return do_drop(me, obj,1);
}
int do_drop(object me, object obj,int amount)
{
	mixed no_drop;
        object ob;
	int i;
      string arg=obj->short(1);
	if (!wizardp(me) && no_drop = obj->query("no_drop"))
		return notify_fail( stringp(no_drop) ? no_drop : "这样东西不能随意丢弃。\n");
    reset_eval_cost();
        i=0;
	foreach ( ob in all_inventory(me)){
                if (ob->short(1)!=arg) continue;
        	if (!wizardp(me) && no_drop = ob->query("no_drop")){
                       write(ob->name(1)+stringp(no_drop) ? no_drop : "这样东西不能随意丢弃。\n");
                       continue;
                }
		if (ob->move(environment(me))) {
			if( ob->is_character() )
				message_vision("$N将$n从背上放了下来，躺在地上。\n", me, ob);
			else {
				message_vision( sprintf("$N丢下一%s$n。\n",	ob->query("unit")),
					me, ob );
				if (ob->id("illicit salt"))	me->delete_temp("illicit");
				if( !ob->query("value") && !ob->value() ) {
					if (ob->id("biao yin"))
						write("因为这样东西太值钱，所以很快人们就把它给瓜分了。\n");
					else
						write("因为这样东西并不值钱，所以人们并不会注意到它的存在。\n");
					destruct(ob);
				}
			}
		}
                i++;
                if(i >= amount)
                    return 1;
	}
	return 1;
}
int help(object me)
{
	write(@HELP
指令格式 : drop <物品名称>||<数量> <物品名称>||<all> <物品名称>

这个指令可以让你丢下你所携带的物品。

HELP
    );
    return 1;
}

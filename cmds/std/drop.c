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
	if(!arg) return notify_fail("��Ҫ����ʲ�ᶫ����\n");
	if(sscanf(arg, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("������û������������\n");
		if( stringp(obj->query("no_drop")) )
			return notify_fail( (string)obj->query("no_drop") );
		if( obj->query_amount() ){
			if( amount < 1 )  return notify_fail("����������������һ����\n");
			if( amount > obj->query_amount() ) return notify_fail("��û��������" + obj->name() + "��\n");
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
			return notify_fail("������û������������\n");
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
		return notify_fail("������û������������\n");
	return do_drop(me, obj,1);
}
int do_drop(object me, object obj,int amount)
{
	mixed no_drop;
        object ob;
	int i;
      string arg=obj->short(1);
	if (!wizardp(me) && no_drop = obj->query("no_drop"))
		return notify_fail( stringp(no_drop) ? no_drop : "���������������ⶪ����\n");
    reset_eval_cost();
        i=0;
	foreach ( ob in all_inventory(me)){
                if (ob->short(1)!=arg) continue;
        	if (!wizardp(me) && no_drop = ob->query("no_drop")){
                       write(ob->name(1)+stringp(no_drop) ? no_drop : "���������������ⶪ����\n");
                       continue;
                }
		if (ob->move(environment(me))) {
			if( ob->is_character() )
				message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, ob);
			else {
				message_vision( sprintf("$N����һ%s$n��\n",	ob->query("unit")),
					me, ob );
				if (ob->id("illicit salt"))	me->delete_temp("illicit");
				if( !ob->query("value") && !ob->value() ) {
					if (ob->id("biao yin"))
						write("��Ϊ��������ֵ̫Ǯ�����Ժܿ����ǾͰ������Ϸ��ˡ�\n");
					else
						write("��Ϊ������������ֵǮ���������ǲ�����ע�⵽���Ĵ��ڡ�\n");
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
ָ���ʽ : drop <��Ʒ����>||<����> <��Ʒ����>||<all> <��Ʒ����>

���ָ��������㶪������Я������Ʒ��

HELP
    );
    return 1;
}

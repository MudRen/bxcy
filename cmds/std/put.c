// put.c
inherit F_CLEAN_UP;
int do_put(object me, object obj, object dest,int amount);
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
	string target, item;
	object obj, dest, *inv, obj2;
	int i, amount;
	if(!arg) return notify_fail("��Ҫ��ʲ�ᶫ���Ž����\n");
	if( sscanf(arg, "%s in %s", item, target)!=2 )
		return notify_fail("��Ҫ��˭ʲ�ᶫ����\n");
	dest = present(target, me);
	if( !dest || living(dest) ) dest = present(target, environment(me));
	if( !dest || living(dest) )
		return notify_fail("����û������������\n");
	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("������û������������\n");
		if( amount < 1 )
			return notify_fail("����������������һ����\n");
		if( obj->query_amount() ){
			if( amount > obj->query_amount() )
			return notify_fail("��û��������" + obj->name() + "��\n");
			else if( amount == (int)obj->query_amount() )
			return do_put(me, obj, dest,1);
			else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			return do_put(me, obj2, dest,1);
			return 1;
			}
		}else   { do_put(me, obj, dest,amount);return 1;}
	}
	if(item=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if( inv[i] != dest ) do_put(me, inv[i], dest,1);
		write("Ok.\n");
		return 1;
	}
	if(!objectp(obj = present(item, me)))
		return notify_fail("������û������������\n");
	return do_put(me, obj, dest,1);
}
int do_put(object me, object obj, object dest,int amount)
{
	string str,arg;
	int i;
if(!dest->is_container())
return notify_fail(obj->name()+"���ܷŽ�"+dest->name()+"�\n");
if((obj->query("money_id")&&obj->query("money_id")!="thousand-gold")||        	
(obj->query("no_drop") || obj->query("no_put")))
  return notify_fail(obj->name()+"���ܷŽ�"+dest->name()+"�\n");
	if (obj==dest)	return notify_fail("����������Ҳ�У�\n");
	str=obj->query("id");
	arg=obj->query("unit")+obj->name();
if(obj->is_character()&& (dest->is_corpse()||dest->is_character()||
dest->query("id")=="skeleton"))
return notify_fail("����������Ҳ�У�\n");
if(userp(obj)) return notify_fail("����������Ҳ�У�\n");
	for (i=0;i<amount;i++){
		if( obj->move(dest) ) {
                if (dest->query("no_put") && obj ) 
                  destruct(obj);
			if(!objectp(obj = present(str, me))) {i++;break;}
		}else{	tell_object(me,obj->name()+"��"+dest->name()+"����̫���ˡ�\n");
			if (!obj->move(me))	obj->move(environment(me));
			return 1;}
	}
	if( !dest->is_character() || dest->is_corpse() ){
		dest->add("no_clean_up",1);
		message_vision( sprintf("$N��%s%s�Ž�%s��\n",
		CHINESE_D->chinese_number(i),arg,dest->name()),me );
	}else{
		message_vision( sprintf("$N͵͵�ؽ�%s%s�Ž�%s�����ϡ�\n",
		CHINESE_D->chinese_number(i),arg,dest->name()),me );
	}
	return 1;
}
int help(object me)
{
write(@HELP
ָ���ʽ : put <��Ʒ����> in <ĳ����>
 
���ָ��������㽫ĳ����Ʒ�Ž�һ����������Ȼ��������Ҫӵ��������Ʒ��
 
HELP
    );
    return 1;
}

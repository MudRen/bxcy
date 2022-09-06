int pay_player(object who, int amount)
{
        object ob;
	seteuid(getuid());
        if (amount < 1)
                amount = 1;
        if (amount / 10000) {
                ob = new(GOLD_OB);
                ob->set_amount(amount / 10000);
                ob->move(who,1);
                amount %= 10000;
        }
        if (amount / 100) {
                ob = new(SILVER_OB);
                ob->set_amount(amount / 100);
                ob->move(who,1);
                amount %= 100;
        }
        if (amount) {
                ob = new(COIN_OB);
                ob->set_amount(amount);
                ob->move(who,1);
        }
        return 1;
}
string value_string(int value1,int value)
{
    string str;
    if (value1){
        str=((int)(value1/10000)?chinese_number(value1/10000)+"��":"") +chinese_number(value1%10000)+ "��";
    if( value < 1 ) return str+"���ƽ�";
    else    if( value < 100 )
        return str +"���ƽ�"+ chinese_number(value) + "��Ǯ";
    else    if( value < 10000 )
        return str +"���ƽ�"+chinese_number(value/100) + "������"
            + (value%100? "��" + chinese_number(value%100) + "��Ǯ": "");
    else
        return str + chinese_number(value/10000) + "���ƽ�"
            +( (value%10000)/100 ? chinese_number((value%10000)/100) + "������" : "")
            +( (value%10000)%100 ? "��" + chinese_number((value%10000)%100) + "��Ǯ": "");
    }else   {
    if( value < 1 ) return "";
    else    if( value < 100 )
        return chinese_number(value) + "��Ǯ";
    else    if( value < 10000 )
        return chinese_number(value/100) + "������"
            + (value%100? "��" + chinese_number(value%100) + "��Ǯ": "");
    else
        return chinese_number(value/10000) + "���ƽ�"
            +( (value%10000)/100 ? chinese_number((value%10000)/100) + "������" : "")
            +( (value%10000)%100 ? "��" + chinese_number((value%10000)%100) + "��Ǯ": "");
    }
}
int do_convert(string arg)
{
    string from, to;
    int amount, bv1, bv2,total;
    object from_ob, to_ob;
    if( !arg || sscanf(arg, "%d %s to %s", amount, from, to)!=3 )
        return notify_fail("ָ���ʽ��convert <����> <��������> to <��������>\n");
    from_ob = present(from + "_money", this_player());
    to_ob = present(to + "_money", this_player());
    if( !to_ob && file_size("/clone/money/" + to + ".c") < 0 )
        return notify_fail("����һ���һ��Ǯ��\n");
    if( !from_ob )
        return notify_fail("������û�����ֻ��ҡ�\n");
    if( amount < 1 )
        return notify_fail("�һ�����һ������Ҫ�һ�һ����\n");
        
    if((total= (int)from_ob->query_amount()) < amount )
        return notify_fail("������û�������" + from_ob->query("name") + "��\n");
    bv1 = from_ob->query("base_value");
    if( !bv1 ) return notify_fail("���ֶ�����ֵǮ��\n");
    bv2 = to_ob ? to_ob->query("base_value") : call_other("/clone/money/" + to, "query", "base_value" );
    if( bv1 == bv2 ) return notify_fail("�����Ĳ����İ���\n");
    if (bv1>1000000 && amount>100) amount=100;
    if( bv1 < bv2 ) amount -= amount % (bv2 / bv1);
    if( amount==0 ) return notify_fail("��Щ" + from_ob->query("name") + "�ļ�ֵ̫���ˣ�������\n");
    if ((amount * bv1 / bv2)>100000 || (amount * bv1 / bv2)<0)  return notify_fail("��ׯ���ֲ��㣬��������ô��Ǯ��\n");
    if( !to_ob ){
        if (!(to_ob = find_object("/clone/money/" + to)))
        to_ob = load_object("/clone/money/" + to);
        to_ob = new("/clone/money/" + to);
        if (!to_ob->move(this_player())){
            to_ob->set_amount(amount * bv1 / bv2);
            to_ob->move(environment(this_player()));
        }else   to_ob->set_amount(amount * bv1 / bv2);
    } else
        to_ob->add_amount(amount * bv1 / bv2);
    message_vision( sprintf("$N������ȡ��%s%s%s������%s%s%s��\n",
        chinese_number(amount), from_ob->query("base_unit"), from_ob->query("name"),
        chinese_number(amount * bv1 / bv2), to_ob->query("base_unit"), to_ob->query("name")),
        this_player() );
    from=base_name(from_ob);
    destruct(from_ob);
    if (total-amount>0){
        from_ob=new(from);
        if (!from_ob->move(this_player())){
            from_ob->set_amount(total-amount);
            from_ob->move(environment(this_player()));
        }else   from_ob->set_amount(total-amount);
    }
    if (!to_ob->move(this_player()))    to_ob->move(environment(this_player()));
    return 1;
}
// ��Ǯ
int do_deposit(string arg)
{
    string money;
    int amount,value,i,total;
    object money_ob;
    if( !arg)
        return notify_fail("ָ���ʽ��deposit <����>||all <��������>\n");
    if ( sscanf(arg, "%d %s", amount, money)!=2 )
        if (sscanf(arg, "all %s", money)!=1 )
        return notify_fail("ָ���ʽ��deposit <����>||all <��������>\n");
    money_ob = present(money + "_money", this_player());
    if( !money_ob)
        return notify_fail("������û�����֡�Ǯ����\n");
    if (!amount)    amount=money_ob->query_amount();
    if( amount < 1 )    return notify_fail("���١�����Ҫ��һ���Ӱɣ�\n");
    if (money_ob->query("base_value")>10000 && amount>100){
        tell_object(this_player(),"һ�����ֻ�ܴ�һ����"+money_ob->query("name")+"��\n");
        amount=100;
    }
    if((total=(int)money_ob->query_amount()) < amount )
        return notify_fail("������û��������" + money_ob->query("name") + "��\n");
    message_vision( sprintf("$N������ȡ��%s%s%s������Ǯׯ��\n",
        chinese_number(amount), money_ob->query("base_unit"), money_ob->query("name")),
        this_player() );
    if (money_ob->query("base_value")>10000){
        reset_eval_cost();
        for (i=0;i<amount;i++){
            value=money_ob->query("base_value")+this_player()->query("money");
            this_player()->add("more_money",value/100000000);
            this_player()->set("money",value%100000000);
        }
    }else{
        value=amount*money_ob->query("base_value")+this_player()->query("money");
        this_player()->add("more_money",value/100000000);
        this_player()->set("money",value%100000000);
    }
    money=base_name(money_ob);
    destruct(money_ob);
    if (total-amount>0){
        money_ob=new(money);
        if (!money_ob->move(this_player())){
            money_ob->set_amount(total-amount);
            money_ob->move(environment(this_player()));
        }else   money_ob->set_amount(total-amount);
    }
    return 1;
}
int do_withdraw(string arg)
{
    string money;
    int amount,value_money;
    object money_ob;
    if( !arg || sscanf(arg, "%d %s", amount, money)!=2 )
        return notify_fail("ָ���ʽ��withdraw <����> <��������>\n");
    if (file_size("/clone/money/" + money + ".c") < 0)
        return notify_fail("��ֻ��ȡ��Ǯ����\n");
    money_ob = new("/clone/money/"+money);
    if (money_ob->query("base_value")>10000)
        return notify_fail("��ֻ��ȡ�ƽ����ӻ�ͭ�壡\n");
    if( amount < 1 )    return notify_fail("���١�����Ҫȡһ���Ӱɣ�\n");
    value_money=amount*money_ob->query("base_value");
    if (value_money<100) return notify_fail("����Ҫȡһ�ٸ�ͭ�壡\n");
    if (value_money>20000000)
        return notify_fail("ȡ��ô��Ǯ���㲻�±����ô��\n");
    if (value_money*101/100 >this_player()->query("money") && this_player()->query("more_money")<1)
            return notify_fail("��û����ô���\n");
    message_vision( sprintf("$N��Ǯׯȡ��%s��\n",
    value_string((value_money)/100000000,(value_money)%100000000)),
        this_player() );
    pay_player(this_player(), value_money);
    
    if (value_money>this_player()->query("money")){
        this_player()->add("more_money",-1);
        this_player()->add("money",100000000-value_money/100*101);
    }
    else
    this_player()->add("money",-value_money/100*101);
    return 1;
}
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
int do_check(string arg)
{
    object ob,me;
    me=this_player();
    if (arg){
        if( wizardp(me)) {
            ob = find_player(arg);
            if( !ob ) ob = find_living(arg);
            if( !ob ) ob = present(arg, environment(me));
        }else   return 0;
    }
    if (!objectp(ob))   ob=this_player();
    if (ob->query("money") || ob->query("more_money")){
      if (ob->query("more_money")>100) ob->set("more_money",100);
        tell_object(me , sprintf(this_object()->name()+"���ĵĸ����㣬%s�ڱ�ׯ������%s��\n",
            ob==me?"��":ob->query("name"),
            value_string(ob->query("more_money"),ob->query("money")) ) );
    }   else
        tell_object(me , sprintf("%sû���κδ�\n",ob==me?"��":ob->query("name")));
        return 1;
}

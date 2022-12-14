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
        str=((int)(value1/10000)?chinese_number(value1/10000)+"亿":"") +chinese_number(value1%10000)+ "万";
    if( value < 1 ) return str+"两黄金";
    else    if( value < 100 )
        return str +"两黄金"+ chinese_number(value) + "文钱";
    else    if( value < 10000 )
        return str +"两黄金"+chinese_number(value/100) + "两白银"
            + (value%100? "又" + chinese_number(value%100) + "文钱": "");
    else
        return str + chinese_number(value/10000) + "两黄金"
            +( (value%10000)/100 ? chinese_number((value%10000)/100) + "两白银" : "")
            +( (value%10000)%100 ? "又" + chinese_number((value%10000)%100) + "文钱": "");
    }else   {
    if( value < 1 ) return "";
    else    if( value < 100 )
        return chinese_number(value) + "文钱";
    else    if( value < 10000 )
        return chinese_number(value/100) + "两白银"
            + (value%100? "又" + chinese_number(value%100) + "文钱": "");
    else
        return chinese_number(value/10000) + "两黄金"
            +( (value%10000)/100 ? chinese_number((value%10000)/100) + "两白银" : "")
            +( (value%10000)%100 ? "又" + chinese_number((value%10000)%100) + "文钱": "");
    }
}
int do_convert(string arg)
{
    string from, to;
    int amount, bv1, bv2,total;
    object from_ob, to_ob;
    if( !arg || sscanf(arg, "%d %s to %s", amount, from, to)!=3 )
        return notify_fail("指令格式：convert <数量> <货币种类> to <货币种类>\n");
    from_ob = present(from + "_money", this_player());
    to_ob = present(to + "_money", this_player());
    if( !to_ob && file_size("/clone/money/" + to + ".c") < 0 )
        return notify_fail("你想兑换哪一种钱？\n");
    if( !from_ob )
        return notify_fail("你身上没有这种货币。\n");
    if( amount < 1 )
        return notify_fail("兑换货币一次至少要兑换一个。\n");
        
    if((total= (int)from_ob->query_amount()) < amount )
        return notify_fail("你身上没有那麽多" + from_ob->query("name") + "。\n");
    bv1 = from_ob->query("base_value");
    if( !bv1 ) return notify_fail("这种东西不值钱。\n");
    bv2 = to_ob ? to_ob->query("base_value") : call_other("/clone/money/" + to, "query", "base_value" );
    if( bv1 == bv2 ) return notify_fail("你无聊不无聊啊？\n");
    if (bv1>1000000 && amount>100) amount=100;
    if( bv1 < bv2 ) amount -= amount % (bv2 / bv1);
    if( amount==0 ) return notify_fail("这些" + from_ob->query("name") + "的价值太低了，换不起。\n");
    if ((amount * bv1 / bv2)>100000 || (amount * bv1 / bv2)<0)  return notify_fail("本庄人手不足，换不了这么多钱。\n");
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
    message_vision( sprintf("$N从身上取出%s%s%s，换成%s%s%s。\n",
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
// 存钱
int do_deposit(string arg)
{
    string money;
    int amount,value,i,total;
    object money_ob;
    if( !arg)
        return notify_fail("指令格式：deposit <数量>||all <货币种类>\n");
    if ( sscanf(arg, "%d %s", amount, money)!=2 )
        if (sscanf(arg, "all %s", money)!=1 )
        return notify_fail("指令格式：deposit <数量>||all <货币种类>\n");
    money_ob = present(money + "_money", this_player());
    if( !money_ob)
        return notify_fail("你身上没有这种「钱」！\n");
    if (!amount)    amount=money_ob->query_amount();
    if( amount < 1 )    return notify_fail("至少、起码要存一个子吧？\n");
    if (money_ob->query("base_value")>10000 && amount>100){
        tell_object(this_player(),"一次最多只能存一百张"+money_ob->query("name")+"。\n");
        amount=100;
    }
    if((total=(int)money_ob->query_amount()) < amount )
        return notify_fail("你身上没有那麽多的" + money_ob->query("name") + "。\n");
    message_vision( sprintf("$N从身上取出%s%s%s，存入钱庄。\n",
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
        return notify_fail("指令格式：withdraw <数量> <货币种类>\n");
    if (file_size("/clone/money/" + money + ".c") < 0)
        return notify_fail("你只能取『钱』！\n");
    money_ob = new("/clone/money/"+money);
    if (money_ob->query("base_value")>10000)
        return notify_fail("你只能取黄金、银子或铜板！\n");
    if( amount < 1 )    return notify_fail("至少、起码要取一个子吧？\n");
    value_money=amount*money_ob->query("base_value");
    if (value_money<100) return notify_fail("至少要取一百个铜板！\n");
    if (value_money>20000000)
        return notify_fail("取这么多钱，你不怕被打劫么？\n");
    if (value_money*101/100 >this_player()->query("money") && this_player()->query("more_money")<1)
            return notify_fail("你没有那么多存款！\n");
    message_vision( sprintf("$N从钱庄取出%s。\n",
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
        tell_object(me , sprintf(this_object()->name()+"悄悄的告诉你，%s在敝庄共存有%s。\n",
            ob==me?"你":ob->query("name"),
            value_string(ob->query("more_money"),ob->query("money")) ) );
    }   else
        tell_object(me , sprintf("%s没有任何存款！\n",ob==me?"你":ob->query("name")));
        return 1;
}

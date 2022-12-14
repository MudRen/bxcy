int give_money(object who, int amount)
{
    object ob;
    if( amount < 1 ) amount = 1;
        if( amount/10000 ) {
        if (!ob=present("gold_money", who)){
                    ob = new(GOLD_OB);
            if ( !ob->move(who) ){
                ob->set_amount(amount/10000);
                ob->move(environment(who));
            }else   ob->set_amount(amount/10000);
        }else   ob->add_amount(amount/10000);
        amount %= 10000;
    }
    if( amount/100 ) {
        if (!ob=present("silver_money", who)){
                    ob = new(SILVER_OB);
            if (!ob->move(who)){
                ob->set_amount(amount/100);
                ob->move(environment(who));
            }else   ob->set_amount(amount/100);
        }else   ob->add_amount(amount/100);
        amount %= 100;
    } 
    if( amount ) {
        if (!ob=present("coin_money", who)){
            ob = new(COIN_OB);
            if (!ob->move(who)){
                ob->set_amount(amount);
                ob->move(environment(who));
            }else   ob->set_amount(amount);
        }else   ob->add_amount(amount);
    }
    return 1;
}
string string_value(int value1,int value)
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
int sell_salt(string arg)
{
    object obj,me,room;
    string str;
    int value,amount,all_amount;
    if( !arg )
        return notify_fail("你要卖断什麽物品？\n");
        if(sscanf(arg, "%d %s", amount,str)==2 )
        arg=str;
    if( !(obj = present(arg, this_player())) )
        return notify_fail("你身上没有这东东。\n");
    if (!obj->id("illicit salt"))
        return notify_fail("这东西我不要！有没有些其他的东东?\n");
    all_amount=obj->query_amount();
    if (!amount || amount>all_amount)
    amount=all_amount;
    if (amount<1) return notify_fail("什么？几斤？你当我是三岁小孩呀？\n");
    me=this_object();
    if (! room=find_object(me->query("startroom")))
        room=load_object(me->query("startroom"));
    if (room!=environment()){
        command("say 快来人呀，有人贩卖私盐！");
        return 1;
    }
    if (me->query("need_salt")>0){
        if (me->query("need_salt")<amount){
            command("shake");
            command("say 本店只需要"+CHINESE_D->chinese_number(me->query("need_salt"))+"斤盐。");
            return 1;
        }
    }else   return notify_fail(me->name()+"大惊失色：私盐？！可是违法的呀！\n");
    value=amount*obj->query("base_value")/10*(10+random(15));
    give_money(this_player(), value);
    message_vision("$N把身上的" + CHINESE_D->chinese_number(amount)+ obj->query("base_unit")+obj->name() + "卖掉"+ string_value(0,value)+"。\n",
        this_player());
    me->add("need_salt",-amount);
   this_player()->add("potential",amount/2);
   this_player()->add("qi",-amount/5);
   str=base_name(obj);
   value=all_amount-amount;
   destruct(obj);
    if (value>0){
        obj=new(str);
        if (!obj->move(this_player()))  obj->move(environment(this_player()));
        obj->set_amount(value);
    }else   this_player()->delete_temp("illicit");
    return 1;
}


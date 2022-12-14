// cmds/std/auction.c 拍卖与竞价程序
// call_out() 映射控制版 for sz xo2(xkx)
// By Shure@mudbuilder.net 2001-8-17
/*
key  string ob_id      物品ID
v[0] object obj        拍卖物品     
v[1] int    ob_price   竞标价格               
v[2] object ob_auction 竞标者                 
v[3] object ob_onwer   物品所有者             
v[4] string ob_desc    物品所有者对该物品的介绍
v[5] string auction_id 竞标者ID
v[6] string onwer_id   物主ID
v[7] string ob_name    物品名称
v[8] string ob_long    物品描述

mapping structure:
auction[obj : {ob, ob_price, ob_auction, ob_onwer, ob_desc, auction_id, ...} ]
*/

#include <ansi.h>
inherit F_DBASE;

#define PRICE_DIFFERENCE 100

static mapping auction = ([]);

// 状态变化的控制中心
void auction_chat(string msg);  
void auction_state_check(int times, int s_times, int last_price, string obj_id); 
// 静止的状态切换
void auction_end(string ob_name, int ob_price, mixed ob_auction, object ob_onwer, object ob, string ob_id);
void auction_cancel(string ob_id, object discredit_1, object discredit_2);
// 实现拍卖
void get_ob_desc(string desc, object me, string str, int num);
void choise_secret(string decide, object me, string ob_id, string desc, int num);
// 数据反馈
int player_demand(int num, string unit, object me);
int player_bank(object ob);
int player_pay(object who, int amount);
int help();

// channeld.c需要增加auction频道
/*
	"auction":([	"msg_speak": HIY "【拍卖场】%s: %s\n" NOR,
			"msg_color": HIY,
		]),
*/

int clean_up(){ return 1;}

void create()
{
	seteuid(ROOT_UID);
	set("name", "拍卖指令");
	set("id", "auction");
	set("channel_id","");
}

void auction_chat(string msg) 
{	
	msg = replace_string(msg,NOR,HIY);	
	CHANNEL_D->do_channel(this_object(),"auction",msg);
}

void auction_state_check(int times, int s_times, int last_price, string obj_id)
{
	int i, ob_price, flag1 = 0, flag2 = 0;
	object ob, ob_auction, ob_onwer, new_auction, new_onwer, nul;
	mixed *values, *v;
	string *k, ob_name, ob_id, str;
	
	// 重新定位此物品，避免因为其他物品被清除导致索引号变化
	k = keys(auction);
	i = member_array(obj_id,k); 
	v = values(auction)[i];
	ob_id      = k[i];
	ob         = v[0];
	ob_price   = v[1];
	ob_auction = v[2];
	ob_onwer   = v[3];
	ob_name    = v[7];
	
	if(!objectp(ob_auction) && !stringp(ob_auction))
	{
		flag1++;
		if(objectp(new_auction = find_player(v[5])))
		{
			ob_auction = new_auction;
			flag1 = 0;
		}
	}
	if(!objectp(ob_onwer))
	{
		flag2++;
		if(objectp(new_onwer = find_player(v[6])))
		{
			ob_onwer = new_onwer;
			flag2 = 0;
		}
	}

	if(flag2 && !flag1) 
	{
		str="由于卖方缺席，取消"+ob_name+"的拍卖";
		auction_chat(str);
		auction_cancel(ob_id, ob_auction, nul);
		return;
	}
	if(!objectp(ob) || !objectp(present(ob,ob_onwer)))
	{
		str="由于卖方保管不当，拍卖物品"+ob_name+"丢失，本次拍卖取消！\n";
		auction_chat(str);
		ob_onwer->delete_temp("auctioning");
		auction_cancel(ob_id, ob_auction, nul);
		return;
	}
	if(times < 20)
	{
		times++;
		if(ob_price > last_price)
		{
			s_times = 0;
			call_out("auction_state_check", 20, times, s_times, ob_price, ob_id);
		}
		else
		{
			s_times++;
			if(s_times<4)
			{
				str = "第"+CHINESE_D->chinese_number(s_times)+"次喊价:拍卖"+ob_name+"，现价"+MONEY_D->price_str(ob_price)+"!!";
				auction_chat(str);   
				call_out("auction_state_check", 10, times, s_times, ob_price, ob_id);
			}
			else
			{
				if(flag1 && !flag2)
				{
					str="由于买方缺席，取消"+ob_name+"的拍卖！";
					auction_chat(str);
					auction_cancel(ob_id, ob_onwer, nul);
					return;
				}
				if(flag1 && flag2)
				{
					str="由于买卖双方缺席，取消"+ob_name+"的拍卖！";
					auction_chat(str);
					auction_cancel(ob_id, nul, nul);
					return;
				}				
				auction_end(ob_name, ob_price, ob_auction, ob_onwer, ob, ob_id);
			}
		}
	}
	else
	{
		if(flag1 && !flag2)
		{
			str="由于买方缺席，取消"+ob_name+"的拍卖！";
			auction_chat(str);
			auction_cancel(ob_id, ob_onwer, nul);
			return;
		}
		if(flag1 && flag2)
		{
			str="由于买卖双方缺席，取消"+ob_name+"的拍卖！";
			auction_chat(str);
			auction_cancel(ob_id, nul, nul);
			return;
		}
		str = "时间已到，拍卖"+ob_name+"的过程到此为止！\n";
		auction_chat(str);
		auction_end(ob_name, ob_price, ob_auction, ob_onwer, ob, ob_id);
		return;
	}
		if(ob_auction->is_ghost()||ob_onwer->is_ghost())
			{
				str="由于买卖双方有缺席，取消"+ob_name+"的拍卖";
				auction_chat(str);
				auction_cancel(ob_id, nul, nul);
				return;
			}
	return ;
}

void auction_end(string ob_name, int ob_price, mixed ob_auction, object ob_onwer, object ob, string ob_id)
{

	object  *inv, *en_inv, nul;
	string onwer_id, str;

	if(!objectp(ob_onwer))	return;  // 虽然不太可能发生，但还是判断下保险
	onwer_id = ob_onwer->query_temp("auction/"+ob_id);
		if(ob_auction->is_ghost()||ob_onwer->is_ghost())
			{
//				str="由于买卖双方有缺席，取消"+ob_name+"的拍卖";
//				auction_chat(str);
				auction_cancel(ob_id, nul, nul);
				return;
			}	
	if(stringp(ob_auction))
	{
		str=onwer_id+ " 以底价 "+MONEY_D->price_str(ob_price)+" 拍卖 "+
		ob_name+"，三次喊价后无人投标，本次拍卖无效！\n";		
		auction_cancel(ob_id, ob_onwer, nul);
		ob_onwer->set("auction_fail",ob_onwer->query("mud_age"));
	}
	else
	{
		str=ob_auction->query("name")+"("+ob_auction->query("id")+")"+ " 出价 "+MONEY_D->price_str(ob_price)+" 竞标 "+
		ob_name+"成功，本次拍卖成交！\n";
			
		inv = all_inventory(ob_auction); 
		en_inv = all_inventory(environment(ob_auction)); 
		if(!player_pay(ob_auction, (int)(ob_price))) 
		{
			str="由于买方无力支付竞价，本次拍卖无效。\n";
			ob_auction->delete_temp("auctioning");
			auction_cancel(ob_id, ob_onwer, nul);
		}
		else
		{
			tell_object(ob_auction,"恭喜！你竞标成功，得到了 "+ob_name+"\n");
				if(!ob->move(ob_auction) || (inv && sizeof(inv) > 49))
				{
					if(en_inv && sizeof(en_inv) < 49)
					{
						tell_object(ob_auction, "你手头已经拿不下了,东西落到了你的脚边..\n");
						ob->move(environment(ob_auction)); 
					}
					else
					{
						tell_object(ob_auction, "此次拍卖所得由于你无力保管而收归国有！\n");
					 	destruct(ob);
					}
				}	
				tell_object(ob_onwer,ob_name+"拍卖成功，所得款已经转至你的钱庄帐户。\n");
				ob_onwer->add("more_money",(ob_price+ob_onwer->query("money"))/100000000);
				ob_onwer->set("money",(ob_price+ob_onwer->query("money"))%100000000);
			auction_cancel(ob_id, ob_auction, ob_onwer);
		}
	}
	auction_chat(str);
	return;
}

void auction_cancel(string ob_id, object discredit_1, object discredit_2)
{
	if(member_array(ob_id, keys(auction)) != -1)
		map_delete(auction, ob_id);

	if(objectp(discredit_1))
		discredit_1->delete("discredit");
	if(objectp(discredit_2))
		discredit_2->delete("discredit");
}

int main(object me,string arg)
{
	int i, coin, guaranty, num, index;
	mixed *ob_value;
	string str, unit, *tuned_ch, *ob_key;
	object ob;
	
	ob_key = keys(auction);
	ob_value = values(auction);
	if(!arg)
	{
		tuned_ch = me->query("channels");
		if( !pointerp(tuned_ch) )
			me->set("channels", ({ "auction" }) );
		else if( member_array(auction, tuned_ch) == -1 )
			me->set("channels", tuned_ch + ({ "auction" }) );
		tell_object(me,"\n你的拍卖频道(auction)现在处于开通状态\n");
		return 1;
	}	
		
	if(arg == "-l")
	{
	    	if(!sizeof(auction))
		{
			tell_object(me,"目前没有物品被拍卖。\n");
			return 1;
		}
		str=HIG"当前拍卖物品清单：\n\n";
		str += "—————————————————————————————————————\n";
		str += "序号  物品名称                 当前标价             最高竞价者\n";
                str += "—————————————————————————————————————\n"NOR;
		for(i=0; i < sizeof(auction);i++)
		{
			mixed  *v = ob_value[i];

			str += sprintf("%-4s  ",  i+1+".");
			str += sprintf("%-20s  ", v[7]);
			str += sprintf("%-20s  ", MONEY_D->price_str(v[1]));
			str += sprintf("%-15s  \n", (!stringp(v[2]))? v[5] : "");
		}
		str += "\n\n";
        	me->start_more(str);
		return 1;
	}
	if(arg == "-m")
	{
		if(!sizeof(auction))
		{
			tell_object(me,"目前没有物品被拍卖。\n");
			return 1;
		}
		str=HIG"当前拍卖物品详细介绍：\n\n"NOR;
		for(i=0; i < sizeof(auction);i++)
		{
			mixed  *v = ob_value[i];

			str+=HIG+(i+1)+".\n----------"NOR"\n物品名称： "+v[7]+
			"\n物品描述："+v[8]+
			"\n物主介绍："+v[4]+
			"\n物主："+v[6]+"\n\n";
		}
       		me->start_more(str);		
		return 1;
	}
	if(sscanf(arg,"%s for %d %s",str,num,unit) == 3)
	{
		str = lower_case(str);
if(me->is_ghost())
return notify_fail("你都要见阎王了，哪来的时间去发财呀！\n");
		if(me->is_busy())
		{
			tell_object(me,"你正忙着呢。\n");
			return 1;
		}
		if(me->query("discredit") && !me->query_temp("auctioning"))
		{
			if(me->query("mud_age") - me->query("discredit") < 3600)	
			{
				tell_object(me,"你由于在上次拍卖过程中信誉值降低，暂时无权参与。\n");
				return 1;
			}
			else me->delete("discredit");			
		}
		if(me->query("mud_age") - me->query("auction_fail") < 300)
		{
			tell_object(me,"你上次拍卖的物品无人问津，这回还是先花点时间调查市场吧。\n");
			return 1;		
		}
		if(sizeof(auction)>5) // 决定同时间内有多少拍卖进程可以并存
		{
			tell_object(me,"拍卖物品队列已满，请少候。\n");
			return 1;
		}
		if(!objectp(ob = present(str,me)))
		{
			tell_object(me,"你身上没有 "+HIG+str+NOR+" 这件物品。\n");
			return 1;
		}		
		if(member_array(ob->query("id"),ob_key)!= -1)
		{
			tell_object(me,"你晚了一步，这类物品已经有人拍卖了。\n");
			return 1;
		}
		
		if(ob->query("no_drop") || ob->query("no_give") || ob->query("ownmake") || ob->query("money_id") || ob->is_character() )
		{
			tell_object(me,"这件物品不能参加拍卖。\n");
			return 1;
		}

		unit = lower_case(unit);
		if(!(num = player_demand(num, unit, me))) return 1;
		
		write("你所要拍卖的物品："+ob->query("name")+"， 底价："+MONEY_D->price_str(num)+"\n\n");
		write("请输入你对该物品的介绍（控制在50个字符内）\n直接按回车(enter)可以忽略此项。\n");
		input_to("get_ob_desc", me, ob->query("id"), num);
		return 1;
	}
	if(sscanf(arg,"%d add %d %s", index,num,unit) == 3)
	{
		object obj, ob_onwer;
		mixed *v; 
		int ob_price; 
if(me->is_ghost())
return notify_fail("你都要见阎王了，哪来的时间去发财呀！\n");
		if(me->is_busy())
		{
			tell_object(me,"你正忙着呢。\n");
			return 1;
		}
		if(me->query("discredit") && !me->query_temp("auctioning"))
		{
			if(me->query("mud_age") - me->query("discredit") < 3600)	
			{
				tell_object(me,"你由于在上次拍卖过程中信誉值降低，暂时无权参与。\n");
				return 1;
			}
			else me->delete("discredit");			
		}
		if(index < 1 || index > sizeof(auction))
		{
			tell_object(me,"没有这个序号的物品！\n请用 auction -l 指令查询目前竞拍物品清单。\n");
			return 1;
		}
		v = ob_value[index-1];
		obj = v[0];
		ob_price = v[1];
		
		if(objectp(obj) && v[3] == me)
		{
			tell_object(me,"那是你自己的拍卖物品，想暗地托价不成？\n");
			return 1;
		}
		coin = player_bank(me);
		unit = lower_case(unit);
                if(!(num = player_demand(num, unit, me))) return 1;
		if(num < PRICE_DIFFERENCE)
		{
			tell_object(me,"竞拍规则：差价以1两白银为底线。\n");
			return 1;
		}
		if((num + ob_price)/10 > coin)
		{
			tell_object(me,"你没有这么多钱可以偿付这个出价。\n");
			return 1;
		}
		if((num + ob_price) > 1000000000)
		{
			tell_object(me,"对不起，交易金额已达到本行上限。\n");
			return 1;
		}
		me->set("discredit",me->query("mud_age"));
		me->set_temp("auctioning",1);
		me->start_busy(10);
		v[1] = num + ob_price;
		v[2] = me;
		v[5] = me->query("id");
		str = me->query("name")+"("+me->query("id")+")投标"+v[7]+"，竞价："+MONEY_D->price_str(v[1])+"!\n";
		auction_chat(str);
		return 1;
	}
	else return help();
}

void get_ob_desc(string desc, object me, string str, int num)
{
	write("\n");
	if (strlen(desc) > 60)
	{
		write("您对物品的介绍太长了，请注意言简意赅。\n");
	        input_to("get_ob_desc", me, str, num);
                return ;
	}
	write("作为物主，您是否愿意在拍卖过程中透露自己姓名？(y/n)\n");
	input_to("choise_secret", me, str, desc, num);	
        return;
}

void choise_secret(string yn, object me, string ob_id, string desc, int num)
{
	mixed *values;
	int guaranty, i;
	string ob_name, onwer_id, str;
	object ob;

	if (yn[0] != 'y' && yn[0] != 'Y')
		me->set_temp("auction/"+ob_id, "某人");
        else 
        	me->set_temp("auction/"+ob_id, me->query("name")+"("+me->query("id")+")");
	if(!objectp(ob = present(ob_id, me)))
	{
		tell_object(me,"你身上已经没有这件东西了，不能参加拍卖。\n");
		return;
	}        	
	if(sizeof(auction) && member_array(ob_id,keys(auction))!= -1)
	{
		tell_object(me,"你晚了一步，这类物品已经被人抢先拍卖了。\n");
		return;
	}
	onwer_id = me->query_temp("auction/"+ob_id);
	ob_name = ob->query("name")+"("+ob_id+")";

	// 以下设置信任属性，判断违反拍卖规则的玩家
	me->set("discredit",me->query("mud_age"));
	me->set_temp("auctioning",1);
	me->start_busy(10);
	
        values = ({ob, num, "", me , desc, "", onwer_id, ob_name, ob->long()});
	auction[ob_id] = values;
	
	str = onwer_id+"现在开始拍卖"+ob_name+"，"+"底价："+MONEY_D->price_str(num)+"。\n";
	auction_chat(str);
	call_out("auction_state_check", 10, 0, 0, num,ob_id);
	return;
}

int player_demand(int num, string unit, object me)
{
	switch(unit)
	{
		case "coin":break;
		case "silver":num*=100;break;
		case "gold":num*=10000;break;
		case "cash":
		case "thousand-cash":
		        tell_object(me,"拍卖交易中不得使用银票，请先在钱庄兑换成硬通货。\n");
			return 0;
		default:
			tell_object(me,"非法的货币单位！\nvalid unit: coin, silver, gold\n");
			return 0;
	}
	if (num < 1000)
	{
		tell_object(me,"对不起，本行不支持无底价拍卖，10两银子是出价底线。\n");
		return 0;
	}
	if (num > 100000000)
	{
		tell_object(me,"对不起，单次叫价，1万两黄金为上限。\n");
		return 0;
	}
	return num;
}

int player_bank(object ob)
{
	object g_ob;
	object c_ob;
	object s_ob;
	int total;

	total = ob->query("money");

	g_ob = present("gold_money", ob);
	c_ob = present("coin_money", ob);
	s_ob = present("silver_money", ob);

	if (g_ob) total += g_ob->query_amount() * 10000;
	if (s_ob) total += s_ob->query_amount() * 100;
	if (c_ob)   total += c_ob->query_amount();
	total /=10;
	total +=ob->query("more_money") * 10000000;
	return total;
}

int player_pay(object who, int amount)
{
	object g_ob, s_ob, c_ob;
	int gc, sc, cc, left, total, more,totalt;

	seteuid(getuid());

	if (g_ob = present("gold_money", who))
		gc = g_ob->query_amount();
	else
		gc = 0;
	if (s_ob = present("silver_money", who))
		sc = s_ob->query_amount();
	else
		sc = 0;
	if (c_ob = present("coin_money", who))
		cc = c_ob->query_amount();
	else
		cc = 0;
	total = cc + sc * 100 + gc * 10000;
	totalt = who->query("money");
	totalt += who->query("more_money") * 10000000;
	if ( total < amount )
	{
		if((amount-total)/10 > totalt)
			return 0;
		if(objectp(c_ob)) destruct(c_ob);
		if(objectp(s_ob)) destruct(s_ob);
		if(objectp(g_ob)) destruct(g_ob);	
		if((amount-total)>who->query("money")){
			who->add("more_money",-(amount-total)/100000000-1);
			who->add("money",100000000-(amount-total)%100000000);
		}else
		who->add("money",-(amount-total)); 
			tell_object(who,"你身上的零钱不够，所需费用已直接从钱庄帐户上扣除。\n\n");
		return 1;
	}
	else 
	{
		left = total - amount;
		gc = left / 10000;
		left = left % 10000;
		sc = left / 100;
		cc = left % 100;

		if (g_ob)
			g_ob->set_amount(gc);
		else sc += (gc * 100);
		if (s_ob)
		 	s_ob->set_amount(sc);
		else if (sc) {
			s_ob = new(SILVER_OB);
			s_ob->set_amount(sc);
			s_ob->move(who);
		}
		if (c_ob)
			c_ob->set_amount(cc);
		else if (cc) {
			c_ob = new(COIN_OB);
			c_ob->set_amount(cc);
			c_ob->move(who);
		}
		return 1;
	}
}

int help()
{	
    write(@HELP命令格式：
    
    开启拍卖频道：auction
    关闭拍卖频道：tune auction
    查看目前处于竞拍状态的物品清单：auction -l
    查看目前处于竞拍状态的物品介绍：auction -m
    拍卖物品：auction <物品ID> for <底价值> <货币单位>
    竞拍物品：auction <物品序列号> add <加价值> <货币单位>    		
HELP
    );
    return 1;
}

 

  

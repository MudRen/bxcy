// cmds/std/auction.c �����뾺�۳���
// call_out() ӳ����ư� for sz xo2(xkx)
// By Shure@mudbuilder.net 2001-8-17
/*
key  string ob_id      ��ƷID
v[0] object obj        ������Ʒ     
v[1] int    ob_price   ����۸�               
v[2] object ob_auction ������                 
v[3] object ob_onwer   ��Ʒ������             
v[4] string ob_desc    ��Ʒ�����߶Ը���Ʒ�Ľ���
v[5] string auction_id ������ID
v[6] string onwer_id   ����ID
v[7] string ob_name    ��Ʒ����
v[8] string ob_long    ��Ʒ����

mapping structure:
auction[obj : {ob, ob_price, ob_auction, ob_onwer, ob_desc, auction_id, ...} ]
*/

#include <ansi.h>
inherit F_DBASE;

#define PRICE_DIFFERENCE 100

static mapping auction = ([]);

// ״̬�仯�Ŀ�������
void auction_chat(string msg);  
void auction_state_check(int times, int s_times, int last_price, string obj_id); 
// ��ֹ��״̬�л�
void auction_end(string ob_name, int ob_price, mixed ob_auction, object ob_onwer, object ob, string ob_id);
void auction_cancel(string ob_id, object discredit_1, object discredit_2);
// ʵ������
void get_ob_desc(string desc, object me, string str, int num);
void choise_secret(string decide, object me, string ob_id, string desc, int num);
// ���ݷ���
int player_demand(int num, string unit, object me);
int player_bank(object ob);
int player_pay(object who, int amount);
int help();

// channeld.c��Ҫ����auctionƵ��
/*
	"auction":([	"msg_speak": HIY "����������%s: %s\n" NOR,
			"msg_color": HIY,
		]),
*/

int clean_up(){ return 1;}

void create()
{
	seteuid(ROOT_UID);
	set("name", "����ָ��");
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
	
	// ���¶�λ����Ʒ��������Ϊ������Ʒ��������������ű仯
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
		str="��������ȱϯ��ȡ��"+ob_name+"������";
		auction_chat(str);
		auction_cancel(ob_id, ob_auction, nul);
		return;
	}
	if(!objectp(ob) || !objectp(present(ob,ob_onwer)))
	{
		str="�����������ܲ�����������Ʒ"+ob_name+"��ʧ����������ȡ����\n";
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
				str = "��"+CHINESE_D->chinese_number(s_times)+"�κ���:����"+ob_name+"���ּ�"+MONEY_D->price_str(ob_price)+"!!";
				auction_chat(str);   
				call_out("auction_state_check", 10, times, s_times, ob_price, ob_id);
			}
			else
			{
				if(flag1 && !flag2)
				{
					str="������ȱϯ��ȡ��"+ob_name+"��������";
					auction_chat(str);
					auction_cancel(ob_id, ob_onwer, nul);
					return;
				}
				if(flag1 && flag2)
				{
					str="��������˫��ȱϯ��ȡ��"+ob_name+"��������";
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
			str="������ȱϯ��ȡ��"+ob_name+"��������";
			auction_chat(str);
			auction_cancel(ob_id, ob_onwer, nul);
			return;
		}
		if(flag1 && flag2)
		{
			str="��������˫��ȱϯ��ȡ��"+ob_name+"��������";
			auction_chat(str);
			auction_cancel(ob_id, nul, nul);
			return;
		}
		str = "ʱ���ѵ�������"+ob_name+"�Ĺ��̵���Ϊֹ��\n";
		auction_chat(str);
		auction_end(ob_name, ob_price, ob_auction, ob_onwer, ob, ob_id);
		return;
	}
		if(ob_auction->is_ghost()||ob_onwer->is_ghost())
			{
				str="��������˫����ȱϯ��ȡ��"+ob_name+"������";
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

	if(!objectp(ob_onwer))	return;  // ��Ȼ��̫���ܷ������������ж��±���
	onwer_id = ob_onwer->query_temp("auction/"+ob_id);
		if(ob_auction->is_ghost()||ob_onwer->is_ghost())
			{
//				str="��������˫����ȱϯ��ȡ��"+ob_name+"������";
//				auction_chat(str);
				auction_cancel(ob_id, nul, nul);
				return;
			}	
	if(stringp(ob_auction))
	{
		str=onwer_id+ " �Ե׼� "+MONEY_D->price_str(ob_price)+" ���� "+
		ob_name+"�����κ��ۺ�����Ͷ�꣬����������Ч��\n";		
		auction_cancel(ob_id, ob_onwer, nul);
		ob_onwer->set("auction_fail",ob_onwer->query("mud_age"));
	}
	else
	{
		str=ob_auction->query("name")+"("+ob_auction->query("id")+")"+ " ���� "+MONEY_D->price_str(ob_price)+" ���� "+
		ob_name+"�ɹ������������ɽ���\n";
			
		inv = all_inventory(ob_auction); 
		en_inv = all_inventory(environment(ob_auction)); 
		if(!player_pay(ob_auction, (int)(ob_price))) 
		{
			str="����������֧�����ۣ�����������Ч��\n";
			ob_auction->delete_temp("auctioning");
			auction_cancel(ob_id, ob_onwer, nul);
		}
		else
		{
			tell_object(ob_auction,"��ϲ���㾺��ɹ����õ��� "+ob_name+"\n");
				if(!ob->move(ob_auction) || (inv && sizeof(inv) > 49))
				{
					if(en_inv && sizeof(en_inv) < 49)
					{
						tell_object(ob_auction, "����ͷ�Ѿ��ò�����,�����䵽����Ľű�..\n");
						ob->move(environment(ob_auction)); 
					}
					else
					{
						tell_object(ob_auction, "�˴����������������������ܶ��չ���У�\n");
					 	destruct(ob);
					}
				}	
				tell_object(ob_onwer,ob_name+"�����ɹ������ÿ��Ѿ�ת�����Ǯׯ�ʻ���\n");
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
		tell_object(me,"\n�������Ƶ��(auction)���ڴ��ڿ�ͨ״̬\n");
		return 1;
	}	
		
	if(arg == "-l")
	{
	    	if(!sizeof(auction))
		{
			tell_object(me,"Ŀǰû����Ʒ��������\n");
			return 1;
		}
		str=HIG"��ǰ������Ʒ�嵥��\n\n";
		str += "��������������������������������������������������������������������������\n";
		str += "���  ��Ʒ����                 ��ǰ���             ��߾�����\n";
                str += "��������������������������������������������������������������������������\n"NOR;
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
			tell_object(me,"Ŀǰû����Ʒ��������\n");
			return 1;
		}
		str=HIG"��ǰ������Ʒ��ϸ���ܣ�\n\n"NOR;
		for(i=0; i < sizeof(auction);i++)
		{
			mixed  *v = ob_value[i];

			str+=HIG+(i+1)+".\n----------"NOR"\n��Ʒ���ƣ� "+v[7]+
			"\n��Ʒ������"+v[8]+
			"\n�������ܣ�"+v[4]+
			"\n������"+v[6]+"\n\n";
		}
       		me->start_more(str);		
		return 1;
	}
	if(sscanf(arg,"%s for %d %s",str,num,unit) == 3)
	{
		str = lower_case(str);
if(me->is_ghost())
return notify_fail("�㶼Ҫ�������ˣ�������ʱ��ȥ����ѽ��\n");
		if(me->is_busy())
		{
			tell_object(me,"����æ���ء�\n");
			return 1;
		}
		if(me->query("discredit") && !me->query_temp("auctioning"))
		{
			if(me->query("mud_age") - me->query("discredit") < 3600)	
			{
				tell_object(me,"���������ϴ���������������ֵ���ͣ���ʱ��Ȩ���롣\n");
				return 1;
			}
			else me->delete("discredit");			
		}
		if(me->query("mud_age") - me->query("auction_fail") < 300)
		{
			tell_object(me,"���ϴ���������Ʒ�����ʽ���ػ����Ȼ���ʱ������г��ɡ�\n");
			return 1;		
		}
		if(sizeof(auction)>5) // ����ͬʱ�����ж����������̿��Բ���
		{
			tell_object(me,"������Ʒ�������������ٺ�\n");
			return 1;
		}
		if(!objectp(ob = present(str,me)))
		{
			tell_object(me,"������û�� "+HIG+str+NOR+" �����Ʒ��\n");
			return 1;
		}		
		if(member_array(ob->query("id"),ob_key)!= -1)
		{
			tell_object(me,"������һ����������Ʒ�Ѿ����������ˡ�\n");
			return 1;
		}
		
		if(ob->query("no_drop") || ob->query("no_give") || ob->query("ownmake") || ob->query("money_id") || ob->is_character() )
		{
			tell_object(me,"�����Ʒ���ܲμ�������\n");
			return 1;
		}

		unit = lower_case(unit);
		if(!(num = player_demand(num, unit, me))) return 1;
		
		write("����Ҫ��������Ʒ��"+ob->query("name")+"�� �׼ۣ�"+MONEY_D->price_str(num)+"\n\n");
		write("��������Ը���Ʒ�Ľ��ܣ�������50���ַ��ڣ�\nֱ�Ӱ��س�(enter)���Ժ��Դ��\n");
		input_to("get_ob_desc", me, ob->query("id"), num);
		return 1;
	}
	if(sscanf(arg,"%d add %d %s", index,num,unit) == 3)
	{
		object obj, ob_onwer;
		mixed *v; 
		int ob_price; 
if(me->is_ghost())
return notify_fail("�㶼Ҫ�������ˣ�������ʱ��ȥ����ѽ��\n");
		if(me->is_busy())
		{
			tell_object(me,"����æ���ء�\n");
			return 1;
		}
		if(me->query("discredit") && !me->query_temp("auctioning"))
		{
			if(me->query("mud_age") - me->query("discredit") < 3600)	
			{
				tell_object(me,"���������ϴ���������������ֵ���ͣ���ʱ��Ȩ���롣\n");
				return 1;
			}
			else me->delete("discredit");			
		}
		if(index < 1 || index > sizeof(auction))
		{
			tell_object(me,"û�������ŵ���Ʒ��\n���� auction -l ָ���ѯĿǰ������Ʒ�嵥��\n");
			return 1;
		}
		v = ob_value[index-1];
		obj = v[0];
		ob_price = v[1];
		
		if(objectp(obj) && v[3] == me)
		{
			tell_object(me,"�������Լ���������Ʒ���밵���м۲��ɣ�\n");
			return 1;
		}
		coin = player_bank(me);
		unit = lower_case(unit);
                if(!(num = player_demand(num, unit, me))) return 1;
		if(num < PRICE_DIFFERENCE)
		{
			tell_object(me,"���Ĺ��򣺲����1������Ϊ���ߡ�\n");
			return 1;
		}
		if((num + ob_price)/10 > coin)
		{
			tell_object(me,"��û����ô��Ǯ���Գ���������ۡ�\n");
			return 1;
		}
		if((num + ob_price) > 1000000000)
		{
			tell_object(me,"�Բ��𣬽��׽���Ѵﵽ�������ޡ�\n");
			return 1;
		}
		me->set("discredit",me->query("mud_age"));
		me->set_temp("auctioning",1);
		me->start_busy(10);
		v[1] = num + ob_price;
		v[2] = me;
		v[5] = me->query("id");
		str = me->query("name")+"("+me->query("id")+")Ͷ��"+v[7]+"�����ۣ�"+MONEY_D->price_str(v[1])+"!\n";
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
		write("������Ʒ�Ľ���̫���ˣ���ע���Լ����ࡣ\n");
	        input_to("get_ob_desc", me, str, num);
                return ;
	}
	write("��Ϊ���������Ƿ�Ը��������������͸¶�Լ�������(y/n)\n");
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
		me->set_temp("auction/"+ob_id, "ĳ��");
        else 
        	me->set_temp("auction/"+ob_id, me->query("name")+"("+me->query("id")+")");
	if(!objectp(ob = present(ob_id, me)))
	{
		tell_object(me,"�������Ѿ�û����������ˣ����ܲμ�������\n");
		return;
	}        	
	if(sizeof(auction) && member_array(ob_id,keys(auction))!= -1)
	{
		tell_object(me,"������һ����������Ʒ�Ѿ��������������ˡ�\n");
		return;
	}
	onwer_id = me->query_temp("auction/"+ob_id);
	ob_name = ob->query("name")+"("+ob_id+")";

	// ���������������ԣ��ж�Υ��������������
	me->set("discredit",me->query("mud_age"));
	me->set_temp("auctioning",1);
	me->start_busy(10);
	
        values = ({ob, num, "", me , desc, "", onwer_id, ob_name, ob->long()});
	auction[ob_id] = values;
	
	str = onwer_id+"���ڿ�ʼ����"+ob_name+"��"+"�׼ۣ�"+MONEY_D->price_str(num)+"��\n";
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
		        tell_object(me,"���������в���ʹ����Ʊ��������Ǯׯ�һ���Ӳͨ����\n");
			return 0;
		default:
			tell_object(me,"�Ƿ��Ļ��ҵ�λ��\nvalid unit: coin, silver, gold\n");
			return 0;
	}
	if (num < 1000)
	{
		tell_object(me,"�Բ��𣬱��в�֧���޵׼�������10�������ǳ��۵��ߡ�\n");
		return 0;
	}
	if (num > 100000000)
	{
		tell_object(me,"�Բ��𣬵��νмۣ�1�����ƽ�Ϊ���ޡ�\n");
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
			tell_object(who,"�����ϵ���Ǯ���������������ֱ�Ӵ�Ǯׯ�ʻ��Ͽ۳���\n\n");
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
    write(@HELP�����ʽ��
    
    ��������Ƶ����auction
    �ر�����Ƶ����tune auction
    �鿴Ŀǰ���ھ���״̬����Ʒ�嵥��auction -l
    �鿴Ŀǰ���ھ���״̬����Ʒ���ܣ�auction -m
    ������Ʒ��auction <��ƷID> for <�׼�ֵ> <���ҵ�λ>
    ������Ʒ��auction <��Ʒ���к�> add <�Ӽ�ֵ> <���ҵ�λ>    		
HELP
    );
    return 1;
}

 

  

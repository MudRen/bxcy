// natured.c
#include <ansi.h>
// #pragma save_binary
#define TIME_TICK (time()*60)
#define TIME_TICK1 (time()*60)

nosave int current_day_phase, current_month;

mapping *day_phase;

nosave string ppl;

string *month_desc = ({
	HIW"隆冬的"NOR,
	HIW"寒冬的"NOR,
	HIG"初春的"NOR,
	HIG"早春二月的"NOR,
	HIG"阳春三月的"NOR,
	HIC"初夏的"NOR,
	HIC"盛夏的"NOR,
	HIR"仲夏的"NOR,
	HIY"初秋的"NOR,
	HIY"秋高气爽的"NOR,
	YEL"深秋的"NOR,
	WHT"初冬的"NOR,
});

mapping *read_table(string file);
void init_day_phase();

void create()
{
	string get_month, get_day;
	mixed *local;
	local = localtime(TIME_TICK1);
        get_day = CHINESE_D->chinese_number(local[3]);
	get_month = CHINESE_D->chinese_number(local[4]);
	switch(get_month)
	{
		//spring weather
		case "三":
		case "四":
		case "五":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/spring_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/spring_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/spring_wind");
			   break;
		     }
		     break;
		//summer weather
		case "六":
		case "七":
		case "八":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/summer_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/summer_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/summer_wind");
			   break;
		     }
		     break;
		//autumn weather
		case "九":
		case "十":
		case "十一":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/autumn_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/autumn_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/autumn_wind");
			   break;
		     }
		     break;
		//winter weather
                case "零":
		case "二":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/winter_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/winter_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/winter_wind");
			   break;
		     }
		case "一":
		        if(get_day=="一")
		      { day_phase = read_table("/adm/etc/nature/spring");break;}
		      else switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/winter_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/winter_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/winter_wind");
			   break;
		     }

		     break;
		default:
		     day_phase = read_table("/adm/etc/nature/day_phase");
	}


	init_day_phase();
}

void init_day_phase()
{
	mixed *local;
	int i, t;


	local = localtime(TIME_TICK1);
	t = local[2] * 60 + local[1];


	for( i=0; i < sizeof(day_phase); i++)
		if( t >= day_phase[i]["length"] )
			t -= (int)day_phase[i]["length"];
		else
			break;

	current_day_phase = (i==0? sizeof(day_phase)-1: i - 1);
	current_month = local[4];


	remove_call_out("init_day_phase");
	call_out("init_day_phase", 3600);


	remove_call_out("update_day_phase");



	call_out("update_day_phase",
	(int)day_phase[(current_day_phase+1) % sizeof(day_phase)]["length"] - t);
}

void update_day_phase()
{
        remove_call_out("update_day_phase");

        current_day_phase = (++current_day_phase) % sizeof(day_phase);
switch (day_phase[current_day_phase]["outcolor"])
        {
              case "BLK":
message("shout", HIW"◎"HIM"苍茫大地     "BLK + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "RED":
message("shout", HIW"◎"HIM"苍茫大地     "RED + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIR":
message("shout", HIW"◎"HIM"苍茫大地     "HIR + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "GRN":
message("shout", HIW"◎"HIM"苍茫大地     "GRN + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIG":
message("shout", HIW"◎"HIM"苍茫大地     "HIG + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "YEL":
message("shout", HIW"◎"HIM"苍茫大地     "YEL + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIY":
message("shout", HIW"◎"HIM"苍茫大地     "HIY + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "BLU":
message("shout", HIW"◎"HIM"苍茫大地     "BLU + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIB":
message("shout", HIW"◎"HIM"苍茫大地     "HIB + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "MAG":
message("shout", HIW"◎"HIM"苍茫大地     "MAG + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIM":
message("shout", HIW"◎"HIM"苍茫大地     "HIM + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "CYN":
message("shout", HIW"◎"HIM"苍茫大地     "CYN + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIC":
message("shout", HIW"◎"HIM"苍茫大地     "HIC + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "WHT":
message("shout", HIW"◎"HIM"苍茫大地     "WHT + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIW":
message("shout", HIW"◎"HIM"苍茫大地     "HIW + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              default:
message("shout", HIW"◎"HIM"苍茫大地     "HIG + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
        }
//        message("outdoor:vision", day_phase[current_day_phase]["time_msg"] + "\n", users());
        if( !undefinedp(day_phase[current_day_phase]["event_fun"]) )
            call_other(this_object(), day_phase[current_day_phase]["event_fun"]);

        call_out("update_day_phase", day_phase[current_day_phase]["length"]);
}
void event_morning()
{
	object badguy;
	object room;
        if (random(12) == 1)
        {
		if(objectp(room=load_object("/d/city/guangchang")) &&
		objectp(badguy = new("/quest/weiguo/japan/japan4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
  message("shout", HIY"【朝廷急报】"HIR + "在扬州城中发现日本奸细！\n"NOR,users() );
	}
        if (random(12) == 2)
        {
		if(objectp(room=load_object("/d/city2/di_anmen")) &&
		objectp(badguy = new("/quest/weiguo/japan/japan4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
  message("shout", HIY"【朝廷急报】"HIM + "在北京城中发现日本奸细！\n"NOR,users() );
	}
        if (random(12) == 3)
        {
		if(objectp(room=load_object("/d/city3/guangchang")) &&
		objectp(badguy = new("/quest/weiguo/japan/japan4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
 message("shout", HIY"【朝廷急报】"HIM + "在成都城中发现日本奸细！\n"NOR,users() );
	}
        if (random(12) == 4)
        {
if(objectp(room=load_object("/d/lingjiu/changl11")) &&
		objectp(badguy = new("/quest/weiguo/jinbing/jin4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
message("shout", HIB"【朝廷急报】"GRN + "在灵鹫宫中发现金国奸细！\n"NOR,users() );
	}
        if (random(12) == 5)
        {
if(objectp(room=load_object("/d/wanjiegu/road1")) &&
		objectp(badguy = new("/quest/weiguo/jinbing/jin4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
message("shout", HIB"【朝廷急报】"GRN + "在大理城中发现金国奸细！\n"NOR,users() );
	}
        if (random(12) == 6)
        {
if(objectp(room=load_object("/d/wudang/shiliang")) &&
		objectp(badguy = new("/quest/weiguo/jinbing/jin4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
message("shout", HIB"【朝廷急报】"GRN + "在武当山中发现金国奸细！\n"NOR,users() );
	}
        if (random(12) == 7)
        {
if(objectp(room=load_object("/d/tianlongsi/dadao1")) &&
		objectp(badguy = new("/quest/weiguo/menggu/mengu4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
message("shout", HIG"【朝廷急报】"CYN + "在大理城中发现蒙古奸细！\n"NOR,users() );
	}
        if (random(12) == 8)
        {
if(objectp(room=load_object("/d/city/nanmen")) &&
		objectp(badguy = new("/quest/weiguo/menggu/mengu4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
message("shout", HIG"【朝廷急报】"CYN + "在扬州城中中发现蒙古奸细！\n"NOR,users() );
	}
        if (random(12) == 9)
        {
if(objectp(room=load_object("/d/city2/dongmen")) &&
		objectp(badguy = new("/quest/weiguo/menggu/mengu4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
message("shout", HIG"【朝廷急报】"CYN + "在北京城中中发现蒙古奸细！\n"NOR,users() );
	}
        if (random(12) == 10)
        {
		if(objectp(room=load_object("/d/quanzhou/zhongxin")) &&
		objectp(badguy = new("/quest/weiguo/xixiabing/xixia4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
  message("shout", HIR"【朝廷急报】"BLU + "在泉州城中发现西夏奸细！\n"NOR,users() );
	}
        if (random(12) == 11)
        {
if(objectp(room=load_object("/d/quanzhou/tieqiang")) &&
		objectp(badguy = new("/quest/weiguo/xixiabing/xixia4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
message("shout", HIR"【朝廷急报】"BLU + "在泉州城中发现西夏奸细！\n"NOR,users() );
	}
        if (random(12) == 12)
        {
if(objectp(room=load_object("/d/dali/xidajie3")) &&
		objectp(badguy = new("/quest/weiguo/xixiabing/xixia4")))
		badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
message("shout", HIR"【朝廷急报】"BLU + "在大理城中发现西夏奸细！\n"NOR,users() );
	}
        if (random(16) == 1)
        {
if(objectp(room=load_object("/d/city3/westchengmen")) &&
		objectp(badguy = new("/quest/weiguo/xixiabing/xixia3")))
		badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia2");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia1");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia1");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia1");
                badguy->move(room);
                badguy = new("/quest/weiguo/xixiabing/xixia1");
                badguy->move(room);
message("shout", HIR"【前线告急】"HIW + "西夏大军攻打西北的军事重镇成都！\n"NOR,users() );
	}
        if (random(16) == 2)
        {
		if(objectp(room=load_object("/d/quanzhou/zhongxin")) &&
		objectp(badguy = new("/quest/weiguo/japan/japan3")))
		badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan2");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
                badguy = new("/quest/weiguo/japan/japan1");
                badguy->move(room);
  message("shout", HIR"【前线告急】"HIW + "倭寇大军在泉州附近登陆！杀我百姓!!\n"NOR,users() );
	}
        if (random(16) == 4)
        {
if(objectp(room=load_object("/d/city/ximen")) &&
		objectp(badguy = new("/quest/weiguo/menggu/mengu3")))
		badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu2");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu1");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu1");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu1");
                badguy->move(room);
                badguy = new("/quest/weiguo/menggu/mengu1");
                badguy->move(room);
message("shout", HIR"【前线告急】"HIW + "蒙古大军进军事重镇扬州！扬州告急!!\n"NOR,users() );
	}
        if (random(16) == 7)
        {
		if(objectp(room=load_object("/d/city2/di_anmen.")) &&
		objectp(badguy = new("/quest/weiguo/jinbing/jin3")))
		badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin2");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin1");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin1");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin1");
                badguy->move(room);
                badguy = new("/quest/weiguo/jinbing/jin1");
                badguy->move(room);
  message("shout", HIR"【前线告急】"HIW + "金国完颜氏的部队杀入了京城！京城告危!!\n"NOR,users() );
	}
}
void event_night()
{
	object badguy;
	object room;
        if (random(12) == 1)
        {
		if(objectp(room=load_object("/d/city/guangchang")) &&
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("shout", HIW"【官府通告】"HIR + "扬州城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
	}
        if (random(12) == 2)
        {
		if(objectp(room=load_object("/d/city2/di_anmen")) &&
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("shout", HIW"【官府通告】"HIR + "北京城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
	}
        if (random(12) == 3)
        {
		if(objectp(room=load_object("/d/city3/guangchang")) &&
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("shout", HIW"【官府通告】"HIR + "成都城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
	}
        if (random(12) == 4)
        {
if(objectp(room=load_object("/d/changan/ca28")) &&
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("shout", HIW"【官府通告】"HIR + "长安城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
	}
        if (random(12) == 5)
        {
if(objectp(room=load_object("/d/tianlongsi/dadao4")) &&
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("shout", HIW"【官府通告】"HIR + "大理城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
	}
        if (random(12) == 6)
        {
if(objectp(room=load_object("/d/changan/ca16")) &&
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
message("shout", HIW"【官府通告】"HIR + "长安城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
	}
        if (random(12) == 7)
        {
if(objectp(room=load_object("/d/dali/guangcang")) &&
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
message("shout", HIW"【官府通告】"HIR + "大理城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
	}
        if (random(12) == 8)
        {
if(objectp(room=load_object("/d/city3/guangchang")) &&
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
message("shout", HIW"【官府通告】"HIR + "成都城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
	}
        if (random(12) == 9)
        {
if(objectp(room=load_object("/d/changan/ca")) &&
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
message("shout", HIW"【官府通告】"HIR + "长安城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
	}
        if (random(12) == 10)
        {
		if(objectp(room=load_object("/d/quanzhou/zhongxin")) &&
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("shout", HIW"【官府通告】"HIR + "泉州城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
	}
        if (random(12) == 11)
        {
if(objectp(room=load_object("/d/city/nandajie1")) &&
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
message("shout", HIW"【官府通告】"HIR + "扬州城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
	}
        if (random(12) == 12)
        {
if(objectp(room=load_object("/d/city2/tian_anm")) &&
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
message("shout", HIW"【官府通告】"HIR + "北京城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
	}

}
void event_afternoon()
{
	object *ob_list;
	int i;
	ob_list = children("/quest/weiguo/japan/japan1");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
		message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
	ob_list = children("/quest/weiguo/japan/japan2");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
		message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
	ob_list = children("/quest/weiguo/japan/japan3");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
		message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
	ob_list = children("/quest/weiguo/japan/japan4");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
		message_vision("$N说道：天要黑了，东西也到手了，我闪！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
	ob_list = children("/quest/weiguo/jinbing/jin1");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
		message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
	ob_list = children("/quest/weiguo/jinbing/jin2");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
		message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/jinbing/jin3");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
		message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/jinbing/jin4");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
		message_vision("$N说道：天要黑了，东西也到手了，我闪！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/menggu/mengu1");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
		message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/menggu/mengu2");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
		message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/menggu/mengu3");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
		message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/menggu/mengu4");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
		message_vision("$N说道：天要黑了，东西也到手了，我闪！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/xixiabing/xixia1");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
		message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/xixiabing/xixia2");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
		message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/xixiabing/xixia3");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
		message_vision("$N说道：天要黑了，撤兵！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
     	ob_list = children("/quest/weiguo/xixiabing/xixia4");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
		message_vision("$N说道：天要黑了，东西也到手了，我闪！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
}
void event_dawn()
{
	object *ob_list;
	int i;
	ob_list = children("/quest/feizei/feizei");
                for(i=0; i<sizeof(ob_list); i++)
		if(environment(ob_list[i]))
		{
			message_vision("$N笑道：天亮了，东西也到手了，我闪！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
}

void event_midnight()
{

	string get_month, get_day;
	mixed *local;
	local = localtime(TIME_TICK1);
	get_day = CHINESE_D->chinese_number(local[3]);
	get_month = CHINESE_D->chinese_number(local[4]);
	switch(get_month)
	{
		//spring weather
		case "三":
		case "四":
		case "五":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/spring_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/spring_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/spring_wind");
			   break;
		     }
		     break;
		//summer weather
		case "六":
		case "七":
		case "八":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/summer_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/summer_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/summer_wind");
			   break;
		     }
		     break;
		//autumn weather
		case "九":
		case "十":
		case "十一":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/autumn_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/autumn_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/autumn_wind");
			   break;
		     }
		     break;
		//winter weather
                case "零":
		case "二":
		     switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/winter_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/winter_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/winter_wind");
			   break;
		     }

		     case "一":
		        if(get_day=="一")
		      { day_phase = read_table("/adm/etc/nature/spring");break;}
		      else switch(random(3))
		     {
			case 0:
			   day_phase = read_table("/adm/etc/nature/winter_rain");
			   break;
			case 1:
			   day_phase = read_table("/adm/etc/nature/winter_sun");
			   break;
			case 2:
			   day_phase = read_table("/adm/etc/nature/winter_wind");
			   break;
		     }
		     break;
		default:
		     day_phase = read_table("/adm/etc/nature/day_phase");
	}


}


void event_noon()
{
	object *ob;
	int i, con, con1, con2, con3;
	string get_month,ill,msg;
	mixed *local;
	local = localtime(TIME_TICK1);
	get_month = CHINESE_D->chinese_number(local[4]);
	switch(get_month)
	{
		case "三":
		case "四":
		case "五":
		     ill = "ill_kesou";
		     msg = "忽然喉头一阵痕痒，你感觉似乎要咳嗽了。\n" ;
		     break;
		case "六":
		case "七":
		case "八":
		     ill = "ill_zhongshu";
		     msg = "突然你胸臆之间一阵翻腾，你中暑了。\n" ;
		     break;
		case "九":
		case "十":
		case "十一":
		     ill = "ill_shanghan";
		     msg = "陡的你打了个冷战，头昏沉沉的，你得伤寒病了。\n";
		     break;
		case "十二":
		case "一":
		case "二":
		     ill = "ill_dongshang";
		     msg = "你肢体末端一阵僵直，看来你被冻伤了。\n";
		     break;
	}
	if(random(2))
	{
		ill = "ill_fashao";msg = HIG+"你偶感风寒，竟而发起烧来。\n";
	}
	ob = users();
	for(i=0; i<sizeof(ob); i++)
	{
		if( !environment(ob[i]) ) continue;
		if( !environment(ob[i])->query("outdoors") ) continue;
		if( ob[i]->query("age")==14 ) continue;
		con1 = ob[i]->query("qi");
		con2 = ob[i]->query("max_qi");
		(int)con = con1/con2*50;
		con3 = ob[i]->query("neili");
		con2 = ob[i]->query("max_neili");
		if( con2 == 0) con2 = 1;
		(int)con1 = con3/con2*50;
		if(random(con)+random(50)+random(con1)<25)
		{
			ob[i]->apply_condition(ill, 10);
			tell_object(ob[i], msg);
		}
	}
}
string outdoor_room_description()
{
	return "    " + sprintf(
		day_phase[current_day_phase]["desc_msg"],
		month_desc[current_month]) + "。\n";
}

string game_time()
{
	return CHINESE_D->chinese_date(TIME_TICK1);
}

mapping *read_table(string file)
{
	string *line, *field, *format;
	mapping *data;
	int i, rn, fn;

	line = explode(read_file(file), "\n");
	data = ({});
	for(i=0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !pointerp(field) ) {
			field = explode( line[i], ":" );
			continue;
		}
		if( !pointerp(format) ) {
			format = explode( line[i], ":" );
			continue;
		}
		break;
	}

	for( rn = 0, fn = 0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
		sscanf( line[i], format[fn], data[rn][field[fn]] );
		fn = (++fn) % sizeof(field);
		if( !fn ) ++rn;
	}
	return data;
}

int auto_shutdown(int flag)
{
    reclaim_objects();
    if (172800-uptime()<=0 || flag){
        message("vision", RED "要当机了！放心，您的档案已经自动存储了！\n" NOR, users());
        users()->disable_player("备份资料中......");
             call_out("backup",1);
    }
}


int backup()
{
    reset_eval_cost();
    foreach (object userob in children(USER_OB) ){
       if (!userob || !environment(userob)) continue;
           userob->save();
    }
        shutdown(0);
        return 1;

}

mapping *query_day_phase() { return day_phase; }

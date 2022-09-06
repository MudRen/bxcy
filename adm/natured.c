// natured.c
#include <ansi.h>

#define TIME_TICK1 (time()*60)
nosave int current_day_phase,current_month;
void auto_save(object *user, int size, int i);
void event_midnight();
void update_day_phase();
mapping *day_phase;

mapping *read_table(string file);
void init_day_phase();

void create()
{
        string get_month, get_day;
	mixed *local;
	local = localtime(TIME_TICK1);
	get_day = CHINESE_D->chinese_number(local[1]);
	get_month = CHINESE_D->chinese_number(local[4]);
	switch(get_day)
	{
		case "һ��һ��":
		     day_phase = read_table("/adm/etc/nature/spring");
		     break;
}
	switch(get_month)
	{
		//spring weather
		case "��":
		case "��":
		case "��":
		     switch(random(2))
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
		case "��":
		case "��":
		case "��":
		     switch(random(2))
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
		case "��":
		case "ʮ":
		case "ʮһ":
		     switch(random(2))
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
		case "ʮ��":
		case "һ":
		case "��":
		     switch(random(2))
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

        // Get minutes of today.
        local = localtime(TIME_TICK1);
        t = local[2] * 60 + local[1];           // hour * 60 + minutes

        // Find the day phase for now.
        for( i=0; i < sizeof(day_phase); i++)
                if( t >= day_phase[i]["length"] )
                        t -= (int)day_phase[i]["length"];
                else
                        break;

        current_day_phase = (i==0? sizeof(day_phase)-1: i - 1);


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
                   message("channel:chat", HIG"�����⡽"BLK + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "RED":
                   message("channel:chat", HIG"�����⡽"RED + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIR":
                   message("channel:chat", HIG"�����⡽"HIR + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "GRN":
                   message("channel:chat", HIG"�����⡽"GRN + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIG":
                   message("channel:chat", HIG"�����⡽"HIG + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "YEL":
                   message("channel:chat", HIG"�����⡽"YEL + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIY":
                   message("channel:chat", HIG"�����⡽"HIY + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "BLU":
                   message("channel:chat", HIG"�����⡽"BLU + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIB":
                   message("channel:chat", HIG"�����⡽"HIB + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "MAG":
                   message("channel:chat", HIG"�����⡽"MAG + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIM":
                   message("channel:chat", HIG"�����⡽"HIM + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "CYN":
                   message("channel:chat", HIG"�����⡽"CYN + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIC":
                   message("channel:chat", HIG"�����⡽"HIC + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "WHT":
                   message("channel:chat", HIG"�����⡽"WHT + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIW":
                   message("channel:chat", HIG"�����⡽"HIW + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              default:
                   message("channel:chat", HIG"�����⡽"HIG + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
        }
//        message("outdoor:vision", day_phase[current_day_phase]["time_msg"] + "\n", users());
        if( !undefinedp(day_phase[current_day_phase]["event_fun"]) )
            call_other(this_object(), day_phase[current_day_phase]["event_fun"]);

        call_out("update_day_phase", day_phase[current_day_phase]["length"]);
 if(current_day_phase==5||current_day_phase==2) {
	    object *user=users();
	    remove_call_out("auto_save");
	    call_out("auto_save", 10, user, sizeof(user), 0);
	}
}
void event_midnight()
{
        string get_month, get_day;
        mixed *local;
	local = localtime(TIME_TICK1);
	get_day = CHINESE_D->chinese_number(local[1]);
	get_month = CHINESE_D->chinese_number(local[4]);
       switch(get_day)
        {
                case "һ��һ��":
                     day_phase = read_table("/adm/etc/nature/spring");
                     break;
//                case "��������":
//                case "��������":
//                case "����ʮ����":
//                case "���¾���":
//                case "ʮ���°���":
        }
        switch(get_month)
        {
                //spring weather
                case "��":
                case "��":
                case "��":
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
                case "��":
                case "��":
                case "��":
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
                case "��":
                case "ʮ":
                case "ʮһ":
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
                case "ʮ��":
                case "һ":
                case "��":
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
                     break;
                default:
                     day_phase = read_table("/adm/etc/nature/day_phase");
        }
 //  init_day_phase();     
}

// This is called everyday noon by update_day_phase, defined in the
// "event_fun" field in /adm/etc/nature/day_phase

void event_noon()
{
        object *ob;
        int i,con,con1,con2,con3;
        string get_month,ill,msg;
        mixed *local;
	local = localtime(TIME_TICK1);
	get_month = CHINESE_D->chinese_number(local[4]);
        switch(get_month)
        {
                case "��":
                case "��":
                case "��":
                     ill = "ill_kesou";
                     msg = HIG + "��Ȼ��ͷһ���������о��ƺ�Ҫ�����ˡ�\n" + NOR;
                     break;
                case "��":
                case "��":
                case "��":
                     ill = "ill_zhongshu";
                     msg = HIG+"ͻȻ������֮��һ���ڣ��������ˡ�\n" + NOR;
                     break;
                case "��":
                case "ʮ":
                case "ʮһ":
                     ill = "ill_shanghan";
                     msg = HIG+"��������˸���ս��ͷ������ģ�����˺����ˡ�\n"+NOR;
                     break;
                case "ʮ��":
                case "һ":
                case "��":
                     ill = "ill_dongshang";
                     msg = HIG+"��֫��ĩ��һ��ֱ�������㱻�����ˡ�\n"+NOR;
                     break;
        }
        if(random(2))
        {
                ill = "ill_fashao";msg = HIG+"��ż�з纮����������������\n"+NOR;
        }
        ob = users();
        for(i=0; i<sizeof(ob); i++)
        {
                if( !environment(ob[i]) ) continue;
                if( !environment(ob[i])->query("outdoors") ) continue;
                if( ob[i]->query("age")==14 ) continue;
                con1 = ob[i]->query("qi");
                con2 = ob[i]->query("max_qi");
                (int)con = con1/con2*50;//�γɵ�һ�������ж�����
                con3 = ob[i]->query("neili");
                con2 = ob[i]->query("max_neili");
		if( con2 == 0) con2 = 1;
                (int)con1 = con3/con2*50;//�γɵڶ��������ж�����
                if(random(con)+random(50)+random(con1)<25)
                {
                        ob[i]->apply_condition(ill, 10);
                        tell_object(ob[i], msg);
                }
        }
}

string outdoor_room_description()
{
        return "    " + day_phase[current_day_phase]["desc_msg"] + "��\n";
}
string outdoor_room_outcolor()
{
        return day_phase[current_day_phase]["outcolor"];
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
        message("vision", RED "Ҫ�����ˣ����ģ����ĵ����Ѿ��Զ��洢�ˣ�\n" NOR, users());
//        message("system", HIW "\n �Զ�������������У����Ժ�....\n" NOR, users());
        users()->disable_player("����������......");
             call_out("backup",1);
    }
}
int backup()
{
   // int i, j, ppl_cnt, count;
   // mixed *local;
  //  string *dir, *ppls, name,data_dir;
    //mixed info;

    reset_eval_cost();
  foreach (object userob in children(USER_OB) ){
       if (!userob || !environment(userob)) continue;
           userob->save();
    }
/*
    local=localtime(TIME_TICK);
    data_dir="/backdata/back"+local[6]+"/";
    log_file( "AUTOSTART", sprintf("%s autostart!write to %s\n",ctime(time()),data_dir ) );
    count = 0;
    ppl_cnt = 0;
    dir = get_dir(DATA_DIR + "login/");
    for(i=0; i<sizeof(dir); i++) {
        reset_eval_cost();
        ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
        ppl_cnt += sizeof(ppls);
        for(j=0; j<sizeof(ppls); j++) {
            if( sscanf(ppls[j], "%s.o", name)==1 )
                if( (string)SECURITY_D->get_status(name)!="(player)" )
                    continue;
            info = stat(DATA_DIR + "login/" + dir[i] + "/" + ppls[j]);
            if( (time()-(int)info[1])<= 172800 ) {
                assure_file(data_dir + "login/" + dir[i] + "/" + ppls[j]);
                assure_file(data_dir + "user/" + dir[i] + "/" + ppls[j]);
                cp(DATA_DIR + "login/" + dir[i] + "/" + ppls[j],data_dir + "login/" + dir[i] + "/" + ppls[j]);
                cp(DATA_DIR + "user/" + dir[i] + "/" + ppls[j],data_dir + "user/" + dir[i] + "/" + ppls[j]);
                count ++;
            }
        }
    }
*/
    shutdown(0);
    return 1;
}
void auto_save(object *user, int size, int i)
{
    int j;
    
    for(j=i;j<i+5;j++) {
	if(j>=size) return;
	if(!user[j]) continue;
	if(user[j]->save())
	    message("vision", RED"�����Զ��洢��ϡ�\n"NOR,user[j]);
    }
    
    call_out("auto_save", 10, user, size, i+5);
   }
mapping *query_day_phase() { return day_phase; }


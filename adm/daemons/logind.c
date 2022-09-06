// logind.c
#include <ansi.h>
#include <command.h>
#include <login.h>

inherit F_DBASE;
int wiz_lock_level = WIZ_LOCK_LEVEL;
int mad_lock = 0;
string Rname;
string *banned_name = ({
                         "你", "你的", "我","我的","自己","屁", "他", "他的","她", "她的","它", "它的",
                         "鬼王","风云","流氓","爸","妈","祖先","祖宗","爷","奶","毛泽东","邓小平","江泽民",
                         "【","】","马克思","恩格斯","列宁","抄","手淫","老百姓",
                       });
string *start_room = ({
        "/d/xingxiu/beijiang",
        "/d/quanzhou/tieqiang",
        "/d/city/wumiao",
        "/d/city2/kedian",
});
string *banned_id =   ({"admin","arch","wizard","apprentice","immortal","player","fuck","snow",
	"yudiao","hero","fyue","tuzi"});
protected void get_id(string arg, object ob,int ip_cnt);
protected void confirm_id(string yn, object ob,int ip_cnt);
object make_body(object ob);
protected void init_new_player(object user);
private void check_ok(object ob);
void get_resp(string arg, object ob);
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object find_body(string name);
int check_legal_id(string arg);
int check_legal_name(string arg);
string random_name();
void random_gift(mapping my, int select)
{
	int i = 10, j;
	int tmpstr, tmpint, tmpcon, tmpdex;
	tmpstr = tmpint = tmpcon = tmpdex = 10;
	switch (select) {
		case 1: tmpstr = i = my["str"]; break;
		case 2: tmpint = i = my["int"]; break;
		case 3: tmpcon = i = my["con"]; break;
		case 4: tmpdex = i = my["dex"];
	}
	i = 50 - i;
	while (i--) {
		j = random(4);
		if (j == select - 1) {
			i++;
			continue;
		}
		switch (j) {
		case 0: tmpstr++; break;
		case 1: tmpint++; break;
		case 2: tmpcon++; break;
		case 3: tmpdex++; break;
		}
	}
	if (tmpstr <= 30) my["str"] = tmpstr; else my["str"] = 30;
	if (tmpint <= 30) my["int"] = tmpint; else my["int"] = 30;
	if (tmpcon <= 30) my["con"] = tmpcon; else my["con"] = 30;
	if (tmpdex <= 30) my["dex"] = tmpdex; else my["dex"] = 30;

	my["kar"] = 10 + random(21);
	my["per"] = 10 + random(21);
}
void create() 
{
    seteuid(getuid());
    set("channel_id", "连线精灵");
}
protected void logfile(string str)
{
    mixed *local =localtime(time());
    string file=sprintf("login/login%d%d.log",local[5],local[4]+1);
    log_file(file,str);
}
void logon(object ob) 
{
    object *usr;
        int i, wiz_cnt, ppl_cnt,ip_cnt,ban_cnt,login_cnt,i_user,online_num;
    string str,user_num;
    if (uptime() < 30)
	{
	        write(RED"游戏服务器正在启动过程中，请稍等几分钟后再连线。\n"NOR);
	        destruct(ob);
	        return;
	}
     str=query_ip_number(ob);
   if (BAN_D->is_banned(str) == 1) 
            {
                write(HIR"你的地址在本 MUD 不受欢迎，请写信至jhfy@email.com.cn申述。\n"NOR);
                destruct(ob);
                return;
            }
    if( mad_lock == 1 ) {
        write("现在时空已经封闭了，不能进入！！ \n");
                destruct(ob);
                return;
        }
 
      	write("\n\n\n");
cat(WELCOME);
write(NOR"欢迎光临"+" "HIM "碧血残阳"NOR +  HIW" 之 "NOR +HIG"「豪侠晚歌」\n\n"NOR);
write("\n\n");	
write(MAG+NOR CYN"豪侠晚歌"HIW"域名"NOR" : ""akai.isme.net"NOR MAG"  \n"NOR);	
write(MAG+NOR CYN"豪侠晚歌"HIW"ZMUD端口"NOR" : ""6666"NOR MAG"  \n"NOR); 	
write(MAG+NOR CYN"豪侠晚歌"HIW"TOMUD端口"NOR" : ""8888"NOR MAG"\n"NOR);
write("\n\n");	

        usr = users();
        wiz_cnt = 0;
        ppl_cnt = 0;
        login_cnt = 0;
        ban_cnt = 0;
        ip_cnt=0;
         
        for(i=0; i<sizeof(usr); i++) {
        if (str==query_ip_number(usr[i])) ip_cnt++;
        if( str==query_ip_number(usr[i]) && !environment(usr[i]) ) ban_cnt++;
        if( !environment(usr[i]) ) login_cnt++;
        else if( wizardp(usr[i])){ if (!usr[i]->query("env/invisibility") ||
        	usr[i]->query("id")!="afei") wiz_cnt++;}
        else ppl_cnt++;
}
        user_num=read_file(__DIR__"users",1);
	i_user=atoi(user_num);
	i_user=i_user+1; 
	user_num=sprintf("%d", i_user); 
	write_file(__DIR__"users",user_num,1);
	user_num=read_file(__DIR__"iduser",1);
	i_user=atoi(user_num); 
if (ip_cnt-1 > 0){
        printf(	"你现在从%s连线进入。",CYN+str+NOR);
        printf("在这个地址上，还有"+YEL+chinese_number(ip_cnt-1)+NOR+"位其他玩家。\n");}
     else printf("你现在从%s连线进入。\n",CYN+str+NOR);
	printf("目前共有"+ HIY"%s"NOR+ "位神仙、"+HIW"%s"NOR+ "位江湖人士在江湖中，以及"+HIB"%s"NOR+ "位朋友正在步入江湖的途中。\n",
		chinese_number(wiz_cnt), chinese_number(ppl_cnt), chinese_number(login_cnt) );
if(ppl_cnt > online_num) {
   user_num = sprintf("%d",ppl_cnt);
   write_file(__DIR__"maxonline",user_num,1);
   }
  if (ban_cnt>8){
        write("这个IP上同时正在连线的玩家太多了，请稍候再尝试！！ \n");
             destruct(ob);
             return;
    }
    if (ob->query_temp("tomud"))
    {
    write(CLEAN0);
    write(CLEAN1);
    write(CLEAN2);
    write(TMI("version"));
    input_to("get_version", ob,ip_cnt);
  }

    write(NOR YEL"请输入您的英文名字："NOR);

    input_to( (: get_id :), ob,ip_cnt );
}
protected void get_version(string arg, object ob,int ip_cnt)
{
	if (! arg || arg[0..3] != "2060")
	{
		write(HIY "请进入残阳主页下载TOMUD客户端\n" NOR);
		write(HIY "或使用Zmud客户端选择5555端口重新连接。\n\n" NOR);
		destruct(ob);
		return;
	}
	 input_to( (: get_id :), ob,ip_cnt );
}
protected void get_id(string arg, object ob,int ip_cnt)
{
    object ppl;
    object *usr;
    int i, wiz_cnt,usr_cnt;
    arg = lower_case(arg);
    if( !check_legal_id(arg)) 
    {
        write(YEL"请输入您的英文名字："NOR);
        input_to("get_id", ob,ip_cnt);
        return;
    }
    usr = users();
    wiz_cnt = 0;
    for(i=0; i<sizeof(usr); i++) 
          {
        if( wizardp(usr[i]) ) wiz_cnt++;
          }
    if( (string)SECURITY_D->get_status(arg)=="(player)"
         && (sizeof(users()) - wiz_cnt) >= 350) 
   {
        ppl = find_body(arg);
        // Only allow reconnect an interactive player when MAX_USERS exceeded.
        if( !ppl || !interactive(ppl) ) 
        {
            write("对不起，" + MUD_NAME + "的使用者已经太多了，请待会再来。\n");
            destruct(ob);
            return;
        }
    }
    if( wiz_level(arg) < wiz_lock_level ) 
    {
        write("对不起，" + MUD_NAME + "目前限制巫师等级 " + WIZ_LOCK_LEVEL
            + " 以上的人才能连线。\n");
        destruct(ob);
        return;
    }
    
    if( (string)ob->set("id", arg) != arg ) 
    {
        write("Failed setting user name.\n");
        destruct(ob);
        return;
    }
    for (i=0;i<sizeof(banned_id);i++)
        if ( strsrch(arg, banned_id[i])!=-1)
        {
                write("对不起，这个帐户正在有另一个使用者在登录，请重新输入你的英文名。\n");
                write(YEL"请输入您的英文名字："NOR);
        input_to("get_id", ob,ip_cnt);
                return;
        }
        if (BAN_D->is_bandid(arg) == 1)
        {
                write("\n对不起，这个帐户正在有另一个使用者在登录，请重新输入你的英文名。\n");
                write(YEL"请输入您的英文名字："NOR);
        input_to("get_id", ob,ip_cnt);
                return;
        }
    if( arg=="guest" ) 
    {
                write("对不起，现在限制guest帐户登录，请重新输入你的英文名。\n");
                write("您的"+HIW"英文"NOR+"名字：");
        input_to("get_id", ob,ip_cnt);
        return;
    }
    if (wiz_level(arg)<2)
    {
        if (!BAN_D->is_welcome(arg))
        {
            if (!BAN_D->is_netclub(query_ip_number(ob)))
            if (ip_cnt>8)
            {
                write(HIR"这个IP上来的玩家太多了，不能进入！！ \n"NOR);
                     destruct(ob);
                     return;
            }
           
        }
    }
    if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 ) 
    {
        if( ob->restore() ) 
        {
            write(YEL"请输入您的密码："NOR);
            input_to("get_passwd", 1, ob);
            return;
        }
        write("您的人物储存挡出了一些问题，请利用 guest 人物通知巫师处理。\n");
        destruct(ob);
        return;
    }
    usr_cnt=0;
    for(i=0; i<sizeof(usr); i++) 
     {
        if (usr[i]->query("id")==arg)
         {
            usr_cnt++;
            if (usr_cnt>1)
                {
                write("对不起，这个帐户正在有另一个使用者在登录，请重新输入你的英文名。\n");
                write("请输入您的您的英文名字：");
 
                input_to("get_id", ob,ip_cnt);
                return;
                }
         }
    }

    write("使用 "HIW + (string)ob->query("id") + NOR" 这个名字将会创造一个新的人物，您确定吗("HIR"y"NOR"/"HIY"n"NOR")？");
    input_to("confirm_id", ob,ip_cnt);
}
protected void get_passwd(string pass, object ob)
{
    string my_pass,my_wizpwd;
    int err_num;
    write("\n");
    my_pass = ob->query("password");
		my_wizpwd = ob->query("wizpwd");
		if( crypt(pass, my_wizpwd) == my_wizpwd){
			ob->set_temp("reset_password", 1);
			write("您输入的是管理密码，请重新设定您的普通密码。\n");
			input_to("new_password", 1, ob);
			return;
		}
    if( crypt(pass, my_pass) != my_pass ) {
    
        err_num=ob->query_temp("error_login");
                err_num++;
                ob->set_temp("error_login",err_num);
                if ( err_num < 3 ){
               write("您还有"HIR+chinese_number(3-err_num)+NOR"次机会，请输入正确密码：");
                  input_to("get_passwd", 1, ob);
                }else {
                        write("\n你已经没有机会了，请想好后再连线！\n");
                        destruct(ob);
                       }
        return;
    }
		if(!ob->query("wizpwd")){
			write("您还未设定您的管理密码，请设定您的管理密码：");
			input_to("reset_wizpwd", 1, ob);
			return;
		}
		check_ok(ob);
}

protected void reset_wizpwd(string pass, object ob)
{
		string ad_pass;
    write("\n");
    if( strlen(pass)<5 ) {
        write("密码的长度至少要五个字符，请重设您的密码：");
        input_to("reset_wizpwd", 1, ob);
        return;
    }
    if (stringp(ad_pass = ob->query("password")) &&
    	crypt(pass, ad_pass) == ad_pass)
    {
    	write(HIR "请注意，为了安全起见，系统要求你的管理密码和普通密码不能相同。\n\n" NOR);
    	write("请重新设置您的普通密码：");
    	input_to("reset_wizpwd", 1, ob);
    	return;
    }
    ob->set_temp("wizpwd", crypt(pass,0) );
    write("请再输入一次您的密码，以确认您没记错：");
    input_to("confirm_reset_wizpwd", 1, ob);
}
protected void confirm_reset_wizpwd(string pass, object ob)
{
 	
	string old_pass;
	write("\n");
	old_pass = ob->query_temp("wizpwd");
	if( crypt(pass, old_pass)!=old_pass )
	{
		write("您两次输入的密码并不一样，请重新设定一次密码：");
		input_to("reset_wizpwd", 1, ob);
		return;
	}
	ob->set("wizpwd", old_pass);
	check_ok(ob);
}

private void check_ok(object ob)
{
	object user;
 if (!BAN_D->vaild_allow_address(ob)){
        destruct(ob);
        return;
    }
    user = find_body(ob->query("id"));
    if (user) {
        if( user->query_temp("netdead") ) {
            reconnect(ob, user);
            return;
        }
        write("您要将另一个连线中的相同人物赶出去，取而代之吗？("HIR"y"NOR"/"HIY"n"NOR")");
        input_to("confirm_relogin", ob, user);
        return;
    }
    if( objectp(user = make_body(ob)) )
	{
		if( user->restore() )
		{
			
			if(time()-(int)user->query("kickout_time") < 1800)
			{
			write(HIR"\n由于你违反规则被踢出游戏，作为惩罚请三十分钟后再联线。\n\n"NOR);
			destruct(user);
			destruct(ob);
			return;
		}
		      
if(time()-(int)ob->query("last_on") < 5)
			{
                        write(HIR"\n你刚退出游戏，为了减轻系统负担请过一会再连入，谢谢合作。^0^\n\n");
			destruct(user);
			destruct(ob);
			return;
		}
		log_file( "login/login",sprintf("%-20s从%20s  登    录(%s)。\n", user->query("name")+"("+user->query("id")+")", query_ip_number(ob), ctime(time()) ) );
			enter_world(ob, user);
			return;
		}
		else
		{
			destruct(user);
		}
	}
    write("请您重新创造这个人物。\n");
    confirm_id("y", ob,1);
}
protected void confirm_relogin(string yn, object ob, object user)
{
    object old_link;
    if (!ob || !user) return ;
    if( yn=="" ) {
        write("您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)");
        input_to("confirm_relogin", ob, user);
        return;
    }   
    if( yn[0]!='y' && yn[0]!='Y' ) {
        if (wiz_level(user) > 3 ){
            if( objectp(user = make_body(ob)) ) {
                if( user->restore() ) {                 
                    enter_world(ob, user);
                    return;
                } else destruct(user);
            }
        }

        write(GRN"好吧，欢迎下次再来。\n"NOR);
        destruct(ob);
        return;
    } else {
        tell_object(user, "有人从别处( "HIW + query_ip_number(ob)
            + NOR" )连线取代你所控制的人物。\n");
        log_file("login/replace", sprintf("%-20s从%20s  重新联线(%s)。\n", user->query("name")+"("+user->query("id")+")", query_ip_number(ob), ctime(time()) ) );    
    }
    // Kick out tho old player.
    old_link = user->query_temp("link_ob");
    if( old_link ) {
        exec(old_link, user);
        destruct(old_link);
    }
    reconnect(ob, user);    
}
protected void confirm_id(string yn, object ob,int ip_cnt)
{
    if( yn=="" ) {
        write("使用这个名字将会创造一个新的人物，请问您确定吗("HIR"y"NOR"/"HIY"n"NOR")？");
        input_to("confirm_id", ob,ip_cnt);
        return;
    }   
    if( yn[0]!='y' && yn[0]!='Y' ) {
        write("好吧，那么请重新输入您的英文名字：");
        input_to("get_id", ob,ip_cnt);
        return;
    }
    write("\n\n");
	write(YEL @TEXT
※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※
※                                                                    ※
※  好! 现在请您给自己取一个有气质，有个性的名字，好的名字不仅显示了  ※
※  您自身的素养，也会给其他玩家一个好的印象, 甚至会因此而交到更多的  ※
※  朋友，而对您的一生产生极大的影响。所以请务必慎重择名。由于这个名  ※
※  字代表您的人物，以后将很难更改。                                  ※ 
※                                                                    ※
※  另：请不要选择金庸小说中已有人物姓名（不雅观的姓名将被删除）。    ※
※　　　如果您有困难输入中文名字，请直接敲回车键［ＲＥＴＵＲＮ］。　　※　
※                                                                    ※
※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※
TEXT NOR
	);
    write("\n请给自己取一个中文名字：");
    input_to("get_name", ob);
}

string display_attr(int gift)
{
	if (gift > 24) return HIG + gift + NOR;
	if (gift < 16) return CYN + gift + NOR;
	return "" + gift;
}
void get_resp(string arg, object ob)
{
        if( arg=="" ) {
                write("您是否满意这个中文名字("HIR"y"NOR"/"YEL"n"NOR")？");
                input_to("get_resp", ob);
                return;
        }

        if( arg[0]=='y' || arg[0]=='Y' )
	{
        printf("%O\n", ob);
        ob->set("name", Rname);
        write("请设定您的管理密码：");
        input_to("new_wizpwd", 1, ob);
	return;
	}
        else 
	if( arg[0]=='n' || arg[0]=='N')
	{
	Rname = random_name();
        write("您是否满意这个中文名字("HIR"y"NOR"/"HIY"n"NOR")？");
        printf( HIW" ──"NOR YEL"〖 "HIR"%s"NOR YEL" 〗"NOR"："NOR, Rname);
        input_to("get_resp", ob);
	return;
	}
        else {
                write("对不起，您只能选择满意("HIR"y"NOR")不满意("HIY"n"NOR")： ");
                input_to("get_resp", ob);
                return;
        }


}
protected void get_name(string arg, object ob)
{
    if( arg =="")
        {
	Rname = random_name();
        write("看来您要个随机产生的中文名字．．\n");
         write("请问您是否满意这个中文名字("HIR"y"NOR"/"HIY"n"NOR")？");
      printf( HIW" ──"NOR CYN"〖 "HIY"%s"NOR CYN" 〗"NOR"："NOR, Rname);
        input_to("get_resp", ob);
	}
	else {
        if( !check_legal_name(arg) ) {
                write("请再次输入您的中文名字：");
                input_to("get_name", ob);
                return;
        }

        printf("%O\n", ob);
        ob->set("name", arg);
        write("请设定您的管理密码：");
        input_to("new_wizpwd", 1, ob);
		}
}
protected void new_wizpwd(string pass, object ob)
{
    write("\n");
    if( strlen(pass)<5 ) {
        write("密码的长度至少要五个字符，请重设您的密码：");
        input_to("new_wizpwd", 1, ob);
        return;
    }
    ob->set_temp("wizpwd", crypt(pass,0) );
    write("请再输入一次您的密码，以确认您没记错：");
    input_to("confirm_wizpwd", 1, ob);
}
protected void confirm_wizpwd(string pass, object ob)
{
 	
	string old_pass;
	write("\n");
	old_pass = ob->query_temp("wizpwd");
	if( crypt(pass, old_pass)!=old_pass )
	{
		write("您两次输入的密码并不一样，请重新设定一次密码：");
		input_to("new_wizpwd", 1, ob);
		return;
	}
	ob->set("wizpwd", crypt(pass,0) );
	write("请输入你的普通密码：");
	input_to("new_password", 1, ob);
}
	
protected void new_password(string pass, object ob)
{
		string ad_pass;
    write("\n");
    if( strlen(pass)<5 ) {
        write("密码的长度至少要五个字符，请重设您的密码：");
        input_to("new_password", 1, ob);
        return;
    }
    if (stringp(ad_pass = ob->query("wizpwd")) &&
    	crypt(pass, ad_pass) == ad_pass)
    {
    	write(HIR "请注意，为了安全起见，系统要求你的管理密码和普通密码不能相同。\n\n" NOR);
    	write("请重新设置您的普通密码：");
    	input_to("new_password", 1, ob);
    	return;
    }
    ob->set_temp("password", crypt(pass,0) );
    write("请再输入一次您的密码，以确认您没记错：");
    input_to("confirm_password", 1, ob);
}
protected void confirm_password(string pass, object ob)
{
 	
	string old_pass;
	write("\n");
	old_pass = ob->query_temp("password");
	if( crypt(pass, old_pass)!=old_pass )
	{
		write("您两次输入的密码并不一样，请重新设定一次密码：");
		input_to("new_password", 1, ob);
		return;
	}
	ob->set("password", crypt(pass,0) );
	if (ob->query_temp("reset_password"))
		{
			ob->save();
			check_ok(ob);
			return;
		}
write("\n");
	write(NOR MAG @TEXT
※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※
※                                                                    ※
※  一个人物的天赋对于他或她所修习的武艺息息相关。「豪侠晚歌」中的  ※
※  人物大多具有以下六项天赋,其中福缘与容貌是隐藏属性：               ※
※                                                                    ※
※	①　膂力：影响攻击能力及负荷量的大小。                        		※
※	②　悟性：影响学习武功秘籍的速度及理解师傅的能力。            		※
※	③　根骨：影响体力恢复的速度及升级后所增加的体力。            		※
※	④　身法：影响防御及躲避的能力。                              		※
※	⑤　福缘：影响解迷、奇遇，拜师等运气方面。                    		※
※　⑥  容貌：影响解密，拜师的条件以及玩家和NPC对你的印象。       		※
※                                                                    ※
※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※
TEXT NOR);
write("\n您可以输入 "HIR"(1-4)"+NOR" 指定其中的一项值，或者输入 "+HIR"0"NOR" 由系统随机选择。\n");
write("您的选择是 ("CYN"0-4"NOR")：");
input_to("select_gift", ob);
}
void get_gift(string yn, object ob, mapping my, int select)
{
	if (yn[0] != 'y' && yn[0] != 'Y') {
		random_gift(my, select);
		printf("\n膂力[%s]，悟性[%s]，根骨[%s]，身法[%s]\n",
			display_attr(my["str"]),
			display_attr(my["int"]),
			display_attr(my["con"]),
			display_attr(my["dex"]));
		write("您同意这一组天赋吗？Y/N");
		input_to("get_gift", ob, my, select);
		return;
	}
	write("\n您的电子邮件地址：");
	input_to("get_email", ob, my);
}
void select_gift(string yn, object ob)
{
	int i;
	mapping my = ([]);
	if (!sscanf(yn, "%d", i) || i < 0 || i > 4) {
		write("\n输入错误，请重新选择：");
		input_to("select_gift", ob);
		return;
	}
	if (i) {
		write("\n请输入您想要的数值(10-30)：");
		input_to("set_gift", ob, my, i);
	} else get_gift(" ", ob, my, i);
}

void set_gift(string yn, object ob, mapping my, int select)
{
	int i;

	if (!sscanf(yn, "%d", i) || i < 10 || i > 30) {
		write("\n数值错误，请重新输入：");
		input_to("set_gift", ob, my, select);
		return;
	}
	switch (select) {
		case 1: my["str"] = i; break;
		case 2: my["int"] = i; break;
		case 3: my["con"] = i; break;
		case 4: my["dex"] = i;
	}
	get_gift(" ", ob, my, select);
}
protected void get_email(string email, object ob, mapping my)
{
        object user;
	string id,address;

	write("\n");
	if (email == "" || strsrch(email, "@") == -1||
		sscanf(email,"%s@%s",id,address)!=2||strsrch(address,".")==-1)
	{
		write("电子邮件地址需要是 id@xxx.xxx 的格式。\n");
		write("您的电子邮件地址：");
		input_to("get_email", ob, my);
		return;
	}
	ob->set("email", email);
	ob->set("registered", 1);

	// If you want do race stuff, ask player to choose one here, then you can
	// set the user's body after the question is answered. The following are
	// options for player's body, so we clone a body here.
	ob->set("body", USER_OB);
	if( !objectp(user = make_body(ob)) )
		return;
	user->set("str", my["str"]);
	user->set("dex", my["dex"]);
	user->set("con", my["con"]);
	user->set("int", my["int"]);
	user->set("kar", my["kar"]);
	user->set("per", my["per"]);
	ob->set("registered", 1);
	user->set("registered", 1);

	write("您要扮演男性("HIG"m"NOR")的角色或女性("HIM"f"NOR")的角色？");
	input_to("get_gender", ob, user);
}
protected void get_gender(string gender, object ob, object user)
{
    int id_temp; string id_num;
    write("\n");
    if( gender=="" ) {
        write("您要扮演男性("HIG"m"NOR")的角色或女性("HIM"f"NOR")的角色？");
        input_to("get_gender", ob, user);
        return;
    }
    if( gender[0]=='m' || gender[0]=='M' )
        user->set("gender", "男性");
    else if( gender[0]=='f' || gender[0]=='F' )
        user->set("gender", "女性" );
    else {
       write("对不起，您只能选择男性("HIG"m"NOR")或女性("HIM"f"NOR")的角色：");
        input_to("get_gender", ob, user);
        return;
    }
    log_file( "login/newid.log", sprintf("%-12s was created from %-20s (%s)\n", user->query("id"),
        query_ip_number(ob), ctime(time()) ) );
    CHANNEL_D->do_channel( this_object(), "sys","又有一个新玩家："+user->query("name")+"["+user->query("id")+"]。"NOR);
    init_new_player(user);
    enter_world(ob, user);
    id_num=read_file(__DIR__"iduser",1);
    id_temp=atoi(id_num); id_temp=id_temp+1;
    id_num=sprintf("%d",id_temp);
    write_file(__DIR__"iduser",id_num,1);
    write("\n");

}	
object make_body(object ob)
{
    string err;
    object user;
    if (stringp(ob->query("body")))
    user = new(ob->query("body"));
    else return 0;
    if(!user) {
        write("现在可能有人正在修改使用者物件的程式，无法进行复制。\n");
        write(err+"\n");
        return 0;
    }
    seteuid(ob->query("id"));
    export_uid(user);
    export_uid(ob);
    seteuid(getuid());
    user->set("id", ob->query("id"));
    user->set_name( ob->query("name"), ({ ob->query("id")}) );
    return user;
}
protected void init_new_player(object user)
{
    user->set("title", "普通百姓");
    user->set("birthday", time() );
    user->set("potential", 100);
    user->set("channels", ({ "es","chat", "rumor","tell","new","jh","auction"}) );
    if(user->query("gender") == "女性")
	{
	
		user->set("combat_exp", 50);
		user->set("money", 2000);
	}

}
protected void have_mail()
{
     write( BOLD + "\n杜宽(Post officer)告诉你：有您的信！请到驿站来一趟...\n\n" + NOR);
}
varargs void enter_world(object ob, object user, int silent)
{
    object cloth;
    string startroom,id,str;
    object login_ob,*users;
    int i=random(4);
    user->set_temp("link_ob", ob);
    ob->set_temp("body_ob", user);
    user->set("registered", ob->query("registered"));
    if (ob->query_temp("tomud"))
    	user->set_temp("tomud", 1);
    exec(user, ob);
    user->setup();
    if (ob->query("age") == 14) {
            user->set("food", user->max_food_capacity());
            user->set("water", user->max_water_capacity());
    }

    user->save();
    ob->save();

    if (!user->over_encumbranced())
    {
    	if (user->query("age")<18){
       if (user->query("gender")=="女性") cloth = new("/clone/misc/pink_cloth");
       else cloth = new("/clone/cloth/cloth");
       cloth->move(user);
       cloth->wear();
        }
    }
    

    if( !silent ) {
                cat(MOTD);
                login_ob=new(LOGIN_OB);
	        login_ob->set("id",user->query("id"));
	        login_ob->restore();
	        write("★ 您目前权限：" + wizhood(user) + "\n");
	        write("★ 您上次光临豪侠晚歌是从："+login_ob->query("last_from") +"\n");
//	        write("★ 您上次连线的时间是："+ctime(login_ob->query("last_on")) + "\n\n");
}
        id=user->query("id");
        str=DATA_DIR + "mail/" + id[0..0] + "/" + id+".o";
                if(file_size(str) && user->query("new_mail")<file_size(str) ) {
        call_out("have_mail",3);
        }
        if( user->is_ghost() )
            startroom = DEATH_ROOM;
        else {
        	if( !stringp(startroom = user->query("startroom")) )
                   startroom = start_room[i];
                if ( startroom == DEATH_ROOM )
                   startroom = start_room[i];
             }
       


        if (file_size(startroom+".c")>0 && !catch(load_object(startroom)))
            user->move(startroom);
        else {
            user->move(start_room[i]);
            startroom = start_room[i];
            user->set("startroom", start_room[i]);
        }
        if(user->query("id")!="afei")
        tell_room(startroom, user->query("name") + "连线进入这个世界。\n",
            ({user}));

    
    write(HIW"你连线进入这个世界，开始了自己的"+HIG"江湖"+HIW"生涯\n"NOR);
    if(ob->query_temp("no_allow_ip"))   
       write("\n\n警告：你未设定自己的登录地址范围。请用"HIR" allowip "NOR"指令设置。\n\n");
    if(file_size("/log/login/notice")>0){
       write(HIG"     ～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～\n"NOR);
       write(read_file("/log/login/notice"));
        write(HIG"     ～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～\n\n"NOR);
        }
    if(user->query("gender") == "男性"&&user->query("age")<=25){
		   	switch(random(2))
        { case 0 : str = "少年侠士";break;
          case 1 : str = RANK_D->query_respect(user);break;
         }
         }
        else if(user->query("gender") == "女性"&&user->query("age")<=25){
                       switch(random(2))
         {case 0 : str = "妙龄少女";break;
          case 1 : str = RANK_D->query_respect(user);break;
        }
        }
        else str = RANK_D->query_respect(user);
        
if(!(wizardp(user)&&user->query("env/no_login_msg")))
message("shout", TMI("ptext "+HIR"〖有间客栈〗"NOR+": "+CYN"听说又来了一位叫做"+HIW+user->name()+NOR CYN"的"+str+"\n"NOR),users());
  if(user->query("id")!="afei")
	CHANNEL_D->do_channel( this_object(), "sys", sprintf("%s(%s)由%s连线进入。", user->name(),user->query("id"), query_ip_name(user)) );
    UPDATE_D->check_user(user);
    STATUS_D->compare_status(user);
    if(!wizardp(user)||!user->query("env/invisibility")){
    users = filter_array(users(), (: $1->query_temp("tomud") :));
    message("system",ADD2(user),users);
  }
		user->force_me("wear all");
		if (user->query_temp("tomud")){
if(!user->query("env/no_login_msg"))
		write(ALERT("经典文字MUD游戏『碧血残阳』，本游戏为免费游戏！$$" +
    "请到http://akai.isme.net/浏览本游戏主页$$"+
    "如果有任何疑问，请到本游戏服务的提供者WIZ，或者修改本LIB的AKAI。$$"));
		}
    user->set_temp("temp_exp",user->query("combat_exp"));
    user->set_temp("temp_time",time());
}
varargs void reconnect(object ob, object user, int silent)
{
    user->set_temp("link_ob", ob);
    ob->set_temp("body_ob", user);
    if (ob->query_temp("tomud"))
    	user->set_temp("tomud", 1);
    else
    	user->delete_temp("tomud");
    exec(user, ob);
    user->reconnect();
    if( !silent ) {
        tell_room(environment(user), user->query("name") + YEL"重新连线回到这个世界。\n"NOR,
        ({user}));
    }
     if(user->query("id")!="afei")
    CHANNEL_D->do_channel( this_object(), "sys",
        sprintf("%s(%s)由(%s)重新连线进入。", user->query("name"),user->query("id"), query_ip_number(user)) );
    UPDATE_D->check_user(user);
    if (user->query_temp("tomud"))
    {
    	user->force_me("look");
    	user->force_me("inventory");
    }

}
int check_legal_id(string id)
{
    int i;
    i = strlen(id);
    
     if( (strlen(id) < 3) || (strlen(id) > 14 ) ) {
        write("对不起，你的"+HIW"英文"NOR+"名字必须是 3 到 10 个英文字母。\n");
        return 0;
    }
    while(i--)
        if( id[i]<'a' || id[i]>'z' ) {
            write("对不起，你的"+HIW"英文"NOR+"名字只能用英文字母。\n");
            return 0;
        }
    return 1;
}
string random_name()
{
	string *lname = ({
"赵","钱","孙","李","周","吴","郑","王","冯","陈","褚","卫","蒋","沈","韩","杨","朱","秦","尤","许","何","吕","施","张",
"孔","曹","严","华","金","魏","陶","姜","戚","谢","邹","喻","柏","水","窦","章","云","苏","潘","葛","奚","范","彭","郎",
"鲁","韦","昌","马","苗","凤","花","方","傻","任","袁","柳","邓","鲍","史","唐","费","廉","岑","薛","雷","贺","倪","汤",
"藤","殷","罗","华","郝","邬","安","常","乐","呆","时","付","皮","卞","齐","康","伍","余","元","卜","顾","盈","平","黄",
"和","穆","肖","尹","姚","邵","湛","汪","祁","毛","禹","狄","米","贝","明","藏","计","伏","成","戴","谈","宋","茅","庞",
"熊","纪","舒","屈","项","祝","董","梁","樊","胡","凌","霍","虞","万","支","柯","昝","管","卢","英","万","候","司马",
"上官","欧阳","夏候","诸葛","闻人","东方","赫连","皇甫","尉迟","公羊","澹台","公治",
"宗政","濮阳","淳于","单于","太叔","申屠","公孙","仲孙","辕轩","令狐","钟离","宇文",
"长孙","幕容","司徒","师空","颛孔","端木","巫马","公西","漆雕","乐正","壤驷","公良",
"拓趾","夹谷","宰父","谷梁","楚晋","阎法","汝鄢","涂钦","段千","百里","东郭","南郭",
"呼延","归海","羊舌","微生","岳","帅","缑","亢","况","后","有","琴","梁丘","左丘","东门","西门",
			});
			 return (lname[random(200)] + chinese_number(random(20)));
}
int check_legal_name(string name)
{
    int i;
    i = strlen(name);
    if( (strlen(name) < 2) || (strlen(name) > 10 ) ) {
        write("对不起，你的中文名字必须是 1 到 5 个中文字。\n");
        return 0;
    }
    while(i--) {
        if( name[i]<=' ' ) {
            write("对不起，你的中文名字不能用控制字元。\n");
            return 0;
        }
        if( i%2==0 && !is_chinese(name[i..<0]) ) {
            write("对不起，请您用「中文」取名字。\n");
            return 0;
        }
    }
        if( member_array(name, banned_name)!=-1 ) {
                write("对不起，这种名字会造成其他人的困扰。\n");
                return 0;
        }
    for (i=0;i<sizeof(banned_name);i++)
        if ( strsrch(name, banned_name[i])!=-1){
                    write("对不起，这种名字会造成其他人的困扰。\n");
                    return 0;
        }
    return 1;
}
object find_body(string name)
{
    object ob, *body;
    if( objectp(ob = find_player(name)) )
        return ob;
    body = children(USER_OB);
    for(int i=0; i<sizeof(body); i++)
        if( clonep(body[i])
        &&  getuid(body[i]) == name ) {
        	if(!userp(body[i]))
        		destruct(body[i]);
        		else return body[i];
        		}
    return 0;
}
int set_wizlock(int level)
{
    if( wiz_level(this_player(1)) <= level )
        return 0;
    if( geteuid(previous_object()) != ROOT_UID )
        return 0;
    wiz_lock_level = level;
    return 1;
}
int set_madlock(int setmark)
{
    if( wiz_level(this_player(1)) < wiz_level("(arch)") )
        return 0;
    if( setmark == 1 ) mad_lock = 1;
    else mad_lock = 0;
    return 1;
}
int get_madlock()
{
    return mad_lock;
}

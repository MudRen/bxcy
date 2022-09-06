// logind.c
#include <ansi.h>
#include <command.h>
#include <login.h>

inherit F_DBASE;
int wiz_lock_level = WIZ_LOCK_LEVEL;
int mad_lock = 0;
string Rname;
string *banned_name = ({
                         "��", "���", "��","�ҵ�","�Լ�","ƨ", "��", "����","��", "����","��", "����",
                         "����","����","��å","��","��","����","����","ү","��","ë��","��Сƽ","������",
                         "��","��","���˼","����˹","����","��","����","�ϰ���",
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
    set("channel_id", "���߾���");
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
	        write(RED"��Ϸ�������������������У����Եȼ����Ӻ������ߡ�\n"NOR);
	        destruct(ob);
	        return;
	}
     str=query_ip_number(ob);
   if (BAN_D->is_banned(str) == 1) 
            {
                write(HIR"��ĵ�ַ�ڱ� MUD ���ܻ�ӭ����д����jhfy@email.com.cn������\n"NOR);
                destruct(ob);
                return;
            }
    if( mad_lock == 1 ) {
        write("����ʱ���Ѿ�����ˣ����ܽ��룡�� \n");
                destruct(ob);
                return;
        }
 
      	write("\n\n\n");
cat(WELCOME);
write(NOR"��ӭ����"+" "HIM "��Ѫ����"NOR +  HIW" ֮ "NOR +HIG"��������衹\n\n"NOR);
write("\n\n");	
write(MAG+NOR CYN"�������"HIW"����"NOR" : ""akai.isme.net"NOR MAG"  \n"NOR);	
write(MAG+NOR CYN"�������"HIW"ZMUD�˿�"NOR" : ""6666"NOR MAG"  \n"NOR); 	
write(MAG+NOR CYN"�������"HIW"TOMUD�˿�"NOR" : ""8888"NOR MAG"\n"NOR);
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
        printf(	"�����ڴ�%s���߽��롣",CYN+str+NOR);
        printf("�������ַ�ϣ�����"+YEL+chinese_number(ip_cnt-1)+NOR+"λ������ҡ�\n");}
     else printf("�����ڴ�%s���߽��롣\n",CYN+str+NOR);
	printf("Ŀǰ����"+ HIY"%s"NOR+ "λ���ɡ�"+HIW"%s"NOR+ "λ������ʿ�ڽ����У��Լ�"+HIB"%s"NOR+ "λ�������ڲ��뽭����;�С�\n",
		chinese_number(wiz_cnt), chinese_number(ppl_cnt), chinese_number(login_cnt) );
if(ppl_cnt > online_num) {
   user_num = sprintf("%d",ppl_cnt);
   write_file(__DIR__"maxonline",user_num,1);
   }
  if (ban_cnt>8){
        write("���IP��ͬʱ�������ߵ����̫���ˣ����Ժ��ٳ��ԣ��� \n");
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

    write(NOR YEL"����������Ӣ�����֣�"NOR);

    input_to( (: get_id :), ob,ip_cnt );
}
protected void get_version(string arg, object ob,int ip_cnt)
{
	if (! arg || arg[0..3] != "2060")
	{
		write(HIY "����������ҳ����TOMUD�ͻ���\n" NOR);
		write(HIY "��ʹ��Zmud�ͻ���ѡ��5555�˿��������ӡ�\n\n" NOR);
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
        write(YEL"����������Ӣ�����֣�"NOR);
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
            write("�Բ���" + MUD_NAME + "��ʹ�����Ѿ�̫���ˣ������������\n");
            destruct(ob);
            return;
        }
    }
    if( wiz_level(arg) < wiz_lock_level ) 
    {
        write("�Բ���" + MUD_NAME + "Ŀǰ������ʦ�ȼ� " + WIZ_LOCK_LEVEL
            + " ���ϵ��˲������ߡ�\n");
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
                write("�Բ�������ʻ���������һ��ʹ�����ڵ�¼���������������Ӣ������\n");
                write(YEL"����������Ӣ�����֣�"NOR);
        input_to("get_id", ob,ip_cnt);
                return;
        }
        if (BAN_D->is_bandid(arg) == 1)
        {
                write("\n�Բ�������ʻ���������һ��ʹ�����ڵ�¼���������������Ӣ������\n");
                write(YEL"����������Ӣ�����֣�"NOR);
        input_to("get_id", ob,ip_cnt);
                return;
        }
    if( arg=="guest" ) 
    {
                write("�Բ�����������guest�ʻ���¼���������������Ӣ������\n");
                write("����"+HIW"Ӣ��"NOR+"���֣�");
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
                write(HIR"���IP���������̫���ˣ����ܽ��룡�� \n"NOR);
                     destruct(ob);
                     return;
            }
           
        }
    }
    if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 ) 
    {
        if( ob->restore() ) 
        {
            write(YEL"�������������룺"NOR);
            input_to("get_passwd", 1, ob);
            return;
        }
        write("�������ﴢ�浲����һЩ���⣬������ guest ����֪ͨ��ʦ����\n");
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
                write("�Բ�������ʻ���������һ��ʹ�����ڵ�¼���������������Ӣ������\n");
                write("��������������Ӣ�����֣�");
 
                input_to("get_id", ob,ip_cnt);
                return;
                }
         }
    }

    write("ʹ�� "HIW + (string)ob->query("id") + NOR" ������ֽ��ᴴ��һ���µ������ȷ����("HIR"y"NOR"/"HIY"n"NOR")��");
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
			write("��������ǹ������룬�������趨������ͨ���롣\n");
			input_to("new_password", 1, ob);
			return;
		}
    if( crypt(pass, my_pass) != my_pass ) {
    
        err_num=ob->query_temp("error_login");
                err_num++;
                ob->set_temp("error_login",err_num);
                if ( err_num < 3 ){
               write("������"HIR+chinese_number(3-err_num)+NOR"�λ��ᣬ��������ȷ���룺");
                  input_to("get_passwd", 1, ob);
                }else {
                        write("\n���Ѿ�û�л����ˣ�����ú������ߣ�\n");
                        destruct(ob);
                       }
        return;
    }
		if(!ob->query("wizpwd")){
			write("����δ�趨���Ĺ������룬���趨���Ĺ������룺");
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
        write("����ĳ�������Ҫ����ַ����������������룺");
        input_to("reset_wizpwd", 1, ob);
        return;
    }
    if (stringp(ad_pass = ob->query("password")) &&
    	crypt(pass, ad_pass) == ad_pass)
    {
    	write(HIR "��ע�⣬Ϊ�˰�ȫ�����ϵͳҪ����Ĺ����������ͨ���벻����ͬ��\n\n" NOR);
    	write("����������������ͨ���룺");
    	input_to("reset_wizpwd", 1, ob);
    	return;
    }
    ob->set_temp("wizpwd", crypt(pass,0) );
    write("��������һ���������룬��ȷ����û�Ǵ�");
    input_to("confirm_reset_wizpwd", 1, ob);
}
protected void confirm_reset_wizpwd(string pass, object ob)
{
 	
	string old_pass;
	write("\n");
	old_pass = ob->query_temp("wizpwd");
	if( crypt(pass, old_pass)!=old_pass )
	{
		write("��������������벢��һ�����������趨һ�����룺");
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
        write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��("HIR"y"NOR"/"HIY"n"NOR")");
        input_to("confirm_relogin", ob, user);
        return;
    }
    if( objectp(user = make_body(ob)) )
	{
		if( user->restore() )
		{
			
			if(time()-(int)user->query("kickout_time") < 1800)
			{
			write(HIR"\n������Υ�������߳���Ϸ����Ϊ�ͷ�����ʮ���Ӻ������ߡ�\n\n"NOR);
			destruct(user);
			destruct(ob);
			return;
		}
		      
if(time()-(int)ob->query("last_on") < 5)
			{
                        write(HIR"\n����˳���Ϸ��Ϊ�˼���ϵͳ�������һ�������룬лл������^0^\n\n");
			destruct(user);
			destruct(ob);
			return;
		}
		log_file( "login/login",sprintf("%-20s��%20s  ��    ¼(%s)��\n", user->query("name")+"("+user->query("id")+")", query_ip_number(ob), ctime(time()) ) );
			enter_world(ob, user);
			return;
		}
		else
		{
			destruct(user);
		}
	}
    write("�������´���������\n");
    confirm_id("y", ob,1);
}
protected void confirm_relogin(string yn, object ob, object user)
{
    object old_link;
    if (!ob || !user) return ;
    if( yn=="" ) {
        write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
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

        write(GRN"�ðɣ���ӭ�´�������\n"NOR);
        destruct(ob);
        return;
    } else {
        tell_object(user, "���˴ӱ�( "HIW + query_ip_number(ob)
            + NOR" )����ȡ���������Ƶ����\n");
        log_file("login/replace", sprintf("%-20s��%20s  ��������(%s)��\n", user->query("name")+"("+user->query("id")+")", query_ip_number(ob), ctime(time()) ) );    
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
        write("ʹ��������ֽ��ᴴ��һ���µ����������ȷ����("HIR"y"NOR"/"HIY"n"NOR")��");
        input_to("confirm_id", ob,ip_cnt);
        return;
    }   
    if( yn[0]!='y' && yn[0]!='Y' ) {
        write("�ðɣ���ô��������������Ӣ�����֣�");
        input_to("get_id", ob,ip_cnt);
        return;
    }
    write("\n\n");
	write(YEL @TEXT
������������������������������������������������������������������������
��                                                                    ��
��  ��! �����������Լ�ȡһ�������ʣ��и��Ե����֣��õ����ֲ�����ʾ��  ��
��  �������������Ҳ����������һ���õ�ӡ��, ��������˶����������  ��
��  ���ѣ���������һ�����������Ӱ�졣����������������������������  ��
��  �ִ�����������Ժ󽫺��Ѹ��ġ�                                  �� 
��                                                                    ��
��  ���벻Ҫѡ���ӹС˵�������������������Ź۵���������ɾ������    ��
������������������������������֣���ֱ���ûس����ۣңţԣգңΣݡ���������
��                                                                    ��
������������������������������������������������������������������������
TEXT NOR
	);
    write("\n����Լ�ȡһ���������֣�");
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
                write("���Ƿ����������������("HIR"y"NOR"/"YEL"n"NOR")��");
                input_to("get_resp", ob);
                return;
        }

        if( arg[0]=='y' || arg[0]=='Y' )
	{
        printf("%O\n", ob);
        ob->set("name", Rname);
        write("���趨���Ĺ������룺");
        input_to("new_wizpwd", 1, ob);
	return;
	}
        else 
	if( arg[0]=='n' || arg[0]=='N')
	{
	Rname = random_name();
        write("���Ƿ����������������("HIR"y"NOR"/"HIY"n"NOR")��");
        printf( HIW" ����"NOR YEL"�� "HIR"%s"NOR YEL" ��"NOR"��"NOR, Rname);
        input_to("get_resp", ob);
	return;
	}
        else {
                write("�Բ�����ֻ��ѡ������("HIR"y"NOR")������("HIY"n"NOR")�� ");
                input_to("get_resp", ob);
                return;
        }


}
protected void get_name(string arg, object ob)
{
    if( arg =="")
        {
	Rname = random_name();
        write("������Ҫ������������������֣���\n");
         write("�������Ƿ����������������("HIR"y"NOR"/"HIY"n"NOR")��");
      printf( HIW" ����"NOR CYN"�� "HIY"%s"NOR CYN" ��"NOR"��"NOR, Rname);
        input_to("get_resp", ob);
	}
	else {
        if( !check_legal_name(arg) ) {
                write("���ٴ����������������֣�");
                input_to("get_name", ob);
                return;
        }

        printf("%O\n", ob);
        ob->set("name", arg);
        write("���趨���Ĺ������룺");
        input_to("new_wizpwd", 1, ob);
		}
}
protected void new_wizpwd(string pass, object ob)
{
    write("\n");
    if( strlen(pass)<5 ) {
        write("����ĳ�������Ҫ����ַ����������������룺");
        input_to("new_wizpwd", 1, ob);
        return;
    }
    ob->set_temp("wizpwd", crypt(pass,0) );
    write("��������һ���������룬��ȷ����û�Ǵ�");
    input_to("confirm_wizpwd", 1, ob);
}
protected void confirm_wizpwd(string pass, object ob)
{
 	
	string old_pass;
	write("\n");
	old_pass = ob->query_temp("wizpwd");
	if( crypt(pass, old_pass)!=old_pass )
	{
		write("��������������벢��һ�����������趨һ�����룺");
		input_to("new_wizpwd", 1, ob);
		return;
	}
	ob->set("wizpwd", crypt(pass,0) );
	write("�����������ͨ���룺");
	input_to("new_password", 1, ob);
}
	
protected void new_password(string pass, object ob)
{
		string ad_pass;
    write("\n");
    if( strlen(pass)<5 ) {
        write("����ĳ�������Ҫ����ַ����������������룺");
        input_to("new_password", 1, ob);
        return;
    }
    if (stringp(ad_pass = ob->query("wizpwd")) &&
    	crypt(pass, ad_pass) == ad_pass)
    {
    	write(HIR "��ע�⣬Ϊ�˰�ȫ�����ϵͳҪ����Ĺ����������ͨ���벻����ͬ��\n\n" NOR);
    	write("����������������ͨ���룺");
    	input_to("new_password", 1, ob);
    	return;
    }
    ob->set_temp("password", crypt(pass,0) );
    write("��������һ���������룬��ȷ����û�Ǵ�");
    input_to("confirm_password", 1, ob);
}
protected void confirm_password(string pass, object ob)
{
 	
	string old_pass;
	write("\n");
	old_pass = ob->query_temp("password");
	if( crypt(pass, old_pass)!=old_pass )
	{
		write("��������������벢��һ�����������趨һ�����룺");
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
������������������������������������������������������������������������
��                                                                    ��
��  һ��������츳��������������ϰ������ϢϢ��ء���������衹�е�  ��
��  ������������������츳,���и�Ե����ò���������ԣ�               ��
��                                                                    ��
��	�١�������Ӱ�칥���������������Ĵ�С��                        		��
��	�ڡ����ԣ�Ӱ��ѧϰ�书�ؼ����ٶȼ����ʦ����������            		��
��	�ۡ����ǣ�Ӱ�������ָ����ٶȼ������������ӵ�������            		��
��	�ܡ�����Ӱ���������ܵ�������                              		��
��	�ݡ���Ե��Ӱ����ԡ���������ʦ���������档                    		��
������  ��ò��Ӱ����ܣ���ʦ�������Լ���Һ�NPC�����ӡ��       		��
��                                                                    ��
������������������������������������������������������������������������
TEXT NOR);
write("\n���������� "HIR"(1-4)"+NOR" ָ�����е�һ��ֵ���������� "+HIR"0"NOR" ��ϵͳ���ѡ��\n");
write("����ѡ���� ("CYN"0-4"NOR")��");
input_to("select_gift", ob);
}
void get_gift(string yn, object ob, mapping my, int select)
{
	if (yn[0] != 'y' && yn[0] != 'Y') {
		random_gift(my, select);
		printf("\n����[%s]������[%s]������[%s]����[%s]\n",
			display_attr(my["str"]),
			display_attr(my["int"]),
			display_attr(my["con"]),
			display_attr(my["dex"]));
		write("��ͬ����һ���츳��Y/N");
		input_to("get_gift", ob, my, select);
		return;
	}
	write("\n���ĵ����ʼ���ַ��");
	input_to("get_email", ob, my);
}
void select_gift(string yn, object ob)
{
	int i;
	mapping my = ([]);
	if (!sscanf(yn, "%d", i) || i < 0 || i > 4) {
		write("\n�������������ѡ��");
		input_to("select_gift", ob);
		return;
	}
	if (i) {
		write("\n����������Ҫ����ֵ(10-30)��");
		input_to("set_gift", ob, my, i);
	} else get_gift(" ", ob, my, i);
}

void set_gift(string yn, object ob, mapping my, int select)
{
	int i;

	if (!sscanf(yn, "%d", i) || i < 10 || i > 30) {
		write("\n��ֵ�������������룺");
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
		write("�����ʼ���ַ��Ҫ�� id@xxx.xxx �ĸ�ʽ��\n");
		write("���ĵ����ʼ���ַ��");
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

	write("��Ҫ��������("HIG"m"NOR")�Ľ�ɫ��Ů��("HIM"f"NOR")�Ľ�ɫ��");
	input_to("get_gender", ob, user);
}
protected void get_gender(string gender, object ob, object user)
{
    int id_temp; string id_num;
    write("\n");
    if( gender=="" ) {
        write("��Ҫ��������("HIG"m"NOR")�Ľ�ɫ��Ů��("HIM"f"NOR")�Ľ�ɫ��");
        input_to("get_gender", ob, user);
        return;
    }
    if( gender[0]=='m' || gender[0]=='M' )
        user->set("gender", "����");
    else if( gender[0]=='f' || gender[0]=='F' )
        user->set("gender", "Ů��" );
    else {
       write("�Բ�����ֻ��ѡ������("HIG"m"NOR")��Ů��("HIM"f"NOR")�Ľ�ɫ��");
        input_to("get_gender", ob, user);
        return;
    }
    log_file( "login/newid.log", sprintf("%-12s was created from %-20s (%s)\n", user->query("id"),
        query_ip_number(ob), ctime(time()) ) );
    CHANNEL_D->do_channel( this_object(), "sys","����һ������ң�"+user->query("name")+"["+user->query("id")+"]��"NOR);
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
        write("���ڿ������������޸�ʹ��������ĳ�ʽ���޷����и��ơ�\n");
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
    user->set("title", "��ͨ����");
    user->set("birthday", time() );
    user->set("potential", 100);
    user->set("channels", ({ "es","chat", "rumor","tell","new","jh","auction"}) );
    if(user->query("gender") == "Ů��")
	{
	
		user->set("combat_exp", 50);
		user->set("money", 2000);
	}

}
protected void have_mail()
{
     write( BOLD + "\n�ſ�(Post officer)�����㣺�������ţ��뵽��վ��һ��...\n\n" + NOR);
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
       if (user->query("gender")=="Ů��") cloth = new("/clone/misc/pink_cloth");
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
	        write("�� ��ĿǰȨ�ޣ�" + wizhood(user) + "\n");
	        write("�� ���ϴι��ٺ�������Ǵӣ�"+login_ob->query("last_from") +"\n");
//	        write("�� ���ϴ����ߵ�ʱ���ǣ�"+ctime(login_ob->query("last_on")) + "\n\n");
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
        tell_room(startroom, user->query("name") + "���߽���������硣\n",
            ({user}));

    
    write(HIW"�����߽���������磬��ʼ���Լ���"+HIG"����"+HIW"����\n"NOR);
    if(ob->query_temp("no_allow_ip"))   
       write("\n\n���棺��δ�趨�Լ��ĵ�¼��ַ��Χ������"HIR" allowip "NOR"ָ�����á�\n\n");
    if(file_size("/log/login/notice")>0){
       write(HIG"     ����������������������������������������������������������������\n"NOR);
       write(read_file("/log/login/notice"));
        write(HIG"     ����������������������������������������������������������������\n\n"NOR);
        }
    if(user->query("gender") == "����"&&user->query("age")<=25){
		   	switch(random(2))
        { case 0 : str = "������ʿ";break;
          case 1 : str = RANK_D->query_respect(user);break;
         }
         }
        else if(user->query("gender") == "Ů��"&&user->query("age")<=25){
                       switch(random(2))
         {case 0 : str = "������Ů";break;
          case 1 : str = RANK_D->query_respect(user);break;
        }
        }
        else str = RANK_D->query_respect(user);
        
if(!(wizardp(user)&&user->query("env/no_login_msg")))
message("shout", TMI("ptext "+HIR"���м��ջ��"NOR+": "+CYN"��˵������һλ����"+HIW+user->name()+NOR CYN"��"+str+"\n"NOR),users());
  if(user->query("id")!="afei")
	CHANNEL_D->do_channel( this_object(), "sys", sprintf("%s(%s)��%s���߽��롣", user->name(),user->query("id"), query_ip_name(user)) );
    UPDATE_D->check_user(user);
    STATUS_D->compare_status(user);
    if(!wizardp(user)||!user->query("env/invisibility")){
    users = filter_array(users(), (: $1->query_temp("tomud") :));
    message("system",ADD2(user),users);
  }
		user->force_me("wear all");
		if (user->query_temp("tomud")){
if(!user->query("env/no_login_msg"))
		write(ALERT("��������MUD��Ϸ����Ѫ������������ϷΪ�����Ϸ��$$" +
    "�뵽http://akai.isme.net/�������Ϸ��ҳ$$"+
    "������κ����ʣ��뵽����Ϸ������ṩ��WIZ�������޸ı�LIB��AKAI��$$"));
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
        tell_room(environment(user), user->query("name") + YEL"�������߻ص�������硣\n"NOR,
        ({user}));
    }
     if(user->query("id")!="afei")
    CHANNEL_D->do_channel( this_object(), "sys",
        sprintf("%s(%s)��(%s)�������߽��롣", user->query("name"),user->query("id"), query_ip_number(user)) );
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
        write("�Բ������"+HIW"Ӣ��"NOR+"���ֱ����� 3 �� 10 ��Ӣ����ĸ��\n");
        return 0;
    }
    while(i--)
        if( id[i]<'a' || id[i]>'z' ) {
            write("�Բ������"+HIW"Ӣ��"NOR+"����ֻ����Ӣ����ĸ��\n");
            return 0;
        }
    return 1;
}
string random_name()
{
	string *lname = ({
"��","Ǯ","��","��","��","��","֣","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","ʩ","��",
"��","��","��","��","��","κ","��","��","��","л","��","��","��","ˮ","�","��","��","��","��","��","��","��","��","��",
"³","Τ","��","��","��","��","��","��","ɵ","��","Ԭ","��","��","��","ʷ","��","��","��","�","Ѧ","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʱ","��","Ƥ","��","��","��","��","��","Ԫ","��","��","ӯ","ƽ","��",
"��","��","Ф","��","Ҧ","��","տ","��","��","ë","��","��","��","��","��","��","��","��","��","��","̸","��","é","��",
"��","��","��","��","��","ף","��","��","��","��","��","��","��","��","֧","��","��","��","¬","Ӣ","��","��","˾��",
"�Ϲ�","ŷ��","�ĺ�","���","����","����","����","�ʸ�","ξ��","����","�̨","����",
"����","���","����","����","̫��","����","����","����","ԯ��","���","����","����",
"����","Ļ��","˾ͽ","ʦ��","��","��ľ","����","����","���","����","����","����",
"��ֺ","�й�","�׸�","����","����","�ַ�","��۳","Ϳ��","��ǧ","����","����","�Ϲ�",
"����","�麣","����","΢��","��","˧","��","��","��","��","��","��","����","����","����","����",
			});
			 return (lname[random(200)] + chinese_number(random(20)));
}
int check_legal_name(string name)
{
    int i;
    i = strlen(name);
    if( (strlen(name) < 2) || (strlen(name) > 10 ) ) {
        write("�Բ�������������ֱ����� 1 �� 5 �������֡�\n");
        return 0;
    }
    while(i--) {
        if( name[i]<=' ' ) {
            write("�Բ�������������ֲ����ÿ�����Ԫ��\n");
            return 0;
        }
        if( i%2==0 && !is_chinese(name[i..<0]) ) {
            write("�Բ��������á����ġ�ȡ���֡�\n");
            return 0;
        }
    }
        if( member_array(name, banned_name)!=-1 ) {
                write("�Բ����������ֻ���������˵����š�\n");
                return 0;
        }
    for (i=0;i<sizeof(banned_name);i++)
        if ( strsrch(name, banned_name[i])!=-1){
                    write("�Բ����������ֻ���������˵����š�\n");
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

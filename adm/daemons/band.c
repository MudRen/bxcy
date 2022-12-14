// ban.c

#define BANNED_SITES "/adm/etc/banned_sites"
#define WELCOME "/adm/etc/welcome_sites"
#define BANNED_IDS   "/adm/etc/banned_ids"
#define BANNED_NAMES "/adm/etc/banned_names"

void load_sites();
void load_welcome();
void load_banned_names();
void load_banned_ids();

void add_site(string pattern);       // ban一个不欢迎的ip
void remove_site(string pattern);    // 解封一个ip
int is_banned(string site);          // 判断是否一个ban的ip(logind.c调用)
string list_sites();                   // 被ban的ip列表
//  welcome的用户不受ban的影响,而且可以开放这根线上多个ip
string list_welcome_users();           // welcome users列表
int is_welcome(string user_id);      // 判断是否一个welcome的用户(logind.c调用)
void add_welcome_user(string user_id); // 增加一个welcome 用户(id)
void remove_welcome_user(string user_id); // 删除一个welcome 用户(id)
void open_club_line(object user);    // 由welcome用户自己打开网吧地址
int is_netclub(string netline);      // 判断是否一个网吧线的用户(logind.c调用)
void remove_netclub(string netline);  // 移去一条网吧线

string *Sites;
string *Netclubs;
string *Welcomes;
string *Banned_IDs;              //  ban id 表
string *Banned_Names;            //  ban 中文名表

void create()
{
    seteuid(getuid());
    Netclubs = ({"61.143.241.230",});
    load_sites();
    load_welcome();
    load_banned_names();
    load_banned_ids();
}
string *query_sites() { return Sites; }
string *query_welcomes() { return Welcomes; }
string *query_banned_ids() { return Banned_IDs; }
string *query_banned_names() { return Banned_Names; }


void load_banned_ids()
{
    string *tmp, file;
    int loop;
    Banned_IDs = ({});
    
    // reads in the list of the sites
    file = read_file(BANNED_IDS);
    if (!file) return;
    
    tmp = explode(file, "\n");
    for(loop=0; loop<sizeof(tmp); loop++)
            if(tmp[loop][0] == '#' || tmp[loop][0] == '\n' || tmp[loop] == "")
                continue;
            else Banned_IDs += ({ tmp[loop] });
}

void load_banned_names()
{
    string *tmp, file;
    int loop;
    
    // reads in the list of the sites
    Banned_Names=({});
    file = read_file(BANNED_NAMES);
    if (!file) return;
    
    tmp = explode(file, "\n");
    for(loop=0; loop<sizeof(tmp); loop++)
            if(tmp[loop][0] == '#' || tmp[loop][0] == '\n' || tmp[loop] == "")
                continue;
            else Banned_Names += ({ tmp[loop] });
}

void load_sites()
{
    string *tmp, file;
    int loop;
    Sites = ({});
    
    // reads in the list of the banned sites
    file = read_file(BANNED_SITES);
    if (!file) return;
    
    tmp = explode(file, "\n");
    for(loop=0; loop<sizeof(tmp); loop++)
            if(tmp[loop][0] == '#' || tmp[loop][0] == '\n' || tmp[loop] == "")
                continue;
            else Sites += ({ tmp[loop] });
}

void load_welcome()
{
    string *tmp, file;
    int loop;
    Welcomes = ({});
    // reads in the list of the banned sites
    file = read_file(WELCOME);
    if (!file) return;
    
    tmp = explode(file, "\n");
    for(loop=0; loop<sizeof(tmp); loop++)
            if(tmp[loop][0] == '#' || tmp[loop][0] == '\n' || tmp[loop] == "")
                continue;
            else Welcomes += ({ tmp[loop] });
}
int is_banned(string site)
{
    string *line = ({site});
    string tmp1,tmp2,tmp3,tmp4;
    int i;
    if (!site)  return 1;

    if (sscanf(site,"%s.%s.%s.%s",tmp1,tmp2,tmp3,tmp4)!=4)
        return 1;
    // 禁止使用虚拟ip 或 route
    if (tmp4=="0" || tmp4=="255")
        return 1;
    for (i = 0; i < sizeof(Sites); i++)
       if (sizeof(regexp(line, Sites[i])) == 1)
            return 1;
        return 0;
} 

int is_bandid(string user_id)
{
    if (member_array(user_id,Banned_IDs)==-1)  return 0;
    return 1;
} 
void add_site(string site)
{ 
 string tmp1,tmp2,tmp3,tmp4;
    int i;
   
    if (!site)  return;
   // 禁止地址
    if (sscanf(site,"%s.%s.%s.%s",tmp1,tmp2,tmp3,tmp4)==4){
      if (is_banned(site)){
         write (RED+site+"已经被禁止!\n"+NOR);
         return;
      }
      if (tmp1=="*"){
         write (RED+site+"的IP范围太大了!\n"+NOR);
         return;
      }
      Sites += ({site});
      write_file(BANNED_SITES, Sites[sizeof(Sites)-1] + "\n", 0);
  write (RED "\n禁止地址"+site+"...OK!\n" NOR);
      Netclubs -= ({ site });
      return;
    }
    // 禁止使用中文名
    if (is_chinese(site)){
       if( sizeof(Banned_Names) && member_array(site, Banned_Names)!=-1 ) {
               write (RED+site+"已经被禁止!\n"+NOR);
               return;
        }
        for (i=0;i<sizeof(Banned_Names);i++)
            if ( strsrch(site, Banned_Names[i])!=-1){
               write (RED+site+"已经被禁止!\n"+NOR);
               return;
            }
      Banned_Names+= ({site});
      write_file(BANNED_NAMES, Banned_Names[sizeof(Banned_Names)-1] + "\n", 0);
      write (RED "\n禁止使用中文名"+site+"...OK!\n" NOR);
      return;
    }
    i=strlen(site);
    if( (strlen(site) < 3) || (strlen(site) > 12 ) ) {
       write("英文名字必须是 3 到 12 个英文字母。\n");
     return;
    }
    while(i--)
       if( site[i]<'a' || site[i]>'z' ) {
           write("只能用英文字母。\n");
           return;
       }
   if( member_array(site, Banned_IDs)!=-1 ) {
           write(site+"在列表中已经存在。\n");
           return;
   }

    Banned_IDs += ({ site });
    write_file(BANNED_IDS, Banned_IDs[sizeof(Banned_IDs)-1] + "\n", 0);
    write (BOLD "\n增加"+HIY+site+HIW+"到列表...OK!\n" NOR);
}


void remove_site(string site)
{
    string tmp1,tmp2,tmp3,tmp4;
    int i;
    string *line = ({site});
   
  if (!site)  return;
    // 解除禁止地址
    if (sscanf(site,"%s.%s.%s.%s",tmp1,tmp2,tmp3,tmp4)==4){
        if (!is_banned(site)){
            write ("\n这个地址并未被禁止!\n");
            return;
        }
        for (i = 0; i < sizeof(Sites); i++)
            if (sizeof(regexp(line, Sites[i])) == 1)
                Sites -= ({ Sites[i] });
            write_file(BANNED_SITES, implode(Sites, "\n")+"\n", 1);
        write (BOLD "\n解禁地址"+site+"...OK!\n" NOR);
        return;
    }
    // 解除禁止使用的中文名
    if (is_chinese(site)){
       if( member_array(site, Banned_Names)==-1 ) {
                write (RED+site+"没被禁止使用!\n"+NOR);
       }else{
                Banned_Names-= ({site});
                write_file(BANNED_NAMES, implode(Banned_Names,"\n")+"\n", 1);
                write (RED "\n解禁中文名"+site+"...OK!\n" NOR);
                return;
  }
       for (i=0;i<sizeof(Banned_Names);i++)
            if ( strsrch(site, Banned_Names[i])!=-1){
                Banned_Names -= ({site});
                write_file(BANNED_NAMES, implode(Banned_Names,"\n")+"\n", 1);
                write (RED "\n解禁中文名"+site+"...OK!\n" NOR);
                return;
            }
        write (HIY+site+HIW+"没被禁止!\n" NOR);
        return;
    }
    i=strlen(site);
    if( (strlen(site) < 3) || (strlen(site) > 12 ) ) {
       write("英文名字必须是 3 到 12 个英文字母。\n");
       return;
    }
    while(i--)
       if( site[i]<'a' || site[i]>'z' ) {
           write("只能用英文字母。\n");
           return;
       }
   if( member_array(site, Banned_IDs)!=-1 ) {
        Banned_IDs -= ({ site });
  write_file(BANNED_IDS, implode(Banned_IDs,"\n") + "\n", 1);
        write (BOLD "\n解除使用英文名"+HIY+site+HIW+"的限制!\n" NOR);
        return;
   }
    write (HIY+site+HIW+"没被禁止!\n" NOR);
}




int is_welcome(string user_id)
{
    if (member_array(user_id,Welcomes)==-1)  return 0;
    return 1;
}

void add_welcome_user(string user_id)
{
    if (is_welcome(user_id)){
       write("这个id已经列入了welcome player!\n");
       return;
    }
    Welcomes += ({ user_id });
    write_file(WELCOME, Welcomes[sizeof(Welcomes)-1] + "\n", 0);
    write (BOLD "\n增加welcome user "+HIY+user_id+HIW+"...OK!\n" NOR);
    write(list_welcome_users());
}

void remove_welcome_user(string user_id)
{
    if (!is_welcome(user_id)){
       write("这个id并未列入了welcome player!\n");
       return;
    }
    Welcomes -= ({ user_id });
    write_file(WELCOME, implode(Welcomes,"\n")+"\n", 1);
    write (BOLD "\n删除welcome user "+HIY+user_id+HIW+"...OK!\n" NOR);
    write(list_welcome_users());
}

string list_welcome_users()
{
    if (!sizeof(Welcomes))
        return (BOLD "现在还没有Welcome user.\n" NOR);
    return sprintf(HIY MUD_NAME+"的Welcome users如下:\n"+HIC+"  %s\n" NOR,implode(Welcomes, "\n  "));
}

void list_netclubs()
{
    if (!sizeof(Netclubs)){
        write(BOLD "现在没有开放的网吧地址!\n" NOR);
        return;
    }
    printf(HIY "\n现在允许多人同时进入"+MUD_NAME+"的ip地址如下:\n"+HIC+"  %s\n" NOR,implode(Netclubs, "\n  "));
}

int is_netclub(string netline)
{
    int i;
    string *line = ({netline});
    
    for (i = 0; i < sizeof(Netclubs); i++)
        if (sizeof(regexp(line, Netclubs[i])) == 1)
            return 1;
    return 0;
}

void remove_netclub(string netline)
{
    int i;
    string *line = ({netline});
    
    for (i = 0; i < sizeof(Netclubs); i++)
        if (sizeof(regexp(line, Netclubs[i])) == 1){
            Netclubs -= ({ Netclubs[i] });
            write (HIR "\n删除网吧地址"+netline+"...OK!\n" NOR);
            return;
        }
    write ("\n这个地址并不是网吧线!\n");
}

void open_club_line(object user)
{
    int i;
    string netline;
    string *line;
    if (!user) user=this_player();
    netline=query_ip_number(user);
    line = ({netline});
    if (!wizardp(user) && !is_welcome(user->query("id"))){
       write("你未列入welcome player,请向巫师申请!\n");
       write("\n申请方式:通过mailbox写信给arch以上级别的巫师,通过后\n巫师会回信通知你,以后用这个id上来打开你的网吧线即可,\n请注意督促你所在网吧的玩家遵守游戏规则。谢谢合作！\n\n");
       return;
    }
    for (i = 0; i < sizeof(Netclubs); i++)
        if (sizeof(regexp(line, Netclubs[i])) == 1){
            write (HIY+netline+"网吧线已经打开!\n"+NOR);
            return;
    }
      if (netline=="202.96.190.124"){
            write (HIY+"你现在所占用的是网关!\n"+NOR);
             remove_welcome_user(user->query("id"));
            return;
     }
    Netclubs += ({ netline });
    write (BOLD "\n打开网吧地址"+netline+"...OK!\n" NOR);
}
string list_sites()
{
    int flag;
    string msg=HIC "\n现在被禁止进入"+MUD_NAME+"的ip地址如下:\n"+HIR;
    if (!sizeof(Sites))
        return (BOLD "现在没有被禁止的地址!\n" NOR);
    flag=0;
    foreach (string str in sort_array(Sites,1)){
        msg += str;
  flag++;
        if (flag % 8 )
            msg += "\t";
        else
            msg += "\n";
    }
    return msg+"\n"+NOR;
}

int vaild_allow_address(object ob)
{
   string *address;
   string *line;
   int i;
   
   if (!ob) return 0;
   address=ob->query("allow_ip");
   if (!sizeof(address)){
       ob->set_temp("no_allow_ip",1);
  //     write(HIY+"\n警告：你未设定自己的登录地址范围。请用allowip指令设置。\n"+NOR);
   if (is_welcome(ob->query("id")) && !is_netclub(query_ip_number(ob))){
      open_club_line(ob);    // 并自动开放网吧限制
    log_file("login/open_netclub",sprintf("user %s open ip address %s limit in %s.\n",ob->query("id"),query_ip_number(ob),ctime(time())));
    }
      return 1;
   }
   line=({ query_ip_number(ob) });
   for (i = 0; i < sizeof(address); i++)
        if (sizeof(regexp(line, address[i])) == 1){
   if (is_welcome(ob->query("id")) && !is_netclub(query_ip_number(ob))){
      open_club_line(ob);    // 并自动开放网吧限制
    log_file("login/open_netclub",sprintf("user %s open ip address %s limit in %s.\n",ob->query("id"),query_ip_number(ob),ctime(time())));
    }
            return 1;
    }
    write(HIR+"\n严重警告：你不在自己所设定的登录地址范围内。\n"+NOR);
    log_file("login/ALLOW_IP",sprintf("%s(%s)于%s试图从%s登录。\n",ob->query("name"),ob->query("id"),ctime(time()),query_ip_number(ob)));
    return 0;
   
}

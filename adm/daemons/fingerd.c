// fingerd.c
#include <net/dns.h>
void create() { seteuid( getuid() ); }
string age_string(int time)
{
        int day, hour, min, sec;
        sec = time % 60;
        time /= 60;
        min = time % 60;
        time /= 60;
        hour = time % 24;
        time /= 24;
        day = time;
        return (day?sprintf("%3d日",day):"     ") +(hour?sprintf("%2d时",hour):"    ") + sprintf("%2d分",min);
}
        
string finger_all()
{
    object *ob;
    string msg, *all_user=({});
    int i;
    ob = filter_array(users(), "sort_user", this_object(),this_player());
    msg = "";
    if ( !wizardp(this_player()) )  // player finger
    {
        for(i=0; i<sizeof(ob); i++) {
                if( !environment(ob[i]) ) continue;
            msg = sprintf("%s%-14s%-12s%14s%9s\n",
                msg, ob[i]->query("name"), ob[i]->query("id"),
//                age_string( (int)ob[i]->query("mud_age")), 
                CHINESE_D->chinese_number((int)ob[i]->query("age"))+"岁", 
                query_idle(ob[i]) + "秒");
        }
        return "◎  "+MUD_NAME+"\n" + 
        "—————————————————————————\n"
        + "姓名          帐号              年  龄    发呆\n" +
        "—————————————————————————\n"
        + msg +
        "—————————————————————————\n";
    } else      // wizard finger
    {
        for(i=0; i<sizeof(ob); i++) {
            all_user+=({ sprintf("%-20s%-12s%-14s%-16s%s\n", query_ip_number(ob[i]),
                ob[i]->query("name"), ob[i]->query("id"),
                age_string( (int)ob[i]->query("mud_age")), 
                query_idle(ob[i]) + "秒") });
        }
        all_user=sort_array(all_user,(: strcmp :));
        for(i=0; i<sizeof(all_user); i++) {
                msg += all_user[i];
        }
        return "◎  "+MUD_NAME+"\n" + 
        "—————————————————————————————————————\n"
        + "     连线           姓名          帐号            年    龄    发呆\n" +
        "—————————————————————————————————————\n"
        + msg +
        "—————————————————————————————————————\n";
    }
}
int sort_user(object ob1, object ob2)
{
    if (!ob2) return 1;
    if (ob1==ob2) return 1;
    return ob2->visible(ob1);
}

string finger_user(string name)
{
        object ob, body;
        string msg, mud;
      if( sscanf(name, "%s@%s", name, mud)==2 ) {
                GFINGER_Q->send_finger_q(mud, name, this_player(1));
                return "网路指令传送过程可能需要一些时间，请稍候。\n";
        }
        ob = new(LOGIN_OB);
        ob->set("id", name);
        if( !ob->restore() ) return "没有这个玩家。\n";
      if (!stringp(ob->query("name")) )   return "没有这个玩家。\n";
        
    if ( !wizardp(this_player()) )  // player finger
        {
        
                body = LOGIN_D->make_body(ob);
                if( !body || !body->restore() ) return "没有这个玩家。\n";
                destruct(body);
                msg =  sprintf("\n英文代号：\t%s\n姓    名：\t%s\n权限等级：\t%s\n"
                        "电子邮件地址：\t%s\n上次连线：\t%s\n\n%s\n",
                        ob->query("id"),
                        ob->query("name"),
                        ob->query("call")?"(test_player)":SECURITY_D->get_status(name),
                        ob->query("email"),
                        ctime(ob->query("last_on")),
                      stringp(ob->query("profile"))?(ob->query("profile")):""
                );
                if( objectp(body = find_player(name)) && this_player()->visible(body) ) {
                        msg += sprintf("\n%s目前正在连线中。\n", body->name(1));
                }
        } else          // wizard finger
        {
                msg =  sprintf("\n英文代号：\t%s\n姓    名：\t%s\n权限等级：\t%s\n"
                        "电子邮件地址：\t%s\n上次连线地址：\t%s( %s )\n\n%s\n",
                        ob->query("id"),
                        ob->query("name"),
                        ob->query("call")?"(test_player)":SECURITY_D->get_status(name),
                        ob->query("email"),
                        ob->query("last_from"),
                        ctime(ob->query("last_on")),
                      stringp(ob->query("profile"))?(ob->query("profile")):""
                );
                if( objectp(body = find_player(name)) && this_player()->visible(body) ) {
                        msg += sprintf("\n%s目前正在从 %s 连线中。\n", body->name(1),
                                query_ip_name(body));
                }
        }       
        
        destruct(ob);
        return msg;
}
varargs string remote_finger_user(string name, int chinese_flag)
{
        object ob, body;
        string msg;
        ob = new(LOGIN_OB);
        ob->set("id", name);
        if( !ob->restore() )
                return chinese_flag ? "没有这个玩家。\n" : "No such user.\n";
        if( chinese_flag ) msg =  sprintf(
                "\n英文代号：\t%s\n姓    名：\t%s\n权限等级：\t%s\n"
                "电子邮件地址：\t%s\n上次连线：\t%s\n\n",
                ob->query("id"),
                ob->query("name"),
                SECURITY_D->get_status(name),
                ob->query("email"),
                ctime(ob->query("last_on"))
        );
        else msg =  sprintf(
                "\nName\t: %s\nStatus\t: %s\nEmail\t: %s\nLastOn\t: %s\n\n",
                capitalize(ob->query("id")),
                SECURITY_D->get_status(name),
                ob->query("email"),
                ctime(ob->query("last_on"))
        );
        if( body = find_player(name) ) {
                if( !this_player() || this_player()->visible(body) )
                        msg += chinese_flag ?
                                ("\n" + ob->query("name") + "目前正在线上。\n"):
                                ("\n" + capitalize(name) + " is currently connected.\n");
        }
        destruct(ob);
        return msg;
}

object acquire_login_ob(string id)
{
        object ob;
        if( ob = find_player(id) ) {
                // Check if the player is linkdead
                if( ob->query_temp("link_ob") )
                        return ob->query_temp("link_ob");
        }
        ob = new(LOGIN_OB);
        ob->set("id", id);
        return ob->restore() ? ob : 0;
}
string get_killer()
{
        int i;
        string msg;
        object *ob = users();
        msg = "";
        for (i = 0; i < sizeof(ob); i++)
                if ((int)ob[i]->query_condition("killer"))
                        msg += (ob[i]->query("title")+" "+ob[i]->name(1)+"("+ob[i]->query("id") + ")\n");
        if (msg == "")
                return "本城治安良好。\n";
        else
                return "现在本城正在缉拿以下人犯：\n\n" + msg;
}


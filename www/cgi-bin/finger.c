#include <mudlib.h>

void create() { seteuid( getuid() ); }

string gateway(string args) {

    object ob,body;
    string str;
    int online;

    online = 0;

    if( sscanf(args,"id=%s",args) == 0)

        return "请先填好表格";



    ob = new(LOGIN_OB);

    ob->set("id", args);



    if( !ob->restore() ) return "没有这个玩家。\n";



    if( objectp(body = find_player(args)) && geteuid(body)==args ) {

        if( body->query("env/invisibility") < 1 )

            if( !body->is_ghost() )

                online = 1;

    }

    str = "<html><title>查询玩家</title><body>";

    str += sprintf(
                "<h3 align=center><font face='幼圆' color=#ff0000>%s"
                "<font face='幼圆'color=#000000>玩家查询</font>"
                "</h3><p><hr></p>",
                CHINESE_MUD_NAME
                );

    str += sprintf(
        "<center><TABLE BORDER=5>"

        "<TR><TH>英文代号：</TH><TD>%s</TD></TR>"

        "<TR><TH>姓    名：</TH><TD>%s</TD></TR>"

        "<TR><TH>权限等级：</TH><TD>%s</TD></TR>"

        "<TR><TH>上次连线：</TH><TD>%s</TD></TR>"

        "<TR><TH>是否在线：</TH><TD>%s</TD></TR>"

        "</TABLE>",

        ob->query("id"),

        ob->query("name"),

        SECURITY_D->get_status(args),

        ctime(ob->query("last_on")),

        online

? "是" : "否"
        );

    destruct(ob);
    str += "</center></body></html>";
    return str;

}
// who.c

#include <net/daemons.h>
#include <net/macros.h>

inherit F_CLEAN_UP;
int sort_user(object ob1, object ob2);

string gateway(string pattern) 
{
	string	ret = "<HEAD><TITLE>"+MUD_NAME+"目前在线的玩家</TITLE></HEAD>";
        object *list;
	int i;

        list = sort_array(users(), "sort_user", this_object());

	if ( stringp(pattern) )
		return __DIR__"finger"->gateway("id="+pattern);
	ret += sprintf("<h3 align=center><font face='幼圆' color=#ff0000>%s"
				"<font face='幼圆'color=#000000>在线玩家列表</font>"
				"</h3><hr>",CHINESE_MUD_NAME);

	ret += "<center><TABLE BORDER=1><br><font size=3 face=黑体>";

	foreach ( object player in list )
	{
		if( !environment(player) ) continue;
                if( wizardp(player) && player->query("env/invisibility") ) continue;
		ret += sprintf("<td><font size=3 face='幼圆'>"+
		"<a href=who.c?%s <em>  %s(%s)  </em></a></font>",player->query("id"),player->name(1),capitalize(player->query("id")));
		if( i%3 == 2 )
			ret += "<tr>";
		i++;
	}
	ret += "</TABLE>";
	ret +="<p><hr></p><p><font size=4 face='幼圆' color=#340460>共有"+CHINESE_D->chinese_number(i)+ "个玩家连线中。</font></p></center></body>";
	return ret;
}
int sort_user(object ob1, object ob2)
{
        if( wizardp(ob1) && !wizardp(ob2) ) return -1;
        
        if( wizardp(ob2) && !wizardp(ob1) ) return 1;

        if( wizardp(ob1) && wizardp(ob2) )
                return (int)SECURITY_D->get_wiz_level(ob2) 
                        - (int)SECURITY_D->get_wiz_level(ob1);

        if( ob1->query("id") && !ob2->query("id") )
                return -1;
        if( ob2->query("id") && !ob1->query("id") )
                return 1;
        if( !ob1->query("id") && !ob2->query("id") )
                return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
        return strcmp(ob2->query("id"), ob1->query("id"));
}

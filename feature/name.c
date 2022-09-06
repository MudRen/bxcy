// name.c
#pragma save_binary
#include <dbase.h>
#include <condition.h>
nosave string *my_id;
void set_name(string name, string *id)
{
    set("name", name);
    set("id", id[0]);
    my_id = id;
}
int id(string str)
{
    string *applied_id;
    if( pointerp(my_id) && member_array(str, my_id)!=-1 ) {
        if( pointerp(applied_id = query_temp("apply/id")) 
            &&  sizeof(applied_id) ) {
                if (this_player() && !wizardp(this_player()) )
                     return 0;
        }
        return 1;
    }
    return 0;
}

string *parse_command_id_list()
{
/*  string *applied_id;
    if( pointerp(applied_id = query_temp("apply/id")) 
    &&  sizeof(applied_id) )
        return applied_id+my_id;
    else
*/
        return my_id;
}
varargs string name(int raw)
{
    string str, *mask;
    
    if( !raw && sizeof(mask = query_temp("apply/name")) )
        return mask[sizeof(mask)-1];
    else {
        if( stringp(str = query("name")) )
            return str;
        else
            return file_name(this_object());
    }
}
varargs string short(int raw)
{
    mapping party;
    string party_title,title, nick,degree, str, *mask;
    int fadai;
    
    if( !stringp(str = query("short")) )
        str = name(raw) + "(" + capitalize(query("id")) + ")";
    if( !this_object()->is_character() ) return str;
    if( stringp(nick = query("nickname")) )
        str = sprintf("��%s��%s", nick, str);
    if( stringp(title = query("title")) )
        str = sprintf("%s%s%s", title,(nick?"":" "), str);
    if ( mapp(party = query("party")) ) 
    {
        party_title = party["party_name"] + party["rank"];
        str=sprintf("%s %s", party_title, str);
    }
    if ( stringp(degree = query("degree")) ) 
		{
			str = sprintf("%s%s%s%s%s",degree,(party_title?"":""),(title?"":""),(nick?"":" "), str);
		}
    if (!raw) {
        if(sizeof(mask = query_temp("apply/short")) )
            str = (string)mask[sizeof(mask)-1];
        if ((int)query_temp("pending/exercise") != 0)
            return name() + "�����ڵ�������������";
        else if ((int)query_temp("pending/respirate") != 0)
            return name() + "�����ڵ�������������";
        if( this_object()->is_ghost() ) str = HIB "(�Ļ�) " NOR + str;
        if( query_temp("netdead") ) str += HIG " <������>" NOR;
        if( in_input() ) str += HIC " <����������>" NOR;
        if( in_edit() ) str += HIY " <�༭������>" NOR;
        if(query("env/invisibility")) str +="<������>"NOR;
        if( interactive(this_object())
        &&  query_idle( this_object() ) > 120 ) {
        	fadai = 16-(int)this_object()->query("int")/2;
        	if (fadai<0) fadai = 0;
this_object()->improve_skill("fadai-qigong",fadai);
        	str += HIM+" <����"+chinese_number(query_idle(this_object())/60)+"����>"+NOR;
        	}
        if( !living(this_object()) ) str += HIR + query("disable_type") + NOR;
    }
    return str;
}
varargs string long(int raw)
{
    string str, extra, *mask;
    
    if( !raw && sizeof(mask = query_temp("apply/long")) )
        str = mask[sizeof(mask)-1];
    else if( !stringp(str = query("long")) )
        str = short(raw) + "��\n";
    if( stringp(extra = this_object()->extra_long()) )
        str += extra;
    return str;
}

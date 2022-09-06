#include <login.h>
#include <dbase.h>
inherit F_DBASE;
inherit F_SAVE;
void logon()
{
	call_out( "time_out", LOGIN_TIMEOUT );
	LOGIN_D->logon( this_object() );
}
// Don't destruct(this_object()) in the net_dead() interactive apply or
// there'll be error message: Double call to remove_interactive()
void net_dead()
{
	remove_call_out("time_out");
	call_out( "time_out", 1 );
}
object find_body(string name)
{
        object ob, *body;
	if (!name) return 0;
        if( objectp(ob = find_player(name)) )
                return ob;
        body = children(USER_OB);
        for(int i=0; i<sizeof(body); i++)
                if( clonep(body[i])
                &&      getuid(body[i]) == name ) return body[i];
        return 0;
}
void time_out()
{
	object user;
	if( objectp(query_temp("body_ob")) ) return;
	user=find_body(this_object()->query("id"));
	if (user && (!user->query("title")))
		destruct(user);
	if( interactive(this_object()) )
		write("���������߽���������ʱ��̫���ˣ��´���������ɡ�\n");
	destruct(this_object());
}
// This is used by F_SAVE to determinethe file name to save our data.
string query_save_file()
{
	string id;
	id = query("id", 1);
	if( !stringp(id) ) return 0;
	return sprintf(DATA_DIR "login/%c/%s", id[0], id);
}
void receive_message(string type, string str)
{
	if( type!= "write" ) return;
	receive(str);
}
void terminal_type(string term_type)
{
	set_temp("terminal_type", term_type);
}
// Protect login object's data against hackers.
nomask mixed set(string prop, mixed data)
{
	if( geteuid(previous_object()) != ROOT_UID ) return 0;
	return ::set(prop, data);
}

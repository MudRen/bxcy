// user.c
#include <origin.h>
#include <user.h>
#include <ansi.h>
inherit CHARACTER;
inherit F_AUTOLOAD;
inherit F_SAVE;
inherit F_BACKUP;
nosave int last_age_set;

nomask mixed set(string prop, mixed data)
{
    if (objectp(previous_object()))
        if( !SECURITY_D->valid_set( this_object(), previous_object()) )
            return 0;
    return ::set(prop,data);
}
nomask int delete(string prop)
{
    if (objectp(previous_object()))
        if( !SECURITY_D->valid_set( this_object(), previous_object()) )
            return 0;
    return ::delete(prop);
}

nomask mapping query_entire_dbase()
{
    if (objectp(previous_object()))
        if( !SECURITY_D->valid_set( this_object(), previous_object()) )
            return 0;
    return ::query_entire_dbase();
}
nomask mixed set_temp(string prop, mixed data)
{
    if (objectp(previous_object()))
        if( !SECURITY_D->valid_set( this_object(), previous_object()) )
            return 0;
    return ::set_temp(prop,data);
}
nomask int delete_temp(string prop)
{
    if (objectp(previous_object()))
        if( !SECURITY_D->valid_set( this_object(), previous_object()) )
            return 0;
    return ::delete_temp(prop);
}
nomask mapping query_entire_temp_dbase()
{
    if (objectp(previous_object()))
        if( !SECURITY_D->valid_set( this_object(), previous_object()) )
            return 0;
    return ::query_entire_temp_dbase();
}


nomask mapping query_skills()
{
    if (objectp(previous_object()))
        if( !SECURITY_D->valid_set( this_object(), previous_object()) )
                return 0;
    return ::query_skills();
}

nomask void set_skill(string skill, int val)
{
    if (objectp(previous_object()))
        if( !SECURITY_D->valid_set( this_object(), previous_object()) )
                return;
     ::set_skill(skill, val);
}
nomask int delete_skill(string skill)
{
    if (objectp(previous_object()))
        if( !SECURITY_D->valid_set( this_object(), previous_object()) )
                return 0;
    return ::delete_skill(skill);
}


nomask varargs void improve_skill(string skill, int amount, int weak_mode)
{
    if (objectp(previous_object()))
        if( !SECURITY_D->valid_set( this_object(), previous_object()) )
                return;
::improve_skill(skill, amount, weak_mode);                 	
}

nomask void die()
{
    if (objectp(previous_object()))
        if( !SECURITY_D->valid_set( this_object(), previous_object()) )
                return;
    ::die();
}

/*
nomask void clear_condition()
{
    if (objectp(previous_object()))
        if( !SECURITY_D->valid_set( this_object(), previous_object()) )
                return;
    ::clear_condition();
}
*/


void create()
{
    ::create();
    set_name("ʹ�������", ({ "user object", "user", "object" }) );
}
void terminal_type(string term_type)
{
    set_temp("terminal_type", term_type);
    message("system", "�ն˻���̬�趨Ϊ " + term_type + "��\n", this_object());
}
void reset()
{
    if( (int)query("thief") > 0 )
        add("thief", -1 );
}
// This is used by F_SAVE to determine the filename to save our data.
string query_save_file()
{
    string id;
    id = geteuid();
    if( !id ) id = getuid();
    if( !stringp(id) ) return 0;
    return sprintf(DATA_DIR "user/%c/%s", id[0], id);
}
int save()
{
    int res;
    save_autoload();
    res = ::save();
    clean_up_autoload();        // To save memory
    return res;
}
int backup()
{
   int res;

   save_autoload();
   res = ::backup();
   clean_up_autoload();
   return res;
}
// This function updates player's age, called by heart_beat()
void update_age()
{
    // Update the time we spend on mudding, using method from TMI-2 mudlib.
    if (!environment()) return;
    if (environment()->query("freeze")){
        last_age_set = time();
        return;
    }
    if( !last_age_set ) last_age_set = time();
    add("mud_age", time() - last_age_set);
    last_age_set = time();
    set("age", 14 + (int)query("age_modify") + ((int)query("mud_age") / 86400));
}
void setup()
{
    // We want set age first before new player got initialized with
    // random age.
    update_age();
    ::setup();
    restore_autoload();
}
protected void user_dump(int type)
{
    switch(type) {
        case DUMP_NET_DEAD:
            tell_room( environment(), query("name") + "���߳��� "
                + NET_DEAD_TIMEOUT/60 + " ���ӣ��Զ��˳�������硣\n");
            command("quit");
            break;
        case DUMP_IDLE:
            if ( wizardp(this_object()) || environment()->query("freeze"))
                return;
            tell_object( this_object(), "�Բ������Ѿ��������� " 
                + IDLE_TIMEOUT/60 + " �����ˣ����´�������\n");
            tell_room( environment(), "һ��紵�����������е�" + query("name")
                + "��Ϊһ�ѷɻң���ʧ�ˡ�\n", ({this_object()}));
            command("quit");
            break;
        default: return;
    }
}
// net_dead: called by the gamedriver when an interactive player loses
// hir network connection to the mud.
protected void net_dead()
{
    object link_ob;
    if( objectp(link_ob = query_temp("link_ob")) )
        destruct(link_ob);
    if (!environment()){
        command("quit");
        return;
    }
    set_heart_beat(0);
    // Stop fighting, we'll be back soon.
    remove_all_enemy();
    set_temp("netdead", 1);
    if( userp(this_object()) ) {
        call_out("user_dump", NET_DEAD_TIMEOUT, DUMP_NET_DEAD);
        tell_room(environment(), query("name") + "�����ˡ�\n", this_object());
        environment()->set("channel_id",environment()->query("short"));
        CHANNEL_D->do_channel(environment(), "sys", query("name")+ "(" + capitalize(query("id")) + ")"+"�����ˡ�");
    }
}
// reconnect: called by the LOGIN_D when a netdead player reconnects.
void reconnect()
{
    set_heart_beat(1);
    set_temp("netdead",0);
    remove_call_out("user_dump");
    tell_object(this_object(), "����������ϡ�\n");
}
void kick()
{
    if (is_busy() || is_fighting() )  return;
    command("quit");
}
int id(string str)
{
    string *applied_id;
    if (geteuid(this_object())!=str) return 0;
    if( pointerp(applied_id = query_temp("apply/id"))
        &&  sizeof(applied_id) )
        if( this_player() && !wizardp(this_player()) )
            return 0;
    if( this_player() && !this_player()->visible(this_object()) )
        return 0;

    return 1;
}

                                                         

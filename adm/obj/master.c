//
// master.c
//
// change by Fan@wanxia

#define TOMUD_PORT 8888

#include <runtime_config.h>
#define LOGIN_OB_BAK LOGIN_OB+"bak"
nomask string get_player_fname()
{
    string err;
    object ob;

    if ( err = catch(ob = load_object(LOGIN_OB)) || !ob )
    {
        if ( !ob )
            err = "File '" + LOGIN_OB + "' does not exist!";
        write("Main login ob not loadable!\n" + err + "\n");
        if ( err = catch(ob = load_object(LOGIN_OB_BAK)) )
            write("Spare login obj not loadable!\n" + err + "\n");
        else if ( !ob )
                write("Spare login ob (" + LOGIN_OB_BAK + ") does not exist!\n");
            else
            return LOGIN_OB_BAK;
    }else
    return LOGIN_OB;


}

object connect(int port)
{
    object login_ob;
    mixed err;

    err = catch(login_ob = new(get_player_fname()));

    if (err) {
        write("�������������޸�ʹ�������߲��ݵĳ�ʽ�������������\n");
        write(err);
        destruct(this_object());
    }
    if (port == TOMUD_PORT)
        login_ob->set_temp("tomud", 1);
    return login_ob;
}


mixed compile_object(string file)
{
    object daemon;
    if( daemon = find_object(VIRTUAL_D) )
        return daemon->compile_object(file);
    else
        return 0;
}

protected void crash(string error, object command_giver, object current_object)
{
    mixed cmds;
    int i;
    foreach (object player in users()){
        player->save();
        player->query_temp("link_ob")->save();
       tell_object(player,"ϵͳ���ķ���һ���ҽУ��ۡ������֡�\nϵͳ���ĸ����㣺Ҫ�����ˣ��Լ����ذɣ�\n");
    }
    log_file("static/CRASHES", MUD_NAME + " crashed on: " + ctime(time()) +
        ", error: " + error + "\n");
        if (command_giver){
        log_file("static/CRASHES",
            sprintf( "this_player: %s(%s),last commands:%s,%s\n", command_giver->name(1),command_giver->query("id"),command_giver->process_input("!0"),command_giver->process_input("!1")));
                    cmds = command_giver->query_commands();
        for(i = 0; i<sizeof(cmds); i++) {
                if( cmds[i][2]==command_giver ) continue;
                log_file("static/CRASHES",sprintf("%-15s  %2d %O\n", cmds[i][0], cmds[i][1], cmds[i][2]));
     }
        if (environment(command_giver))
                        log_file("static/CRASHES", sprintf( "in where: %s(%s),\n",environment(command_giver)->query("short"),base_name(environment(command_giver)) ));
      }
    if (current_object)
        log_file("static/CRASHES",
            sprintf( "this_object: %O\n", current_object));
}

protected string *update_file(string file)
{
    string *list;
    string str;
    int i;
    str = read_file(file);
    if (!str)
        return ({});
    list = explode(str, "\n");
    for (i = 0; i < sizeof(list); i++) {
        if (list[i][0] == '#') {
            list[i] = 0;
        }
    }
    return list;
}

string *epilog(int load_empty)
{
    string *items;
    items = update_file(CONFIG_DIR + "preload");
    return items;
}

void preload(string file)
{
    int t1;
    string err;
    if (file_size(file + ".c") == -1)
        return;
    t1 = time();
    write( "���� : " + file + " ��..." );
    err = catch(call_other(file, "??"));
    if (err)
        write( "\n���� " + file + " ʱ�������� : " + err + "\n" );
    else
        write(".... �ɹ�.\n");
        
}

void log_error(string file, string message)
{
    string name, home;
   
    if( find_object(SIMUL_EFUN_OB) )
        name = file_owner(file);
    if (name) home = user_path(name);
    else home = LOG_DIR;
    if(this_player(1)) efun::write("����ʱ�δ���" + message+"\n");
    
    efun::write_file(home + "log", message);
}

int save_ed_setup(object who, int code)
{
    string file;
  
    if (!intp(code))
        return 0;
    file = user_path(getuid(who)) + ".edrc";
    rm(file);
    return write_file(file, code + "");
}

int retrieve_ed_setup(object who)
{
   string file;
   int code;
  
    file = user_path(getuid(who)) + ".edrc";
    if (file_size(file) <= 0) {
        return 0;
    }
    sscanf(read_file(file), "%d", code);
    return code;
}

void destruct_env_of(object ob)
{
    if (!interactive(ob))
        return;
    tell_object(ob, "�������ڵĿռ䱻�����ˡ�\n");
    ob->move(VOID_OB);
}

string make_path_absolute(string file)
{
    file = resolve_path((string)this_player()->query("cwd"), file);
    return file;
}

string get_save_file_name(string fname)
{
    return fname + "." + time();
}
string get_root_uid()
{
   return ROOT_UID;
}
string get_bb_uid()
{
   return BACKBONE_UID;
}
string creator_file(string str)
{
    return (string)call_other(SIMUL_EFUN_OB, "creator_file", str);
}
string domain_file(string str)
{
    return (string)call_other(SIMUL_EFUN_OB, "domain_file", str);
}
string author_file(string str)
{
    return (string)call_other(SIMUL_EFUN_OB, "author_file", str);
}
string standard_trace(mapping error, int caught)
{
    int i, s;
    string res;


    res = (caught) ? "����ѶϢ������: " : "";
    res = sprintf("%s\nִ��ʱ�δ���%s\n��ʽ��%s �� %i ��\n���: %s\n",
        res, error["error"],
        error["program"], error["line"],
        objectp(error["object"])?file_name(error["object"]):"<none>");

    for (i=0, s = sizeof(error["trace"]); i < s; i++) {
                res = sprintf("%s�������ԣ�%s �� %s() �� %i �У������ %O���ط�:%s\n",
                        res,
                        error["trace"][i]["program"],
            error["trace"][i]["function"],
            error["trace"][i]["line"],
            error["trace"][i]["object"],
            environment(error["trace"][i]["object"])?base_name(environment(error["trace"][i]["object"])):"<none>");
    }
    return res;
}


int filter_wiz(object ppl)
{
   if (!environment(ppl)) return 0;
    if (member_array("debug", ppl->query("channels"))!=-1 )
        return wizardp(ppl);
}

string error_handler( mapping error, int caught )
{
    object *ob;
    if (this_player(1)) {
        this_player(1)->set_temp("error", error);
        if (wizardp(this_player(1)))
        tell_object(this_player(1), standard_trace(error, caught));
    }

    ob = filter_array( users(), "filter_wiz", this_object());
    message("channel:chat", WHT +"�������顿"+
        sprintf("ִ��ʱ�δ���%s��ʽ��%s �� %i ��\n"+NOR,
            error["error"],
            error["program"], error["line"]),ob);

    efun::write_file(LOG_DIR + "debug.log", standard_trace(error, caught));
    return "";
}

int valid_shadow( object ob ) { return 0; }

int valid_override( string file, string name )
{

    if (file == SIMUL_EFUN_OB || file==MASTER_OB)
        return 1;

    if(((name == "move_object") || (name == "destruct")) && (file != F_MOVE))
        return 0;

    return 1;
}

int valid_seteuid( object ob, string str )
{
    return (int)SECURITY_D->valid_seteuid( ob, str );
}

int valid_socket( object eff_user, string fun, mixed *info )
{
    return 1;
}

int valid_asm( string file )
{
    return 1;
}

int valid_compile_to_c( string file )
{
    return 1;
}

int valid_hide( object who )
{
    return 1;
}

int valid_object( object ob )
{
    return (!clonep(ob)) || inherits(F_MOVE, ob);
}

int valid_link( string original, string reference )
{
    return 0;
}

int valid_save_binary( string filename )
{
    return 1;
}

int valid_write( string file, mixed user, string func )
{
    object ob;
    if( ob = find_object(SECURITY_D) )
        return (int)SECURITY_D->valid_write(file, user, func);
    return 0;
}

int valid_read( string file, mixed user, string func )
{
    object ob;
    if (!undefinedp(user))
        if (!objectp(user=previous_object()))
        return 1;
    if( ob = find_object(SECURITY_D) )
        return (int)SECURITY_D->valid_read(file, user, func);
    return 1;
}
string object_name(object ob)
{
    if( ob ) return ob->name();
}
void create()
{
    write("master:  �ɹ�����.\n");
}
int valid_bind(object binder, object old_owner, object new_owner)
{
    if( userp(new_owner) ) return 0;
    if( geteuid(binder)==ROOT_UID ) return 1;
    if( clonep(new_owner) ) return 1;
    return 0;
}

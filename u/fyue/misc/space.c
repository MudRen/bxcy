inherit NPC;
#include <net/socket.h>
nosave int telnet_socket;
nosave mapping *rec=({
([    "name" : "�Ķȿռ�",
          "addr" : "172.28.29.119 8000",
      "language": "GB",
]),
([    "name" : "������һ��",
      "addr" : "202.101.104.7 5555",
      "language": "GB",
]),

([    "name" : "��������վ",
      "addr" : "fengyun.com 3333",
      "language": "GB",
]),
([    "name" : "�����½�վ",
      "addr" : "fengyun.xj.cninfo.net 3333",
      "language": "GB",
]),
([    "name" : "Ӣ�۴�˵",
      "addr" : "202.103.237.132 6666",
      "language": "GB",
]),
([    "name" : "��������",
      "addr" : "games.online.tj.cn 5555",
      "language": "GB",
]),
([    "name" : "�����˲�",
      "addr" : "202.130.251.3 8888",
      "language": "GB",
]),
([    "name" : "�����˲�(Big5)",
      "addr" : "202.130.251.3 8888",
      "language": "Big5",
]),
([    "name" : "X K X",
      "addr" : "202.96.242.19 5555",
      "language": "GB",
]),





});
nosave mapping con_to=([ ]);
nosave int in_putting = 0;
void close_callback(int s);
string process_input(string str);
void read_callback(int s, mixed message);
void write_callback(int s,string message);
void close_callback(int s);
void select_connect(string arg);
void begin();

void create()
{
    set_name("�����ռ�", ({ "space" }) );
    set("gender", "����" );
    set("long","һ���ڲ�����Ķ�����ǧ��Ҫ��(possess)��ȥ��\n");
    set("age", 29);
    set("attitude", "heroism");
    set("generation", 0);
    set("no_die",1);
    set("no_clean_up",1);
    setup();

}


int new_possess(string arg)
{
    object me=this_player();
    string money;
     if( this_object()->query_temp("body_ob") )
             return notify_fail( this_object()->name() + "�Ѿ����˸�����ˡ�\n");
    set_name(me->query("name"),({capitalize(me->query("id"))}) );
        if( geteuid(this_object()) != geteuid(me))
                seteuid(geteuid(me));
        message_vision("$N����һ����â����$n�������ڡ�\n", me, this_object());
        LOGIN_D->enter_world(me, this_object(), 1);
    call_out("begin",1);
    return 1;
}
void init()
{
   add_action("new_possess","possess");
}

void remove()
{
    close_callback(telnet_socket);
}

string process_input(string str)
{
    if (!in_putting) return ::process_input(str);
    if (str=="quit!")  return ::process_input("quit");
    if( stringp(str) ) {
         if( interactive(this_object()) ) {
             if (con_to["language"]=="Big5")
                 str = (string)LANGUAGE_D->GB2Big5(str);
         }
     }
     write_callback(telnet_socket,str);
         return "";
}

void read_callback(int s, mixed message)
{
     if (con_to["language"]=="Big5")
          message=(string)LANGUAGE_D->Big52GB(message);
     write(message);
}

void write_callback(int s,string message)
{
    int error;
    error = socket_write(telnet_socket, message+"\n");
    if (error < 0) {
        write("socket_write: " + socket_error(error) + "\n");
        close_callback(telnet_socket);
        call_out("begin",1);
        return;
    }
}

void close_callback(int s)
{
    write("��" + s + "�������ռ��Ѿ��رա�\n");
    socket_close(s);
    in_putting=0;
    call_out("begin",1);
}
void begin()
{
     int i;
     in_putting=0;
     for (i=0;i<sizeof(rec);i++)
        printf("\t %2d . %s %s\n",i,rec[i]["name"],rec[i]["addr"]);

     write("\n\tx . �˳� \n\n\t ��ѡ��:");
    input_to("select_connect");
}
void select_connect(string arg)
{
    int i,error;
    object link_ob=query_temp("body_ob");
    if (!arg 
    || sscanf(arg,"%d",i)!=1 ){
       if (arg=="x"){
            set_name("�����ռ�", ({ "space" }) );
            set("gender", "����" );
                        set("long","һ���ڲ�����Ķ�����ǧ��Ҫ��(possess)��ȥ��\n");
                        command("quit");
                        return;
                }
       begin();
       return;
    }
    if (i>=sizeof(rec)){ begin(); return; }
    con_to=rec[i];
    telnet_socket = socket_create(STREAM, "read_callback", "close_callback");
    if (telnet_socket < 0) {
       write("���������ռ䷢���鷳: " + socket_error(telnet_socket) + "\n");
       begin();
       return;
    }
    write("���������" + telnet_socket + "�������ռ�....\n");

    error = socket_connect(telnet_socket, con_to["addr"], "read_callback", "write_callback");
    if (error < 0 ) {
        write("һ�����ε�����: " + socket_error(error) + ",���㳶�˻���...\n");
        close_callback(telnet_socket);
        begin();
        return;
    }
    in_putting=1;    
}

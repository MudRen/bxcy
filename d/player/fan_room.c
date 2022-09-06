// ��
#define DOMAIN "/d/player/"
#define OUT "south"
#define ROAD "/d/player/seascape"

inherit ROOM;
inherit F_SAVE;
#include <room.h>
nosave string user_id;
nosave string fere;

string query_save_file()
{
        return ("/data/room/"+user_id+"/room.o");
}

void create()
{
      if (sscanf(__FILE__,DOMAIN + "%s_room.c",user_id)!=1)
      user_id="user id";
    if (!restore()){
        set("short", "��");
        set("long", "һ����ܰ�ļ�......\n\n\t�������short��longΪ�Լ��ļҴ�磬\n\tҲ��������(invited)�����˲ι����С�ݡ�\n");
        set("exits", ([
                OUT:ROAD,
                "north":__DIR__+user_id+"_sleep",
        ]));
        set("valid_startroom", 1);
        set("no_steal", 1);
        set("no_clean_up", 0);
      user_id="user id";
        set("fere","user fere");
    }
    fere=query("fere");
    setup();
}
void init()
{
      object me=this_player();
      if (!userp(me))  return;
      add_action("do_open","open");
      if (me->query("id")!=user_id )
      if (me->query("id")!=fere )
      if (me->query_temp("invited")!=user_id ){
           me->move(ROAD);
           return;
      }
      if (me->query("id")==user_id && stringp(query("marry"))){
            set("fere",fere);
            fere=query("marry");
            save();
      }
      add_action("do_invited","invited");
      add_action("do_long","long");
      add_action("do_short","short");
}
int do_invited(string arg)
{
     if (!arg) return notify_fail("��Ҫ����˭��\n");
     if (this_player()->id(arg) || arg==this_player()->query("marry"))
       return notify_fail("�裬�⻹�����룿\n");
     foreach (object player in users()){
          if (player->query("id")==arg && this_player()->visible(player) && environment(player)){
            write("����������"+player->name(1)+"�ι���ļң�\n");
            tell_object(player,BOLD+this_player()->name(1)+"�����㵽"+this_object()->query("short")+"���͡�\n"+NOR);
           player->set_temp("invited",user_id);
           return 1;
      }
    }
    return notify_fail("û����λ��ҡ�\n");
}

int do_open()
{
      object me=this_player();
       if (me->query("id")==user_id || me->query("id")==fere)
        return 0;
       else{
      write("��ô�������͵����ѽ��\n");
          return 1;
       }
}

int valid_leave(object me,string dir)
{
    if (!userp(me)) return 1;
    if (dir=="north" )
    if (me->query("id")!=user_id)
    if ( me->query("id")!=fere )
        return notify_fail("������ò�ò��ã���Ҫ���˼Ҽ����Ҵܣ�\n"); 
    if (dir==OUT)
        me->delete_temp("invited");
    return 1;
}
int do_long()
{
    string arg;
    arg="";
    write("ѶϢ�����кü��У������� . ��ʾ������\n");
    write("������������������������������������������������������������������������\n");
    input_to("get_long",arg);
    return 1;
}

int get_long(string msg,string arg)
{
    if( msg=="."){
        set("long", arg);
        write("�ϣˣ�");
        return 1;
    }
    arg+=msg+"\n";
    input_to("get_long",arg);
    return 1;
}

int do_short(string arg)
{
    if (!arg || arg=="")
         return notify_fail("�����ṩ���ݵļ������������: short �� \n");
    if (strlen(arg)<2 || strlen(arg)>30)
         return notify_fail("���ݵļ������������1��15�����֡�\n");
    set("short",arg);
    save();
    write("�ϣˣ�\n");
    return 1;
}


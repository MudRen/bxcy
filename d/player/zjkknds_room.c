inherit ROOM;
#include <room.h>
void create()
{
        set("short", "��������");
    set("long", @LONG
������һ��ӵ�����ٶ�̨����II�ĳ����ģ�����������ϵ������ϵ����Ϣϵ��Ӧ
��ϵ�ȸ�ϵ�������ǣ�������������������������������������ϯ��Ȼ����Ȼû��һ��
��PLAY MUD��ǽ������һ��ͨ�� (tonggao)���Աߵļ����ϰ���һ��С�ڰ�(board)��
LONG
    );
    set("exits", ([
    "south":"/d/city/mianju_r",

]));
    set("valid_startroom", 1);
    set("no_steal", "1");
    set("no_clean_up", 0);
    setup();
}
void init()
{
      object me=this_player();
       if (me->query("id")!="zjkknds" )
       if (me->query_temp("invited")!="zjkknds")
           me->move("/d/city/mianju_r");
       if (me->query("id")=="zjkknds")
          add_action("do_invited","invited");
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
           player->set_temp("invited","zjkknds");
           return 1;
      }
    }
    return notify_fail("û����λ��ҡ�\n");
}




#define PN1 "gott"
#define PN2 "gott wife"
#define OUT "northwest"

inherit ROOM;
#include <room.h>
void create()
{
        set("short", "СԺ��");
    set("long", @LONG
Ժ����ĺ������ѽ��������������,��˶˶�ʹ���,�������������,
���ٺ���һ�Զ԰�����,��ӨӨ����ĥ��,������,���ߴ�����Ҷ����,̻
̻ȻȻ��������,��ӯ�����ҡҷ��.ǣţ����¥�׾�ǿ����ǽ������,��¥
��׺��������,�Ϻ�ɫ�ױߵĴ�仨��,���¼���ݻ���ʱ�����컶�е���
��,���Ҷ��,�·�Ҫ������Ժ������������¥��ȥ.����Ժ�ŵ��ǿøߴ��
�޻���,�޻�����һƬƬ����,���ڿ�ȸ��һ���̸��ŵ���Ҷ��.
LONG
    );
    set("exits", ([
    OUT:"/d/quanzhou/yucun",
    "north":__DIR__+PN1+"_sleep",
]));
    set("valid_startroom", 1);
    set("no_steal", 1);
    set("no_clean_up", 0);
        create_door("north", "С����", "south", DOOR_CLOSED);
    setup();
}
void init()
{
      object me=this_player();
      if (!userp(me))  return;
       add_action("do_open","open");
       if (me->query("id")!=PN1 )
       if (me->query("id")!=PN2 )
       if (me->query_temp("invited")!=PN1 )
           me->move("/d/quanzhou/yucun");
       if (me->query("id")==PN1 || me->query("id")==PN2)
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
           player->set_temp("invited",PN1);
           return 1;
      }
    }
    return notify_fail("û����λ��ҡ�\n");
}

int do_open()
{
      object me=this_player();
       if (me->query("id")==PN1 || me->query("id")==PN2)
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
    if (me->query("id")!=PN1)
    if ( me->query("id")!=PN2 )
        return notify_fail("������ò�ò��ã���Ҫ���˼Ҽ����Ҵܣ�\n"); 
    if (dir==OUT)
        me->delete_temp("invited");
    return 1;
}


inherit ROOM;
#include <room.h>
void create()
{
        set("short", "名捕机房");
    set("long", @LONG
这里是一个拥有两百多台奔腾II的超大规模机房。计算机系、电信系、信息系、应
科系等各系的网虫们，都经常聚在这里泡网。今天屋里又座无虚席，然而竟然没有一个
人PLAY MUD。墙上贴着一份通告 (tonggao)，旁边的架子上摆着一块小黑板(board)。
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
     if (!arg) return notify_fail("你要邀请谁？\n");
     if (this_player()->id(arg) || arg==this_player()->query("marry"))
       return notify_fail("昏，这还用邀请？\n");
     foreach (object player in users()){
          if (player->query("id")==arg && this_player()->visible(player) && environment(player)){
            write("你现在邀请"+player->name(1)+"参观你的家！\n");
            tell_object(player,BOLD+this_player()->name(1)+"邀请你到"+this_object()->query("short")+"作客。\n"+NOR);
           player->set_temp("invited","zjkknds");
           return 1;
      }
    }
    return notify_fail("没有这位玩家。\n");
}




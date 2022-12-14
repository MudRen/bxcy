#define PN1 "sgsy"
#define OUT "west"

inherit ROOM;
#include <room.h>
void create()
{
        set("short", "思思的闺房");
    set("long", @LONG
人说大树底下好乘凉，没想到大树上更凉快。这棵大榕树真不愧为千年神木，
至今仍绿叶繁茂。据说这里的时间是冻结的，因此便成为许多玩家聊天的地方。
这里摆着几张用榕树根做的椅子，中间用几根榕树枝搭在一起，算是一个茶几了。
当你抬头往上看的时候似乎有个影在树梢之间移动，不过也许是风吹动所造成的
错觉。
LONG
    );
    set("exits", ([
    OUT:"/d/quanzhou/yucun1",
    "north":"/d/player/sgsy_sleep",
]));
    set("valid_startroom", 1);
    set("no_steal", 1);
    set("no_clean_up", 0);
        create_door("north", "小竹门", "south", DOOR_CLOSED);
    setup();
}
void init()
{
      object me=this_player();
      if (!userp(me))  return;
       add_action("do_open","open");
       if (me->query("id")!=PN1 )
       if (me->query_temp("invited")!=PN1 )
           me->move("/d/quanzhou/yucun");
       if (me->query("id")==PN1)
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
           player->set_temp("invited",PN1);
           return 1;
      }
    }
    return notify_fail("没有这位玩家。\n");
}

int do_open()
{
      object me=this_player();
       if (me->query("id")==PN1)
        return 0;
       else{
      write("怎么？想进房偷东西呀？\n");
          return 1;
       }
}

int valid_leave(object me,string dir)
{
    if (!userp(me)) return 1;
    if (dir=="north" )
    if (me->query("id")!=PN1)
        return notify_fail("讲点礼貌好不好，不要在人家家里乱窜！\n"); 
    if (dir==OUT)
        me->delete_temp("invited");
    return 1;
}


#define PN1 "robber"
#define PN2 "robber wife"
#define OUT "south"

inherit ROOM;
#include <room.h>
void create()
{
        set("short", "空");
    set("long", @LONG
空！这是一间空房间！请不要进来哦！
LONG
    );
    set("exits", ([
    OUT:"/d/quanzhou/yucun1",
    "north":__DIR__+PN1+"_sleep",
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
       if (me->query("id")!=PN2 )
       if (me->query_temp("invited")!=PN1 )
           me->move("/d/quanzhou/yucun");
       if (me->query("id")==PN1 || me->query("id")==PN2)
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
       if (me->query("id")==PN1 || me->query("id")==PN2)
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
    if ( me->query("id")!=PN2 )
        return notify_fail("讲点礼貌好不好，不要在人家家里乱窜！\n"); 
    if (dir==OUT)
        me->delete_temp("invited");
    return 1;
}


#define PN1 "fyue"
#define PN2 "ping"
#define OUT "east"

inherit ROOM;
#include <room.h>
#include <ansi.h>
void create()
{
        set("short", HIW"怜月居"NOR);
    set("long", 
这是一间十分简陋，四壁透风的民房，房子里最看的上眼的是那张+"MAG"大床"NOR"+，床上	
铺的是高级"HIR"拉舍尔毛毯"NOR"，一尘不染，给人一种遥遥欲睡的感觉，看来价值连城，与
房的其它家具格格不入，看来房的主人只要睡的好就心满意足了，因为主人很穷，
所以主人从不招待客人，只是与他的老婆过着日出而作，日落而息的隐居生活，你
被他们的平静生活感动了。
    );
    set("exits", ([
    OUT:"/d/city/yaopu",
    "north":__DIR__+PN1+"_sleep",
    "west":__DIR__+PN1+"_room2",
]));
    set("valid_startroom", 1);
    set("no_steal", 1);
    set("no_clean_up", 0);
        create_door("north", HIG"小竹门"NOR, "south", DOOR_CLOSED);
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
      write(HIM"怎么？想进房偷东西呀？\n"NOR);
          return 1;
       }
}

int valid_leave(object me,string dir)
{
    if (!userp(me)) return 1;
    if (dir=="north" )
    if (me->query("id")!=PN1)
    if ( me->query("id")!=PN2 )
        return notify_fail(HIY"讲点礼貌好不好，不要在人家家里乱窜！\n"NOR); 
    if (dir==OUT)
        me->delete_temp("invited");
    return 1;
}


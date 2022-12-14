#define PN1 "gott"
#define PN2 "gott wife"
#define OUT "northwest"

inherit ROOM;
#include <room.h>
void create()
{
        set("short", "小院子");
    set("long", @LONG
院子里的红枣树已结下了青青的枣子,肥硕硕低垂着,海棠树花落果生,
并蒂海棠一对对白生生,绿莹莹地厮磨着,依偎着,羞羞答答躲在叶子下,袒
袒然然在阳光里,轻盈安详地摇曳着.牵牛花从楼底倔强地沿墙爬上来,把楼
窗缀得绿油油,紫红色白边的大朵花儿,像新嫁娘拜花烛时那仰天欢叫的唢
呐,伸出叶子,仿佛要把那满院的清气都吹进楼里去.紧靠院门的那棵高大的
绒花树,绒花开成一片片红云,浮在孔雀翎一般铺盖着的绿叶上.
LONG
    );
    set("exits", ([
    OUT:"/d/quanzhou/yucun",
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


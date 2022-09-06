// jianzhong.c

inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIW"剑冢"NOR);
    set("long", @LONG
搬开冢上石块，露出并列著的三柄长剑。在第一、第二两把剑之间，另有
一块长条石片。三柄剑和石片并列於一块大青石之上。  
LONG
        );   

    setup();
}

void init()
{
        add_action("do_ti", "ti");
        add_action("do_tui", "tui");               
}

int do_ti(string arg)
{
        object me,sword;
        me = this_player();
//      sword = unew("/clone/weapon/xuantiejian");
        if (!arg ) return 0;         
        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着哪！\n");
        if ( arg == "gangjian" ){
           if (me->query_temp("sword"))
           return notify_fail("你已经看过第一把剑了啊。\n"); 
           message_vision(HIY"$N提起右首第一柄剑，只见剑下的石上刻有两行小字：「凌厉刚猛，无坚不
摧，弱冠前以之与河朔群雄争锋。」\n"NOR,me); 
           me->set_temp("sword",1);
           return 1;
           }
         else
        if ( arg == "xuantiejian" ){
           if (!me->query_temp("sword"))
             return notify_fail("什么？\n");
           if (me->query_str() < 30 )
             return notify_fail("你用力想提起玄铁剑，但力不从心。\n");                  
if (me->query("max_neili") < 30000 ){                          	
               message_vision(HIY"$N再伸手去提第二柄剑，只提起数尺，呛啷一声，竟然脱手掉下，在石上一
碰，火花四溅，不禁吓了你一跳。\n"NOR,me);
//  48                 me->set_temp("sword1",1);	
               me->add("neili",-300);
return 1;
               }
//  52  if (!me->query_temp("sword1"))          	
//  53                 return notify_fail("你想提起什么？\n");	
               me->add("neili",-300);
               me->delete_temp("sword");
               me->delete_temp("sword1");
               me->set_temp("sword2",1);
               sword= new("/d/gumu/obj/xuantiejian");
               if(!clonep(sword))
//               if (!query_temp("jian_get") && !present("xuantie jian", me)) 
               return notify_fail(HIR"你来晚了，玄铁剑已经给人取走了。\n"NOR);            
               sword->move(me);
               me->set_temp("jian_get",1);
               message_vision(HIY"於是$N再俯提起，这次有了防备，提起七八十斤的重物自是不当一回事。见那
剑两边剑锋都是钝口，剑尖更圆圆的似是个半球。看剑下的石刻时，见两行小
字道：「重剑无锋，大巧不工。四十岁前恃之横行天下。」\n"NOR,me);                 
               return 1;
              } else
           if( arg == "mujian") {
             if ( !me->query_temp("sword2"))
                return notify_fail("你想提起什么？\n");
                message_vision(HIY"$N力运左臂去取第三柄剑。那知拿在手中却轻飘飘的浑似无物，凝神一看，原
来是柄木剑，年深日久，剑身剑柄均已腐朽，但见剑下的石刻道：「四十岁後，
不滞於物，草木竹石均可为剑。自此精修，渐进於无剑胜有剑之境。」\n"NOR,me);
                me->delete_temp("sword2");
                return 1;
              }
}

int do_tui(string arg)
{
           object me;
           me = this_player();
           if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着哪！\n");
           if ( !arg || arg !="shi" )
                return notify_fail("你要推什么？\n");
           if (arg =="shi")
           message_vision(YEL"$N深深地吸了口气，缓缓推动青石。\n\n"NOR,me);
           write(HIG"你把青石推开！露出了剑冢的出口。\n"NOR);
           set("exits/out", __DIR__"pingtai");
           remove_call_out("close");
           call_out("close", 5, this_object());
           return 1; 
}      

void close(object room)
{
        message("vision",HIY"青石慢慢移回了原位，又挡住了出口。\n"NOR, room);
        room->delete("exits/out");
}


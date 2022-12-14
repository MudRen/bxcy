// Room: /u/xdd/gumu/shengou.c
// Modify By csy 98/12
#include <ansi.h>
int get_object(object ob);
inherit ROOM;

void create()
{
     set("short", HIG"深沟"NOR);
     set("long", @LONG
匆匆地穿过树林，眼前出现一道深沟(gou)，不知是深谷还是山溪的所在，
此外已无去路。低头一看，地下立著一块石碑(shibei)。
LONG      
     );

     set("exits", ([
            "west" : __DIR__"shulin2",
        ]));    

        set("objects",([
                    __DIR__"npc/sun" : 1,
        ]));

     set("item_desc", ([
         "gou" : HIC"深沟里烟雾弥漫，隐约中寒气凛人，间或似乎传来飘渺人声，真是世外高人超
然凡尘的好所在，你悠然神往，不自禁产生一种跃身跳(tiao)下的冲动。\n"NOR,
         "shibei" : HIR"\t\t终南活死人墓，外人莫入！\n"NOR,
          ]));

     set("outdoors", "古墓");

     setup();
}
   
void init()
{
       add_action("do_jump", "tiao");
}

int get_object(object ob)
{
        if(userp(ob))
        return 1;
        return 0;
}

int do_jump(string arg,object *obj)
{ 
        mapping fam;
        object me = this_player();
        object *inv = deep_inventory(me);        
       if ( !living(me) ) return 0; 
       if ( arg =="gou"){  
       if ((fam = me->query("family")) && fam["family_name"] == "全真教"){
          write(HIR"祖师遗训你忘了吗？！\n"NOR);
          me->unconcious();
          me->move("/d/quanzhen/leizudian");
          return 1;
          }
        if ((fam = me->query("family")) && fam["family_name"] != "古墓派")
          return notify_fail(HIR"\t\t古墓重地，闲人莫入！\n"NOR);
        if (me->query("gender") == "无性"){
          write(HIR"你这种不男不女的东西还想进古墓？\n"NOR);
          me->unconcious();
          me->move(__DIR__"lyy");
          return 1;
          }
     if ((int)me->query("per") < 23)
          return notify_fail(HIR"你天生容貌欠佳, 恐怕今生难圆双剑合壁之美梦。\n"NOR);
              if ((int)me->query_int() < 21)
          return notify_fail(HIR"你悟性欠佳, 恐怕今生难圆双剑合壁之美梦。\n"NOR);
        if (me->query_skill("literate", 1) < 30)
          return notify_fail(HIR"你的读书写字太低，入古墓无法领悟。\n"NOR);
if (me->query_dex() < 18 )
          return notify_fail(HIR"你身法太低，可能学不了古墓飘零的功夫。\n"NOR);
//      if (((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 25)){
        obj = filter_array(inv,(:get_object:));
        if(sizeof(obj)){
         write (HIR"你刚想偷偷背个人进去，结果负重太多，脚下一个绊拴，摔倒在地。\n"NOR);
         me->unconcious();
         me->move(__DIR__"shengou");
         return 1;
         }
        message("vision", me->name() + "处惊不乱，微一提气，凭空纵高丈余，衣诀飘飘，身姿潇洒地着落在山谷中。\n",
               environment(me), ({me})); 
        me->move(__DIR__"rukou");
        message_vision(HIY"$N纵身跳下深沟，拿捏恰到好处，正好落在古墓入口前。\n"NOR, me);
        return 1;
        }
       return notify_fail("你往哪里跳？\n");
}


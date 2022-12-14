// Room: /u/xdd/gumu/gmhout.c
// modified by snow@jhfy
// Modify By csy 98/12/29
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
          set("short", HIG"后堂"NOR);
          set("long", @LONG
堂上也是空荡荡的没什么摆设，正前方写着一行大字（zi），东西两壁都
挂着一幅画。西首 (westpic)的画像是两个女郎，正是古墓派的师尊林朝英和
师祖婆婆的肖像，东侧（eastpic）画像中却是一个道士。 
LONG        );

          set("exits", ([
                        "east" : __DIR__"gmqs",
                        "west" : __DIR__"gmzt",
                        "north" : __DIR__"gmws1",
                        "south" : __DIR__"gmws",
          ]));

         set("objects",([
                 __DIR__"npc/xln" : 1,
                 __DIR__"npc/yang" : 1,
         ]));
          set("item_desc", ([
               "westpic" : HIM"画中两个姑娘，一个二十五六岁，正在对镜梳妆，画中镜里映出女郎容貌极美，
秀眉入鬓，眼角却隐隐带着一层杀气，正是古墓派师尊林朝英。另一个是十五
六岁的丫鬟，手持面盆，在旁伺候，憨态可掬，满脸稚气，后来便成了小龙女
的师傅。\n"NOR,
               "eastpic" : HIC"像中道人身材甚高，腰悬长剑，右手食指指着东北角，只是背脊向外，面貌却
看不见。\n"NOR,
               "zi" : HIR"\t入我古墓，先唾重阳，欲成神功，拜我祖师。\n"NOR,
          ]));

          create_door("south", "石门","north", DOOR_CLOSED);
          setup();
}

void init()
{ 
         add_action("do_ketou", "ketou"); 
         add_action("do_tuo", "tuo");
}
 
int do_ketou(string arg)
{
          mapping fam;
          object me = this_player();

        if ((!arg) || (arg != "westpic")) return 0;
          message_vision("$N向西跪倒，双膝及地，恭恭敬敬向祖师婆婆的画像磕了一个响头. \n", me);
          me->add_temp("marks/ketou", 1);
if (me->query_temp("marks/tuo") == 2 && me->query_temp("marks/ketou") == 4	&& !me->query("family")
&& (!(fam = me->query("family")) || fam["family_name"] != "古墓派") ){	
          me->set("family_name", "古墓派");
          me->set("title", HIW"古墓传人"NOR);
          me->create_family("古墓派", 5, "传人");
          me->set("class","swordsman");
          write(HIR"恭喜你自愿成为一名古墓弟子。\n"NOR);
          me->delete_temp("marks/tuo");
          me->delete_temp("marks/ketou");
          return 1;
          }
        if (me->query_temp("marks/ketou") == 15 ){
          me->delete_temp("marks/ketou");
         if (me->query_temp("marks/goldkey"))
            return notify_fail("地上露出一方小孔,但里面空空如也,想必有人先你下手了. \n");
          message_vision(HIY"$N面前的石地突然下沉,露出一把金钥匙,$N得到一把金钥匙. \n"NOR, me);
          me->set_temp("marks/goldkey");
          new(__DIR__"obj/goldkey")->move(me);
          }
     return 1;
}

int do_tuo(string arg)
{
           object me = this_player();
           if (me->query_temp("marks/tuo") == 2)
             return notify_fail("你唾够了没有？\n");
           if ( arg=="eastpic"){
           message_vision("$N朝王重阳的画像狠狠唾了一口. \n", me);
           me->add_temp("marks/tuo", 1);
           return 1;
           }
          return notify_fail("你不要随便乱唾口水啊！\n");
}



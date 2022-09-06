//danfang.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "练丹房");
        set("long", @LONG
这里是间药香弥漫的大屋，屋四周堆满了各式各样的草药，房子中间
放着一炼丹制药的铜鼎(tongding)。因为炼丹的缘故，这屋子四季如春！
一位明教弟子正靠在墙脚打瞌睡。
LONG
        );
        set("exits", ([
 "west" : __DIR__"yaofang1",
        ]));

        set("objects",([
                __DIR__"npc/mingjiaodizi" : 1,

        ]));
        

        set("item_desc", ([
                "tongding" :
"    这是由青铜铸成的炼丹铜鼎，重约二百多斤，鼎身纹有九龙戏珠
的图案。鼎内火势正旺，正是炼丹的紧要关头! 为了保持火势，必须不
停地向鼎口扇(shan)风。\n",
        ]));
        
        setup();
}

void init()
{
        add_action("do_shan", "shan");
}

int do_shan(string arg)
{
        object me;
        int i, costj, costq;

        me = this_player();


        if ( !living(me)) return notify_fail("你发疯了? \n");

        if ( !arg || arg != "tongding" )
            {    message_vision("$N摆了摆手,象是在扇凉!\n",me);
                 return 1;
             }
        if ((int)me->query_skill("taoism", 1) < 30) 
               return notify_fail("弟子喝道：你与道教并无瓜葛，非我门中之人，不必白费力气!\n");
        costj = 1500 / (int)me->query("con");
        costj = random(costj);
        costq = 2000 / (int)me->query("str");
        costq = random(costq);

        if ((int)me->query("jingli") < costj || (int)me->query("qi") < costq){
        message_vision("$N用力过猛, 一不留神头嗑到香炉上!\n",me);
        me->unconcious();return 1;}
        
	me->add("jing", -costj);
        me->add("qi", -costq);       

        message_vision("$N用力呼哧呼哧地扇着火。\n", me);

        if ( (int)me->query_skill("strike", 1) < 31)
                {
                        write(HIY"你手臂来回用力，进退之中似乎对基本掌法有些领悟。\n"NOR);
                        me->improve_skill("strike", (int)(me->query("int") / 8));
                }
        i = (int)me->query("int") * (int)me->query("str") / 4;
        i = i + (int)me->query("kar") / 3 - 20;
        if ( random(i) > 95 )
                {
                        write(HIY"恭喜! 你终于练出一延年聚精丹!\n"NOR);
                        me->add("combat_exp", (int)(me->query("int") / 10));
                      }
        if ( random(i) > 100 )
                {
                        write(HIY"恭喜! 你终于练出一九转结气丸!\n"NOR);
                        me->add("combat_exp", (int)(me->query("int") / 10));
                      }

        return 1;
}


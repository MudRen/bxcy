// Room: shandao1.c


#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "断崖");

        set("long", @LONG
天色昏暗，山道两旁的大树垂下沉沉的枝叶，在昏暗的光线中更加
显得狰狞可怕，你走到这儿，只觉得凉气逼人，一股冷汗油然而生，不
由得打量起来，发现草丛中有好几条古藤(teng)，原来这里就是明教的
东边的最远处--断崖。

LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"shandao0",
]));

        set("no_clean_up", 0);
        set("item_desc", ([
                "teng": "这是一根老山藤。\n"
                ]) );

        setup();
}
void init()
{
        add_action("do_hua", "hua");
}
int do_hua(string arg)
{
        object me=this_player();

        if( !arg || arg=="" ) {write("你要滑什么？\n");return 1;}
if (me->is_busy())
return notify_fail("你上一个动作还没有完成！\n");

        if( arg=="teng" ) {
                write("你顺着山藤，飞快地向下滑去....\n");
if((int)me->query_skill("dodge",1)>=40)
                {write("爬呀爬呀，爬呀爬呀，你终于滑到了谷底。\n");
                me->move(__DIR__"gudi");         

                 return 1;}
                write(RED"突然间，你一不留意，就跌了下去。\n"NOR);

                me->add("jing",-40);
                me->add("qi",-40);
                me->improve_skill("dodge", random(100));
                me->unconcious();

                return 1;

                 }
}


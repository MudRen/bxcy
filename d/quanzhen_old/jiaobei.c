// jiaobei.c 教碑
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "教碑");
        set("long", @LONG
这里是全真教的教碑所在地，路旁立着一块大碑(bei)。再往东
走就是天下闻名的道家玄门正宗--全真教的大门了。北面有一条石
阶，不知道通向哪里，往西是下山的路。
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "northup" : __DIR__"shijie6",
                "eastup" : __DIR__"damen",
                "west" : __DIR__"shijianyan",
        ]));
        set("item_desc", ([
        "bei": CYN"
        ＊＊＊＊＊
　　　　＊　　　＊
　　　　＊　全　＊
　　　　＊　　　＊
　　　　＊　真　＊
　　　　＊　　　＊
　　　　＊　古　＊
　　　　＊　　　＊
　　　　＊　教　＊
　　　　＊　　　＊
　　　　＊＊＊＊＊
\n"NOR
        ]) );
        set("objects",([
//                __DIR__"npc/zhao" : 1,
        ]));

        setup();
        replace_program(ROOM);
}

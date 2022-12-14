//bye enter

#include <room.h>
#include <ansi.h>

inherit ROOM;
int do_jump(string arg);

void create()
{
    set("short", "小亭");
    set("long", @LONG
你正站在湖边的一个小亭里，通过一条曲折迂回的走廊可以
回到大厅。小亭修筑得相当雅致，在这里可以欣赏湖中的荷花和
锦鲤，亭子北面湖中竖着几根木桩，湖心有个小岛，朦胧间看得
却是不太真切。
LONG
    );

    set("exits", ([
        "south" : __DIR__"zoulang4",
    ]));

    set("item_desc", ([
        "木桩" : "这是几根分布得怪里怪气的木桩，看上去不是很结实。"
    ]) );
    setup();
}

void init()
{
    object book, me;
    me = this_player();
    add_action("do_jump", "jump");
}



int do_jump(string arg)
{
    int n;
    n = this_player()->query_skill("dodge");
    if( !arg || arg!="木桩" ) {
        write("不要乱跳，现在是冬天，可不是能游泳的季节哦！\n");
        return 1;
    }


    message_vision(
    "$N深深地吸了口气，猛地跃了起来。\n", this_player());
        
    if (n>=100) {
        message_vision(
        "只见$N轻轻一跃，稳稳地站在湖中的木桩上，几下起落，已经到达了湖中小岛。\n", this_player());
        this_player()->move(__DIR__"xiaodao");
    }
    else {
        message_vision(
        "$N高高跃起,重重地落在木桩上，结果把木桩踩断了！“扑通”一声掉进水中。\n", this_player());
        this_player()->move(__DIR__"huli");
     }
    return 1;
}



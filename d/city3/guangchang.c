//by zhm@silversand_mud
inherit ROOM;

void create()
{
        set("short", "天府广场");
        set("long", @LONG
这里是成都的中心，占地约三亩，绿色的草坪就象一块大
的地毯，东西各有一棵老榕树，已有上百岁了，看看它们，就
知道成都的历史是相当悠久的。这里来往的人很多，熙熙攘攘，
摩肩接踵，有游客、卖艺人、闲人、小贩、商人，吵闹和吆喝
声不绝于耳，好一派热闹繁华的景象,中央有一棵大杉树，盘根
错节，据传已有千年的树龄，。
LONG
        );

        set("item_desc", ([
        "杉树"  :   "一棵枝叶茂盛的大杉树，看来似乎可以爬(climb)上去。\n",
        "大杉树":   "一棵枝叶茂盛的大杉树，看来似乎可以爬(climb)上去。\n",
        "树"    :   "一棵枝叶茂盛的大杉树，看来似乎可以爬(climb)上去。\n",
        "tree"  :   "一棵枝叶茂盛的大杉树，看来似乎可以爬(climb)上去。\n",
        ]));

        set("exits", ([
                "north" : __DIR__"beijie2",
                "south" : __DIR__"nanjie1",
                "west" : __DIR__"xijie2",
                "east" : __DIR__"dongjie1",                
        ]));
        set("outdoors","chengdu");
        set("objects",([
                  __DIR__"npc/xiaolanyan" : 3,
//"/d/npc/shandian" : 1,   
                  __DIR__"npc/laolanyan" : 1,
           ]));
      
        setup();
}

void init()
{
    add_action("do_climb", "climb");
}
 
int do_climb(string arg)
{
    object me;
    mixed *local;
    local=localtime(time());
/*    if (local[6]==0 )
    return notify_fail("树干上布满了青苔,看样子是没法爬上的!\n"); */
    me = this_player();
        if( !arg || arg!="up") return notify_fail("你要往哪个方向爬？\n");
    if(me->query_condition("killer"))
    {
    message("vision",
        me->name() + "战战兢兢地拉着大杉树的盘根，屁股一扭一扭地往上爬，结果惨叫一声，摔了下来。\n",
        environment(me), ({me}) );
     write("你战战兢兢地拉着大杉树的盘根往上爬，结果一不小心摔了个狗吃屎。\n");
     return 1;
     }
    message("vision",
        me->name() + "战战兢兢地拉着大杉树的盘根，屁股一扭一扭地往上爬。\n",
        environment(me), ({me}) );
        me->move("/d/city3/chatroom1.c");
        message("vision",
        me->name() + "气喘嘘嘘地爬了上来。\n",
                environment(me), ({me}) );
    return 1;
}   


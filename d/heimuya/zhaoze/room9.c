// Room: room9.c
inherit ROOM;
int do_climb(string arg);
int do_tiao(string arg);
void create()
{
        set("short", "茅屋");
        set("long", @LONG
越墙而入，原来墙里是个院子，分为两半，左一半是实土，右一
半却是水塘。跨过院子，走向内堂，堂前是个月洞，但无门扉。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"room10",
]));

    set("item_desc", ([
        "wall" : "墙很高，可能翻不过去(climb)。\n",
          "墙" : "墙很高，可能翻不过去(climb)。\n",
        "水塘" : "一个水塘，好象可以跳下去！\n",
    ]) );

        setup();
}
void init()
{
    object book, me;
    me = this_player();
    add_action("do_climb", "climb");
    add_action("do_tiao", "tiao");
}
int do_climb(string arg)
{
    int n;
    n = this_player()->query_skill("dodge",1);
    if( !arg || arg!="wall" ) {
        write("不要到处乱爬！\n");
        return 1;
    }
    message_vision(
    "$N在墙前站定,深吸一口气，猛然跃起.\n", this_player());
        
    if (n>=1000) {
        message_vision(
        "只见$N足尖在墙上一点,已悠然飘落围墙外。\n", this_player());
        this_player()->move(__DIR__"room8");
    }
    else if (n>=800) {
        message_vision(
        "只见$N双手在墙上一攀,勉强翻过围墙,跌落围墙外。\n", this_player());
        this_player()->move(__DIR__"room8");
    }
    else {
        message_vision(
        "$N高高跃起,可还差一大截呢,看来是轻功不够好。\n", this_player());
     }
    return 1;
}

int do_tiao(string arg)
{
        object me,room;
        me = this_player();
        if( !arg || arg!="水") return notify_fail("你要往哪跳？\n");          
        message_vision("$N犹豫了一下，鼓气了勇气，高高跃起，在空中划了条美妙的弧线，\n"
                       "跳入水中。\n",me);
        if (!room=find_object(__DIR__"shx"))
             room=load_object(__DIR__"shx");
        me->move(room);
        return 1;
}

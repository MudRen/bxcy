// Room: /u/mei/room40.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void init();
int do_out();
void create()
{
        set("short", "翡翠池");
        set("long", @LONG
这里四周群山围绕，就如一只大盆一般，盆子中心碧水莹然，绿若翡翠，是
个圆形的池子，隔了这千百年，竟然并不干枯，想来池底另有活水源头。走近池
边，伸下手去，只觉清凉入骨，双手捧起水来，但见澄净清澈，更无纤毫苔泥，
原来圆池四周都是翡翠，池水才映成绿色。只见洁白的玉峰映在碧绿的池中，白
中泛绿，绿中泛白，明艳洁净，幽绝清绝。
LONG
        );
        set("resource/water", 1);
        set("item_desc", ([
                "圆池" : "如果有容器，可以盛(fill)点清凉的池水。\n",
              "翡翠池" : "看来可以下(out)池洗澡耶！\n",
        ]));

        set("exits", ([ 
        "up" : __DIR__"room39",
]));
        set("outdoors", "room40");

        setup();
}
void init()
{
    add_action("do_out","out");
}
int do_out()
{
    object me = this_player();
    message_vision("$N四周看了一眼，“咚”的一声，跳入池中。\n", me);
    me->move(__DIR__"room69");
    return 1;
}

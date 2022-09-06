// Room: /u/mei/zhaoze/pubu.c
inherit ROOM;
void create()
{
        set("short", "无量山界");
        set("long", @LONG
猛听得水声响亮，轰轰隆隆，便如潮水大至一般，抬头一看，只见
西北角上犹如银河倒悬，一条大瀑布从高崖上直泻下来，只见深谷中云
雾弥漫，兀自不见尽头。
LONG
);
        set("outdoors", "pubu");
        set("exits", ([
  "southdown" : __DIR__"xiaodao",
  "westdown" : __DIR__"lczb",
  "northup" : __DIR__"lingding",
]));

        setup();
}

void init()
{
     object me;
     me = this_player();
     if( random((int)me->query_kar()) > 20 ){
     call_out("close_door",10,me);
     }
}

void close_door(object me)
{
        object room;
        if (!me || environment(me)!=this_object()) return;
        room=find_object(__DIR__"xiaoyao/pubu");
        if (!room)
        room = load_object(__DIR__"xiaoyao/pubu");
        message_vision("突然$N脚下踏了个空，身子登时堕下了去。\n",me);
        me->move(__DIR__"xiaoyao/pubu");
        message_vision("砰！$N掉了下来。\n",me);
}

// Room: /u/mei/room38.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
#include <room.h>
void init();
int do_pull(string arg);
int do_climb(string);
int do_move(string);
void create()
{
    set("short", "石室");
    set("long", @LONG
眼前突然大亮，只见一道阳光从上面数十丈高处的壁缝里照射进来。阳光照
正之处，是一间玉室，看来当年建造者依着这道天然光线，在峰中度准位置，开
凿而成。石室中有玉床、玉桌、玉椅，都雕刻得甚是精致，床上斜倚着一具骸骨。
石室一角，又有一大一小的两具骸骨。
LONG
    );
        set("objects", ([ 
  __DIR__"obj/skeleton" : 3,
]));
    set("exits", ([ 
       "east" : __DIR__"room37",

    ]));

    set("item_desc", ([
        "玉桌" : 
"    圆桌是整块从玉石中雕刻出来的，连在地上，圆桌桌面刻的是一群背上生
翅的飞骆驼，花纹极细，刻工甚是精致，然而骆驼的头和身子却并不连在一起，
各自离开了一尺多位置。\n", 
        "玉床" :
"    一张玉石雕刻出来的床。\n",    
])); 

    create_door("east", "小石门", "west", DOOR_CLOSED);
    setup();
}
void init()
{
    add_action("do_climb","climb");
    add_action("do_move","move");
}

int do_climb(string arg)
{
    if ( !arg || arg!="玉床" )
        return notify_fail("你要爬上那里？\n");
    if (this_player()->query_temp("marks/爬1"))
        return notify_fail("你已经在玉床上了。\n");

    message_vision("$N爬上了玉床。\n",this_player());
    this_player()->set_temp("marks/爬1", 1);
        return 1;
}
int do_move(string arg)
{
        object me;
        object room;
        me = this_player();
    if (!arg || arg !="玉桌"){
        write("你要移动什么？\n");
        return 1;
    }
    if (!me->query_temp("marks/爬1") ){
        write("你要移动什么？\n");
        return 1;
    }

    if (!( room = find_object(__DIR__"room39")) )
            room = load_object(__DIR__"room39");
    this_player()->delete_temp("marks/爬1");
    if (!query("exits/enter")){
            set("exits/enter", __DIR__"room39");
            message_vision("$N把圆桌边沿缓缓拉动，使桌面刻的骆驼的头和身子连在一起，玉床上露出一个洞口。\n",me);
            room -> set("exits/out", __FILE__);
            message("vision", "外面传来一阵移动石门的隆隆的响声。\n",room);
            call_out("close_door",10);
            return 1;
    }
        write("你要移动什么？\n");
        return 1;
}
void close_door()
{
        object room=find_object(__DIR__"room39");
        if (!room)
        room = load_object(__DIR__"room39");
        delete("exits/enter");
        message("vision","玉桌边沿轰隆一声移回了原处，洞口又被封住了。\n",this_object());
        room -> delete("exits/out");
        message("vision","外面传来一声巨响，洞口被封住了。\n", room);
}

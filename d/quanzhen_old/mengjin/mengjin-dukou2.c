#define OTHER_ROOM __DIR__"mengjin-dukou1.c"
#define DUCHUAN __DIR__"duchuan.c"

inherit ROOM;
int check_trigger();
void on_board();
void arrive();
void close_passage();
void reset();
void create()
{
    set("short", "孟津北渡口");
    set("long", @LONG
一条汹涌澎湃的大江横在你的面前，水面上的旋涡此起彼伏，
浪涛拍打在青石搭成的码头上。十几个船夫正用带钩的船竿钩着渡
船，个个都因用力过度，挣得面红脖粗的，小掌舵的正大声吆喝着
过渡的客人上船。
LONG
    );
        set("exits", ([ 
  "north" : __DIR__"guandao3",
]));

    set("objects",([
        __DIR__"npc/zhangduo2":1,
]));
    set("outdoors", "mengjin");
    setup();
}

int check_trigger()
{
    object room;
    if(!query("exits/enter") ) {
        if( !(room = find_object(DUCHUAN)) )
            room = load_object(DUCHUAN);
        if( room = find_object(DUCHUAN) ) {
            if((int)room->do_check() && !room->query("yell") ) {
                set("exits/enter", DUCHUAN);
                room->set("exits/out", __FILE__);
                room->set("yell",1);
                message("vision", "一艘渡船缓缓地驶了过来，船夫将一块踏脚"
                    "板搭上堤岸，以便乘客上下。\n", this_object() );
                message("vision", "船夫将一块踏脚板搭上堤岸，形成一个向上"
                    "的阶梯。\n", room);
                remove_call_out("on_board");
                call_out("on_board", 15);
            }else       return 0;       // 船在对岸
        }else{
            message("vision", "ERROR: boat not found\n", this_object() );
            return 0;
        }
    }
    return 1;
}
void on_board()
{
    object room;
    if( !query("exits/enter") ) return;
    if ( NATURE_D->outdoor_room()){
        message("vision", "船夫打了个哈欠：“现在天色已晚，明早再过江吧。”\n",this_object() );
        return;
    }
    message("vision", "船夫把踏脚板收了起来，竹篙一点，渡船向江心驶去。\n",
        this_object() );
    delete("exits/enter");
    if( room = find_object(DUCHUAN) )
    {
        room->delete("exits/out");
    room->delete("yell");
        message("vision", "船夫把踏脚板收起来，说了一声“坐稳喽”，"
            "竹篙一点，渡船向江心驶去。\n", room );
    if (!(int)room->do_check()){
        remove_call_out("arrive");
        call_out("arrive", 20);
    }
    }
}
void arrive()
{
    object room;
    if( room = find_object(DUCHUAN) )
    {
        room->set("exits/out", OTHER_ROOM);
    room->set("yell",1);
        message("vision", "船夫说“到啦，上岸吧”，随即把一块踏脚板搭上堤岸。\n",room );
    if( !room = find_object(OTHER_ROOM) )
    room = load_object(OTHER_ROOM);
    room->set("exits/enter", DUCHUAN);
    message("vision", "一艘渡船缓缓地驶了过来，船夫将一块踏脚板搭上堤岸，以便乘客上下。\n", room );
    remove_call_out("close_passage");
    call_out("close_passage", 10);
   }
}
void close_passage()
{
    object room;
    if( room = find_object(OTHER_ROOM) )
    room->on_board();
}
/* int valid_leave(object who,string dir)
{
        object ob=present("xiao zhangduo",this_object());
        if (dir=="enter"){
          if (!ob)      return notify_fail("船上几位船夫大声嚷道：小掌舵不在，"+RANK_D->query_respect(who)+"等会再上船罢。\n");
          if (!living(ob))      return notify_fail("船上几位船夫大声嚷道：这位"+RANK_D->query_respect(who)+"，小掌舵就在你身边，先叫醒他罢。\n");
          if ( NATURE_D->outdoor_room())
             return notify_fail("小掌舵一下挡在船前，对不起，晚上过渡太危险了！\n");
          if ( !who->query_temp("rent_paid"))
             return notify_fail("小掌舵一下挡在船前，白眼一翻：嘿嘿！不给钱想过江吗？\n");
        }
        who->delete_temp("rent_paid");
        return 1;
}
*/

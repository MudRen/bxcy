// Room: /d/quanzhou/haigang.c
// Date: May 7, 96   Jay
inherit ROOM;
void create()
{
    set("short", "海港");
    set("long", @LONG
这里是出海的必经之地，海边泊着一艘大船(chuan)。
LONG
    );
    set("exits", ([
                "west" : __DIR__"zhongxin",
"east" : "/d/lingshedao/quanzhou/haigang",	
    ]));
    set("objects", ([
                __DIR__"npc/boy":2,
                __DIR__"npc/girl":1,
                "/d/shenlong/npc/chuanfu" :1,
    ]));
    set("item_desc", ([
        "chuan" : "这是去桃花岛的大船。只要上船(enter)就可以到桃花岛。\n",
    ]));
    set("outdoors", "quanzhou");
    setup();
}
void init()
{
    add_action("do_enter", "enter");
}
int do_enter ( string arg )
{
    object ob ,room;
    if( !arg || arg !="chuan" ) 
       {
         tell_object(this_player() , "你要 enter 哪儿？\n" ) ;
         return 1 ;
       }
    if (!room=find_object("/d/taohua/dahai"))
    room=load_object("/d/taohua/dahai");
    if (!room->do_check())
        return notify_fail("船刚刚出海了！\n");
    ob = this_player () ;
    message_vision("船夫一见有人上船，忙叫了一声：开船喽！\n", ob);
    message_vision("船夫升起帆，船就向东方航行。\n", ob);
    ob ->move(room) ;
    tell_object(ob, BLU "你在海上航行了很久很久.......\n" NOR ) ;
    call_out("rtaohua", 10 , ob );
    return 1 ;
}
void rtaohua( object ob )
{
    if (!ob || ob->is_ghost()) return;
  tell_object(ob , "大船终于抵达了一个金色的海滩。你走下船来。\n" ) ;
  ob->move ("/d/taohua/haitan.c") ;
}

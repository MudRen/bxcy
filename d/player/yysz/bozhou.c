
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "困龍滩");
        set("long",@LONG
一片萧瑟，茭白丛中现出一个码头，大小船只依次排开。菱花荷叶
丛中条条水道四通八达，由此可乘船离开御云山庄。湖面正停着一艘小舟
(zhou)。
LONG );
        set("outdoors", "yysa");
        set("exits", ([
            "east"  : __DIR__"pindi",
        ]));
        set("item_desc", ([
            "zhou" : "这是御云山庄和江湖联系的小舟。舟上一个绿衫少女。岛上的客人只要登
舟(enter)就可以出湖了。\n",
        ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
       add_action("do_enter", "enter");
}
int do_enter(string arg)
{
       object ob ;
       string dir;
       if( !arg || arg !="zhou" ) 
       {
             tell_object(this_player() , "你想自杀吗？请去tam,n.out.谢谢合作!\n" ) ;
             return 1 ;
       }
       ob = this_player();
message_vision("船上一个秀美温柔的美丽少女看到$N登舟，竹篙轻点，舟已离岸，
御云山庄渐渐在视野里远去。\n", ob);
       ob ->move(__DIR__"taihu") ;
       tell_object(ob, HIG "你在舟上远眺，四周是看不尽的江南美景。\n" NOR ) ;
       call_out("home", 10 , ob );
       return 1 ;
}
void home( object ob )
{
       tell_object(ob , "小舟终于恋恋不舍地靠岸了。你走下小舟来。少女挥手道别。\n" ) ;
       ob->move (__DIR__"hupan") ;
}


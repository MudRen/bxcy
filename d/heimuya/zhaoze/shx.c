// Room: shx.c
inherit ROOM;
int do_press(string arg);
void relay_circs(object me);
void create()
{
        set("short", "水下");
        set("long", @LONG
这里的水十分浑浊，你把眼睁得大大的，也什么都看不见。
LONG
);
        set("exits", ([ 
        "up" : __DIR__"room9",
]));
        setup();
}
void init()
{
    object me, room;
    me = this_player();
        set("long", @LONG
这里的水十分浑浊，你把眼睁得大大的，也什么都看不见。
LONG
);
     delete("item_desc"); 

    if (userp(me)){
        call_out("relay_circs",5,me);
        }
}
void relay_circs(object me)
{
     if (environment(me)!=this_object()) return;
     if ( !present("ming zhu",me) ) return;  
        write(
"  你怀里的夜明珠忽然发出一阵豪光，你发现这水塘大约有十丈方圆，
塘底有一石板，上刻有一些数字，好象可以按动(press)。\n"
             );
        set("long", @LONG
凭借夜明珠的豪光，你可以看到这水塘大约有十丈方圆，塘底有一石板，
上刻有一些数字，好象可以按动(press)。
LONG
        );
        add_action("do_press", "press");
}
int do_press(string arg)
{
    int p;
    if( !arg || arg == "" || (sscanf( arg , "%d", p)!=1) )
    {
        write("别瞎按！\n");
        return 1;
    }
    if( p == this_player()->query_temp("passwd") )
    {
        message_vision("只听得一阵隆隆的响声由远及近。\n", this_player());
        message_vision("石板缓缓移了开来，露出一个洞。\n", this_player());
        set("exits/enter", __DIR__"mishi");
        remove_call_out("close");
        call_out("close", 5, this_object());
        return 1;
    }
    else
    {
        write("你心想：老天保佑这次能蒙着！\n");
        if ( random(10) >5 )
        {
            message_vision("$N一阵乱按，什么反应也没有。\n", this_player());
            return 1;
        }
        else
        {
            message_vision("$N一阵乱按，突然石板的缝隙间射出一支毒箭！。\n", this_player());
            this_player()->set_temp("die_for","被毒箭射");
            this_player()->receive_damage("qi", 1000);
            this_player()->receive_wound("qi", 1000);
            this_player()->unconcious();
            return 1;
        }
    }
}
void close(object room)
{
        message("vision","轰隆隆的响声响过之后，石板又合上了。\n", room);
        room->delete("exits/enter");
}


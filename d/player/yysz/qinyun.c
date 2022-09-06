
inherit ROOM;

void create()
{
        set("short","温馨小筑");
        set("long",@LONG
这是一间小巧玲珑的房舍，颇为精雅，程公子和聊聊两夫妻就住在这里。
周围稀稀落落的四五间小房屋，建造在一个不知是小岛还是半岛上。真
是一个让人羡慕的地方。
LONG );
        set("exits",([
            "westdown" : __DIR__"muti",
            "east"     : __DIR__"xiaoting",
            "south"    : __DIR__"neitang",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}



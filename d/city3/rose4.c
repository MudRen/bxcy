// This is a room made by roommaker.

inherit ROOM;

void create()
{
    set("short", MAG"园中小屋"NOR);
    set("long", ""MAG"你推开竹门走了进来，一股清新的花香味扑鼻而来，原\n"
                 "来房子的后面有一口池塘，池塘里的荷花正盛放而开，小屋\n"
                 "中摆着一张用竹子编成的桌子，桌子上放着一个非常雅致的\n"
                 "花瓶上面插着十一朵"HIW"白玫瑰"MAG"。"NOR"\n");
    set("exits", ([
                "east" : __DIR__"rose3",
            ]));
       set("no_fight",1);
    setup();
    replace_program(ROOM);
}


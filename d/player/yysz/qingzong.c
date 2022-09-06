
inherit ROOM;
void create()
{
        set("short", "英雄冢");
        set("long",@LONG
你在竹林中七绕八绕，忽然豁然开朗，原来到了御云山庄的墓地，
据说御云山庄的创始高人就葬于此了。地上长满了细的小草，传说这
种草常年碧绿，永不枯萎。大概是因为地下英灵不息的缘故吧。似乎
除了向南有一片竹林外别无出口。
LONG );
        set("outdoors", "yysz");
        set("exits", ([
                "south" : __DIR__"zhulin3",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


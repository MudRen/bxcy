
inherit ROOM;
void create()
{
    set("short", "房舍");
    set("long", @LONG
这里是一间小屋，一个太监正在休息。
LONG
    );
    set("exits", ([
        "north" : __DIR__"zoulang1",
    ]));
    set("objects", ([
        "/d/huanggon/npc/taijian":1,
    ]));
    setup();
    replace_program(ROOM);
}


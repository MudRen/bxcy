
inherit ROOM;

void create()
{
        set("short", "慈云阁");
        set("long",@LONG
这里是供御云山庄的仆人小憩的地方，三面临水。微风拂过，送来
缕缕的花香，沁人心肺。一架墨绿色的竹梯通向楼上的休息室。
LONG );
        set("exits", ([
            "east"  : __DIR__"yimen",
"up"    : __DIR__"qinfeng2",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


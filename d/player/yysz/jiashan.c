
inherit ROOM;

void create()
{
        set("short", "小院");
        set("long",@LONG
这里怪石堆叠，巨石参差，你有些头晕目眩，那么多山洞你不知该钻哪
一个。个个山洞都昏暗曲折，实在不知通向什么地方。院子正中还有一
口喷泉正在"突.突.."的喷水呢。
LONG );
        set("outdoors", "yysz");
        set("exits", ([
            "west" : __DIR__"zuijing",
            "east" : __DIR__"shuiyun",
            "north": __DIR__"huayuan",
//          "south": __DIR__"huanshi",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


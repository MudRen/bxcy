
inherit ROOM;

void create()
{
        set("short", "闲云居");
        set("long",@LONG
这是御云山庄首脑人物日常起居之地，布置得华丽中不乏清雅，平
实中透着高贵。楠木方桌，大太师椅，以及墙上的字画都透着一股非凡
之气魄。
LONG  );
        set("exits", ([
            "west" : __DIR__"qiushuan",
            "east" : __DIR__"zuijing",
            "north": __DIR__"yimen",
            "south": __DIR__"shuwu",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


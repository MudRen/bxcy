// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "三叉路口");
        set("long", "刚进大门，你面前就有一个三叉路口，西南方是神风堂大堂，东南方是天星堂大堂。\n");

	set("exits", ([
                "north" : __DIR__"fumen",
		"south" : __DIR__"sclk1",
                "southwest" : __DIR__"ft",
                "southeast" : __DIR__"yt",

	]));
	setup();
	replace_program(ROOM);
}


// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "新手救济处");
	set("long", "这里是啸天会帮助新人的地方，平时府里的兄弟都会从各
处收集到各种奇珍异宝都会放在这里给一些需要的兄弟们，你
 也可以把你用不到的东西放在这。这里往南边去就是天星堂大
堂了。\n");

	set("exits", ([
                "east" : __DIR__"xs3",
                "south" : __DIR__"yt",
	]));
	setup();
	replace_program(ROOM);
}


// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "监察院");
	set("long", "这里就是啸天会最机密的地方之一，两边路上隐隐约约的
，不知道隐藏了多少的机关。平时只有会长和四个堂主才可以
进来。\n");

	set("exits", ([
                "west" : __DIR__"fzsf",

	]));
	setup();
	replace_program(ROOM);
}


// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", "这是啸天会地子吐纳练气的地方，四周静悄悄的，只能听
见几个弟子的呼吸声。\n");

	set("exits", ([
                "east" : __DIR__"lgt1",
		
	]));
	setup();
	replace_program(ROOM);
}


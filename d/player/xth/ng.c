// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "内阁");
	set("long", " 这里就是啸天会里面的刑堂，只是这里冷冷清清的，似
乎很久没有人来过了。\n");

	set("exits", ([
                "south" : __DIR__"dt",
	]));
	setup();
	replace_program(ROOM);
}


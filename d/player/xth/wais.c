// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "外室");
	set("long", "这里是灼日堂对外处理事物的地方，平时要有弟子被欺
负了，就是由灼日堂堂主在这里和他们进行交涉的。这里唯
一的出口是。\n");

	set("exits", ([
                "north" : __DIR__"dt",
	]));
	setup();
	replace_program(ROOM);
}


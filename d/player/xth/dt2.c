// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "灼日罩地");
	set("long", "这儿是啸天会灼日堂开会的地方，屋子里摆了一张雕花议
事桌和两排檀木椅。灼日堂堂主就在这儿和堂主弟子商量大事。
这里唯一的出口通向灼日堂大厅。\n");

	set("exits", ([
                "west" : __DIR__"dt1",
	]));
	setup();
	replace_program(ROOM);
}


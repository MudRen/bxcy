// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "����·��");
	set("long", "������Х�������ģ�������������ˣ�������ͨ�������ã������������á�\n");

	set("exits", ([
                "north" : __DIR__"sclk",
		"south" : __DIR__"zt",
                "southwest" : __DIR__"lt",
                "southeast" : __DIR__"dt",

	]));
	setup();
	replace_program(ROOM);
}


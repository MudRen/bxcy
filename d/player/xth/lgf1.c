// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", "����Х���������������ĵط������ܾ����ĵģ�ֻ����
���������ӵĺ�������\n");

	set("exits", ([
                "east" : __DIR__"lgt1",
		
	]));
	setup();
	replace_program(ROOM);
}


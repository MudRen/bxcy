// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "����·��");
        set("long", "�ս����ţ�����ǰ����һ������·�ڣ����Ϸ�������ô��ã����Ϸ��������ô��á�\n");

	set("exits", ([
                "north" : __DIR__"fumen",
		"south" : __DIR__"sclk1",
                "southwest" : __DIR__"ft",
                "southeast" : __DIR__"yt",

	]));
	setup();
	replace_program(ROOM);
}


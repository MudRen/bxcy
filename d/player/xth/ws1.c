// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "��������������");
	set("long", "���������������������ң��������ܼ�ªֻ�ڵ�������һ���ò�ϯ����\n");
        set("no_fight",1);
        set("no_steal",1);
        set("sleep_room",1);

	set("exits", ([
                "northwest" : __DIR__"yt1",

	]));
	setup();
	replace_program(ROOM);
}


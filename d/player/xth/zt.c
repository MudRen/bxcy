// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", "������Х�������ã������������������Х��������
�ˡ�������Х��������ã������������á�\n");
        set("no_fight",1);
        set("no_steal",1);

	set("exits", ([
                "north" : __DIR__"sclk1",
                "south" : __DIR__"jyt",
                  "east" : __DIR__"lgs2",
                 "west" : __DIR__"lgs1",


	]));
	setup();
	replace_program(ROOM);
}


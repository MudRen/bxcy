// Room: workroom.c

inherit ROOM;

void create()
{
	set("short", "bingwu�ļ�");
	set("long", @LONG
     ������bingwu�Ĺ����ҡ�
LONG
	);

	set("valid_startroom",1);

	set("exits", ([
		"down": "/d/city/guangchang",
	]));

	setup();
	replace_program(ROOM);
}



inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣���߶�����������

LONG );
       set("outdoors", "city");
	set("no_clean_up", 0);
	set("exits", ([
		
              "east" : __DIR__"eroom2",
		"south" : __DIR__"fight1",
		"west" : __DIR__"guangchang",
		"north" : __DIR__"fight2",
	]));

	setup();
	replace_program(ROOM);
}


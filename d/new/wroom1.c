
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
		
              "east" : __DIR__"guangchang",
		"south" : __DIR__"fight3",
		"west" : __DIR__"wroom2",
		"north" : __DIR__"fight4",
	]));

	setup();
	replace_program(ROOM);
}



inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ��ֵ������ϱ���ͷ���졣���߶�����������

LONG );
       set("outdoors", "city");
	set("no_clean_up", 0);
	set("exits", ([
		
              "east" : __DIR__"fight6",
		"south" : __DIR__"guangchang",
		"west" : __DIR__"fight5",
		"north" : __DIR__"nroom2",
	]));

	setup();
	replace_program(ROOM);
}


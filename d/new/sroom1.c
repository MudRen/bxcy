
inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
����һ����������ʯ��ֵ������ϱ���ͷ���졣���߶�����������

LONG );
       set("outdoors", "city");
	set("no_clean_up", 0);
	set("exits", ([
		
              "east" : __DIR__"fight8",
		"north" : __DIR__"guangchang",
		"west" : __DIR__"fight7",
		"south" : __DIR__"sroom2",
	]));

	setup();
	replace_program(ROOM);
}


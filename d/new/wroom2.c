
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
		
              "east" : __DIR__"wroom1",
		"south" : __DIR__"fight31",
	//	"west" : __DIR__"eroom1",
		"north" : __DIR__"fight41",
	]));

	setup();
	replace_program(ROOM);
}


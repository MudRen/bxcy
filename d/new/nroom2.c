
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
		
              "east" : __DIR__"fight61",
		"south" : __DIR__"nroom1",
		"west" : __DIR__"fight51",
	//	"north" : __DIR__"fight4",
	]));

	setup();
	replace_program(ROOM);
}


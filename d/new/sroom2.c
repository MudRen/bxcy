
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
		
              "east" : __DIR__"fight81",
		"north" : __DIR__"sroom1",
		"west" : __DIR__"fight71",
	//	"north" : __DIR__"fight4",
	]));

	setup();
	replace_program(ROOM);
}


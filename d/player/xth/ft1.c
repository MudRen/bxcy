// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "����ô���");
	set("long", "����������ô���������ǽ�Ϲ��˲��������ֻ���������
��һ�Ű������߲�������õ����ھۻύ�������ϵ��������¡�
�������������ѯ�������Ͼ͵��˽�Ǯ����ȥ���߾������Ʈ
�ƣ������������������˽�����ҡ�\n");

	set("exits", ([
                "north" : __DIR__"zxt",
		"south" : __DIR__"jqt",
                "west" : __DIR__"ft2",
                "east" : __DIR__"ft",
                "southwest" : __DIR__"ws",

	]));
	setup();
	replace_program(ROOM);
}


// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "�ʷ�");
	set("long", "������Х���������ĵط���һ����Ľ������ϴ�����
�����������������ڼ�¼�Ž������Ŀ���롣�������������
���ã������ǲ�������\n");

	set("exits", ([
                "west" : __DIR__"jqt",
                "north" : __DIR__"ft",

	]));
	setup();
	replace_program(ROOM);
}


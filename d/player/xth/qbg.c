// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "�鱨��");
	set("long", "�鱨����Х���������ռ������鱨�ĵط����������κ�
һ��紵�ݶ����Ӳ���������۾����������������ѯ������
��������ô��á�\n");

	set("exits", ([
                "west" : __DIR__"zxt",
                "south" : __DIR__"ft",

	]));
	setup();
	replace_program(ROOM);
}


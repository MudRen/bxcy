// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "�����ô���");
	set("long", "���Ǹ��������Ĵ����������м����һ�ų�����������
�ӡ������õ������͵��Ӿ�����������ཻ���ĵá�����ȥ��
�������ֵغ����������ҡ�\n");

	set("exits", ([
                "northdown" : __DIR__"ncs",
		"southdown" : __DIR__"wcs",
                "east" : __DIR__"dt2",
                "west" : __DIR__"dt",
                "southeast" : __DIR__"ws3",
	]));
	setup();
	replace_program(ROOM);
}


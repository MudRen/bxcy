// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", "�����ǻ��е��������ĵط��������˲���ľ׮ľ�˺�ͭ��
�������ﻹ�в��ټ��ӷ�������ʱ�õ�ľ�ʱ�����\n");

	set("exits", ([
		"west" : __DIR__"lgf2",
		"north" : __DIR__"lt",
	]));
	setup();
	replace_program(ROOM);
}


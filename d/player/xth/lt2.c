// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "���º���");
	set("long", "������Х������������µĵط��������������ش�ľ���
��������������������������������Ṳͬ�����������ȥ��
���������ô�����\n");

	set("exits", ([
		"east" : __DIR__"lt1",
	]));
	setup();
	replace_program(ROOM);
}


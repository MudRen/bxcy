// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "�ڸ�");
	set("long", " �������Х�����������ã�ֻ��������������ģ���
���ܾ�û���������ˡ�\n");

	set("exits", ([
                "south" : __DIR__"dt",
	]));
	setup();
	replace_program(ROOM);
}


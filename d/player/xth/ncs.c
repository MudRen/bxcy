// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "�ڴ���");
	set("long", "  �����������õĵ����ң�������������ı����ϼ�¼��
�����ô�����Ĵ�С���顣\n");

	set("exits", ([
                "southup" : __DIR__"dt1",
	]));
	setup();
	replace_program(ROOM);
}


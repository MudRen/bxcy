// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", "�����������ö��⴦������ĵط���ƽʱҪ�е��ӱ���
���ˣ���������������������������ǽ��н���ġ�����Ψ
һ�ĳ����ǡ�\n");

	set("exits", ([
                "north" : __DIR__"dt",
	]));
	setup();
	replace_program(ROOM);
}


// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "�⴦��");
	set("long", "  �����������õĵ����ң�������������ı����ϼ�¼��
���������Ҵ�����Ĵ�С���顣����Ψһ�ĳ�·�ǡ�\n");

	set("exits", ([
                "northup" : __DIR__"dt1",

	]));
	setup();
	replace_program(ROOM);
}


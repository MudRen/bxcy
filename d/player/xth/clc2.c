// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", "�����Ǹ��ڵ�һ�������أ����ڿ�������������
��ס������ȥժһ�䡣����������ڴ����������������ˣ�\n");
       
	set("exits", ([
                "west" : __DIR__"yyt",

	]));
	setup();
	replace_program(ROOM);
}


// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", "�����Ǹ��ڵ�һ�������أ����ڿ�������������
��ס������ȥժһ�䡣����������ڴ����������������ˣ�\n");
       
	set("exits", ([
                "east" : __DIR__"ywt",
                              
	]));
	setup();
	replace_program(ROOM);
}


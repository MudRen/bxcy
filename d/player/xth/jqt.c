// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", "������Х�������ӷ��Ź��ʺͻ���ѵĵط���������
һ��ľ�������ʷ����ڽ�������µĻ�����������������
�ô������������ʷ���\n");

	set("exits", ([
                "east" : __DIR__"bjg",
                "north" : __DIR__"ft1",

	]));
	setup();
	replace_program(ROOM);
}


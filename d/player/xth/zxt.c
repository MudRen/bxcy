// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "��ѯ��");
	set("long", "�����Ϊ�˽������������ʱ���������ķ��䣬������
�Ѿ��в�������̸����ʲô��Х�����µ��ӿ����������ʵ�
ʱ�����������е�����̡���������Ͼ�������ô�������
�����鱨��\n");

	set("exits", ([
               "east" : __DIR__"qbg",
                "south" : __DIR__"ft1",

	]));
	setup();
	replace_program(ROOM);
}


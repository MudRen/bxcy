// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "������ѯ��");
	set("long", "�����Ϊ�˽������������ʱ���������ķ��䣬������
�Ѿ��в�����̸����ʲô��Х�����µ��ӿ����������ʵ�ʱ
�����������е�����̡���������Ͼ��������ô����ˡ�\n");

	set("exits", ([
                "west" : __DIR__"xs1",
                "south" : __DIR__"yt1",
	]));
	setup();
	replace_program(ROOM);
}


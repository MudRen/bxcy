// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "���̵ֽ���");
	set("long", "������Х���Ԫ����������ڻ��˵ĵط����������в���
��ܡ������Ϸ��Ű���ǰ�������µ����������������������
���ĵá�����򱱾��������ô�����\n");

	set("exits", ([
                "west" : __DIR__"xs2",
                "north" : __DIR__"yt1",
	]));
	setup();
	replace_program(ROOM);
}


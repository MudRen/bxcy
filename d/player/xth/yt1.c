// qjc 2000/5/3 

inherit ROOM;

void create()
{
     set("short", "�����ô���");
	set("long", "���Ǹ��������ɰ��˵Ŀ���������
  �������õ��������д���·�������ܡ�Ľ�������ĸ�·Ӣ�ۼ�
��һ�úò����֡�������ȥ��������ѯ�������������̵ֽ�����
     ����������ҫĿ��������������������˽�����ҡ�\n");

	set("exits", ([
                "north" : __DIR__"xs3",
                "south" : __DIR__"xs4",
                "west" : __DIR__"yt",
                "east" : __DIR__"yt2",
                "southeast" : __DIR__"ws1",
	]));
	setup();
	replace_program(ROOM);
}


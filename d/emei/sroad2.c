//room: /d/emei/sroad2.c

inherit ROOM;

void create()
{
	set("short", "��Դ����");
	set("long", @LONG
������һ��ͨ�������ĵ���ʯ·�ϣ���·���������ų���������ʣ���
������һ��䷿�ݣ����Կ������������⳨���š���Ϊ��紾�ӡ������
ϵ��Ǣ��ʱ�ѵ���·��ʰ�š�ҹ���ջ��ĳ̶ȡ��һ��������������������
���Ը����������������ǵ����
LONG
	);

        set("exits", ([
              "south":__DIR__"sroad1",
              "north":__DIR__"sroad3",
             "west":"/d/emei/user-room/sunrise/home",
	]));
        set("outdoors", "emei");
	setup();
}

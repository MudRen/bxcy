// qjc 2000/5/3 

inherit ROOM;

void create()
{
      set("short", "����ҫĿ");
     set("long", "�����û����������������������µ�
��������������ĵط���ÿ��һ��ʱ�������ͻ��������ټ���
  �ӽ��ܵ��ӵĻ㱨���������ȥ��ֱ�ӵ��������õĴ����ˡ�\n");

	set("exits", ([
                "west" : __DIR__"yt1",

	]));
	setup();
	replace_program(ROOM);
}


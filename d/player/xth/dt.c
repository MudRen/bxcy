// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "�����ô���");
	set("long", "������Х���������ô��ã�һ���žͻῴ��ǽ�����ɷ�
���һ����Ѹ���֡�����������������㽻����Ⱥ�ۣ������
��������Ӣ�۽����ܵ���һ��Ϊ�١�������򶫾��������ô�
�����ϱ������ֱ����ڸ�����ҡ�\n");

	set("exits", ([
                "north" : __DIR__"ng",
		"south" : __DIR__"wais",
                "east" : __DIR__"dt1",
                "northwest" : __DIR__"sclk1",

	]));
	setup();
	replace_program(ROOM);
}


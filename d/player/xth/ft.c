// qjc 2000/5/3 

inherit ROOM;

void create()
{
        set("short", "����ô���");
        set("long", "������Х������ô��á�����ǽ��д��һ�����硱�֣���
�����һ��̴ľ�����ڷ���һЩ�����Ĵ����͹��档����õ�
���Ӷ�������ݼ��������������ĵ�ǲ������������õ��鱨
���ϱ����ʷ���ȥ���߾͵�������ô����ˡ�\n");

	set("exits", ([
                "north" : __DIR__"qbg",
		"south" : __DIR__"bjg",
                "west" : __DIR__"ft1",
                "northeast" : __DIR__"sclk",

	]));
	setup();
	replace_program(ROOM);
}


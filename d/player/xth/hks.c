// wenwu 2003/8/4 	

inherit ROOM;

void create()
{
	set("short", "�����");
set("long", "������ǹ����д����˵ĵط������ܽ�̻Իͣ��м�һ�������ϰڷ��˼�ɫ���ģ�һ����衣\n");	

	set("exits", ([
                "north" : __DIR__"jyt",
                "south" : __DIR__"zly",
                "west" : __DIR__"fzws",
                "east" : __DIR__"fzsf",
	]));
	setup();
	replace_program(ROOM);
}


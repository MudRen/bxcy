// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "���Ժ");
	set("long", "�������Х�������ܵĵط�֮һ������·������ԼԼ��
����֪�������˶��ٵĻ��ء�ƽʱֻ�л᳤���ĸ������ſ���
������\n");

	set("exits", ([
                "west" : __DIR__"fzsf",

	]));
	setup();
	replace_program(ROOM);
}


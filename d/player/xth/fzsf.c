// wenwu 2003/8/4 	

inherit ROOM;

void create()
{
set("short", "�鷿");
	
set("long", "�����������ǹ�������˽���鷿����������źü����ӵĹż������ӿ�������һ�ź�ľ����������ڷ����ķ��ı���һЩ��·���ܸ����������İ�����\n");
	set("exits", ([
                "west" : __DIR__"hks",
                "east" : __DIR__"jcy",

	]));
	setup();
	replace_program(ROOM);
}


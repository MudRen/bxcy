// wenwu 2003/8/4 	

inherit ROOM;

void create()
{
	set("short", "������");
set("long", "�����������ǹ��ۼ�����ĵط�,�����ڿտ��ĺ�,ֻҪһ�д��·�������������ɽ�˺���ˮй��ͨ��\n");	

	set("exits", ([
                "north" : __DIR__"zt",
                "south" : __DIR__"hks",
                "west" : __DIR__"ywt",
                "east" : __DIR__"yyt",
	]));
	setup();
	replace_program(ROOM);
}


//hudi4.c

inherit ROOM;

void create()
{
	set("short", "С���� ");
	set("long",
		������С���ף����ܺں����ģ�ͷ���Ͽ�����һ�����⣬��ߵ�ˮ��
		���Ϻ��µ�ӿ���š���������һ�����ۡ������ƺ���һ�����⣬Ҳ��֪��
                        Щʲô����ΧһƬ���ţ��ƺ������Ų��ɱ����\n"

	);
	set("exits", ([
		"up" : __DIR__"",	
		"down" : __DIR__"",
		"east" : __DIR__"",
		"north" : __DIR__"",
		"south" : __DIR__"",
	]));
	setup();
	replace_program(ROOM);
}

//hudi3.c

inherit ROOM;

void create()
{
	set("short", "小湖底 ");
	set("long",@LONG
这里是小湖底，四周黑忽忽的，头顶上看不见一点亮光，身边的水流
忽上忽下的涌动着。看起来是一处海眼。脚下似乎有一点亮光，也不知是
些什么。周围一片死寂，似乎暗藏着层层杀机。
LONG

	);
	set("exits", ([
		"up" : __DIR__"",	
		"down" : __DIR__"",
		"southwest" : __DIR__"",
		"northwest" : __DIR__"",
		
	]));
	setup();
	replace_program(ROOM);
}
//tan7.c

inherit ROOM;

void create()
{
	set("short", "嘉兴南湖 ");
	set("long",
"这里是小湖底，四周黑忽忽的，头顶上看不见一点亮光，身边的水流	
		忽上忽下的涌动着。看起来是一处海眼。脚下似乎有一点亮光，也不知是
                        些什么。周围一片死寂，似乎暗藏着层层杀机。\n"

	);
	set("exits", ([
		"up" : __DIR__"",	
		"east" : __DIR__"",
		"west" : __DIR__"",
		"south" : __DIR__"",
		"north" : __DIR__"",
	]));
//        set("objects" , ([
//               __DIR__"npc/fish" : 3,
//	       __DIR__"item/zhenzhu" :1,	
//             ]) );
	setup();
	replace_program(ROOM);
}

// wenwu 2003/8/4 	

inherit ROOM;

void create()
{
set("short", "书房");
	
set("long", "这里是幽云星宫宫主的私人书房，房间里摆着好几架子的古籍。屋子靠窗放着一张红木书桌，上面摆放着文房四宝和一些各路豪杰给宫主送来的拜帖！\n");
	set("exits", ([
                "west" : __DIR__"hks",
                "east" : __DIR__"jcy",

	]));
	setup();
	replace_program(ROOM);
}


//Room /d/honghua/zuolang2.c
inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long",@LONG
你走在一条长长的走廊上，四周没有一个人，你的脚步
声传得很远，两旁池塘里的残荷上停了几只呱呱乱叫的青蛙
，阵阵轻风吹来，令人欲醉.
LONG
	);
	
	set("outdoors", "honghua");	


	set("exits", ([
          "south" : "/d/honghua/xiuxishi",
                "northup" : "/d/honghua/zongduo",
                "west"   : "/d/honghua/yixiangting",
           "eastdown" : __DIR__"zoulang" ,
	]));

	set("coor/x",-150);
	set("coor/y",100);
	set("coor/z",20);
	set("coor/x",-150);
	set("coor/y",100);
	set("coor/z",20);
	set("coor/x",-150);
	set("coor/y",100);
	set("coor/z",20);
	set("coor/x",-150);
	set("coor/y",100);
	set("coor/z",20);
	setup();

}

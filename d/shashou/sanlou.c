//room: /u/chen/shashou/sanlou.c
inherit ROOM;

void init();

void create()
{
	set("short","第三楼");
	set("long", @LONG
这里是杀手楼的第三楼，这里居住的是杀手楼的年
青一代的高手。整个房间里黑黑的，只有一丝微弱的光
线从墙上的窗子里透进来。
LONG
	   );
	set("exits",([
           "west" : __DIR__"qiandian",
	   ]));
	set("objects",([
		      __DIR__"npc/xiaobai":1,
		      __DIR__"npc/xiaohei":1,
                    __DIR__"npc/weishi":2,
			]));
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

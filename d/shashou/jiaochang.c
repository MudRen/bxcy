//room: /u/chen/shashou/jiaoch.c
inherit ROOM;

void init();

void create()
{
	set("short","校场");
	set("long", @LONG
这里是杀手楼的校场，在这里有一些杀手楼的弟
子在这里练习武功，校场的东面是杀手楼的兵器室，
西面是杀手楼弟子休息的地方，校场的北面是杀手楼
的前殿。
LONG
	   );
	set("exits",([/* sizeof()==4 */
	    "south" : __DIR__"fenglin",
	    "north" : __DIR__"qiandian",
	    "west" : __DIR__"xiuxishi",
	    "east" : __DIR__"liangongfang",
	   ]));
	set("no_clean_up", 0);
	set("outdoors", "shashou" );

	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	"/clone/board/shashou_b"->foo();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "杀手楼" ) && dir == "west" )
                return notify_fail("你不是杀手楼的弟子，跑进去干嘛？\n");
                
        return ::valid_leave(me, dir);
}


// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "冷月堂大厅");
	set("long", "这个大厅时冷月堂堂主会见慕名而来的各路英雄的地方，
大厅中央的兵器架上摆放着各式各样的兵器，冷月堂堂主常常
在这儿和江湖豪客纵论武学心得。往西就是冷月寒天，另一边
通向冷月堂堂主的私人卧室。\n");

	set("exits", ([
                "east" : __DIR__"lt",
		  "west" : __DIR__"lt2",
                "southwest" : __DIR__"ws2",

	]));
	setup();
	replace_program(ROOM);
}


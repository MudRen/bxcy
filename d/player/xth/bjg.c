// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "帐房");
	set("long", "这里是啸天会管理财务的地方，一箱箱的金银不断从外面
运来，而几个人正在记录着今天的帐目出入。往北看是神风堂
大堂，西面是财务厅。\n");

	set("exits", ([
                "west" : __DIR__"jqt",
                "north" : __DIR__"ft",

	]));
	setup();
	replace_program(ROOM);
}


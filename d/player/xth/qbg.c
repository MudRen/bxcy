// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "情报阁");
	set("long", "情报阁是啸天会神风堂收集江湖情报的地方，江湖中任何
一点风吹草动都逃不过这里的眼睛。往西是神风堂咨询厅，南
面是神风堂大堂。\n");

	set("exits", ([
                "west" : __DIR__"zxt",
                "south" : __DIR__"ft",

	]));
	setup();
	replace_program(ROOM);
}


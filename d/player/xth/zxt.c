// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "咨询厅");
	set("long", "这儿是为了解决弟子在练功时的难题而设的房间，屋子里
已经有不少人在谈论着什么。啸天会的新弟子可以在有疑问的
时候来这儿向帮中弟兄请教。从这儿往南就是神风堂大厅，往
西是情报阁。\n");

	set("exits", ([
               "east" : __DIR__"qbg",
                "south" : __DIR__"ft1",

	]));
	setup();
	replace_program(ROOM);
}


// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "新手咨询处");
	set("long", "这儿是为了解决弟子在练功时的难题而设的房间，屋子里
已经有不少在谈论着什么。啸天会的新弟子可以在有疑问的时
候来这儿向帮中弟兄请教。从这儿往南就是冷月堂大厅了。\n");

	set("exits", ([
                "west" : __DIR__"xs1",
                "south" : __DIR__"yt1",
	]));
	setup();
	replace_program(ROOM);
}


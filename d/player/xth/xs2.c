// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "新手支援处");
	set("long", "这儿是新入会的弟子需要帮忙的时候来得地方，屋子里并
没有什么摆设只在墙上挂了几幅字画。从这儿出去往北就到了
  天星堂大堂了。\n");

	set("exits", ([
                "east" : __DIR__"xs4",
                "north" : __DIR__"yt",
	]));
	setup();
	replace_program(ROOM);
}


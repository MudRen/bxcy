// qjc 2000/5/3 

inherit ROOM;

void create()
{
      set("short", "天星耀目");
     set("long", "天星堂会议室是天星堂堂主和堂下弟
子商讨堂内事务的地方，每隔一段时间堂主就会在这里召集弟
  子接受弟子的汇报。从这儿出去就直接到了天星堂的大厅了。\n");

	set("exits", ([
                "west" : __DIR__"yt1",

	]));
	setup();
	replace_program(ROOM);
}


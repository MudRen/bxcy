// qjc 2000/5/3 

inherit ROOM;

void create()
{
     set("short", "天星堂大厅");
	set("long", "这是个可以容纳百人的宽敞大厅，不
  少天星堂弟子正在招待各路江湖豪杰。慕名而来的各路英雄济
济一堂好不热闹。往北望去是新手咨询处，南面是新手教导处，
     东边是天星耀目，东南是天星堂堂主的私人卧室。\n");

	set("exits", ([
                "north" : __DIR__"xs3",
                "south" : __DIR__"xs4",
                "west" : __DIR__"yt",
                "east" : __DIR__"yt2",
                "southeast" : __DIR__"ws1",
	]));
	setup();
	replace_program(ROOM);
}


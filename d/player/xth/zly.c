// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "长老院");
	set("long", "这里是啸天会长老们议事的地方，可以看到几位须发皆白
的老者正在大厅里商议着什么。这里透出一股凝重的气氛，让人觉得肃然起敬！\n");

	set("exits", ([
                "north" : __DIR__"hks",
                "south" : __DIR__"zly1",
                "east" : __DIR__"byj",
                "west" : __DIR__"yyg",
//                 "up" : __DIR__"jing",
	]));
  set("objects", ([
      __DIR__"obj/xianglu" : 1,
  ]));
	setup();
   "/d/board/xth_b"->foo();
//    replace_program(ROOM);
}


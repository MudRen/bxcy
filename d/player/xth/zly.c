// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "����Ժ");
	set("long", "������Х��᳤�������µĵط������Կ�����λ�뷢�԰�
���������ڴ�����������ʲô������͸��һ�����ص����գ����˾�����Ȼ�𾴣�\n");

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


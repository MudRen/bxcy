//room: party/biguan.c
inherit ROOM;
void create()
{
  set("short","����");
  set("long",
      "�����ǳ����������书�ĵط������ܾ����ĵģ����Ǹ������似�ĺó�����\n"
    );
  set("exits",([
      "south" : __DIR__"xxshi",
     ]));

 setup();
 replace_program(ROOM);
}

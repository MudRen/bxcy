//room: party/biguan.c
inherit ROOM;
void create()
{
  set("short","静室");
  set("long",
      "这里是长老们钻研武功的地方。四周静悄悄的，真是个钻研武技的好场所。\n"
    );
  set("exits",([
      "south" : __DIR__"xxshi",
     ]));

 setup();
 replace_program(ROOM);
}

// Room: /new/guangchang.c


inherit ROOM;

void create ()
{
  set ("short", "中央广场");
  set ("long", @LONG
这里是新手区的正中心，一个很宽阔的广场，铺着红砖的地面,看起来给人一种
很舒服的感觉,南北东西都是练工区。不时可以看到来自各地的新手。
LONG);

   set("outdoors", "city");
  
  set("exits", ([ 
  
  "north" : __DIR__"nroom1",
  "east" : __DIR__"eroom1",
  "south" : __DIR__"sroom1",
  "west" : __DIR__"wroom1",

]));


  setup();
}


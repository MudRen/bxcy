// create by snowcat jan 21 1998


inherit ROOM;

void create ()
{
  set ("short", "大官道");
  set ("long", @LONG

一条宽阔笔直的大官道自长安以东伸延而去，足可容得下十马
并驰。往西通向大唐国都长安城，往东通向远方。

LONG);

  set("exits", ([
        "east" : __DIR__"east2",
"south" : "/d/wanjiegu/road4",   	
      ]));
  set("outdoors", __DIR__);

  setup();
}



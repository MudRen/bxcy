//room: lgting.c
inherit ROOM;
void create()
{
set("short","中央广场");	
  set("long",@LONG
这里是帮里的中心地带,也是帮中最热闹的地方。平时帮众们经常在这相互切磋武技,谈论江湖上的奇闻轨事.帮内一些首脑人物也经常来此光顾巡查,更有江湖前辈经常来此指教武功.技巧,传授些江湖经验心得.江湖才女纪嫣然更是这的一道美好风景,从她那可以买到些江湖必备物品.	
LONG
     );
set("exits",([
      "east" : __DIR__"dongdajie1",
      "west" : __DIR__"xidajie1",
      "north" : __DIR__"beidajie1",
      "south" : __DIR__"nandajie1",
     ]));
set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/ji" : 1, 	
]));


 setup();
 replace_program(ROOM);
}

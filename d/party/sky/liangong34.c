// Room: /d/new/liangong34.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", @LONG
这里是供帮内兄弟练功习武的地方。有几个帮众正在专心致致地练武
，有几个手持兵器,在互相拆招,身法灵动，别的人则坐在地上的蒲团上
苦练内力。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"dongdajie1",
]));
	set("objects", ([ /* sizeof() == 1 */
"/d/new/npc/tong-ren" : 4,	
]));
	set("no_new_clean_up", 0);

	setup();
	replace_program(ROOM);
}

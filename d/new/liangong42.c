// Room: /d/new/liangong42.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", @LONG
这里是江湖朋友练功的地方。有几个江湖侠客正在专心致致地练武
，有几个手持兵器,在互相拆招,身法灵动，别的人则坐在地上的蒲团上
苦练内力。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"dongdajie5",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tong-ren" : 4,
]));
	set("no_new_clean_up", 0);

	setup();
	replace_program(ROOM);
}

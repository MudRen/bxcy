// Room: /d/huashan/liangong2.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", @LONG
这里是华山弟子练功的地方。有几个华山弟子正在专心致致地练武
，有几个手持竹剑,在互相拆招,身法灵动，别的人则坐在地上的蒲团上
苦练内力。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"liangong1",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tong-ren" : 4,
]));
	set("no_new_clean_up", 0);

	setup();
	replace_program(ROOM);
}

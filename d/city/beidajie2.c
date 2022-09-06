// Room: /d/city/beidajie2.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "北大街");
	set("long", @LONG
	这是一条宽阔的青石街道，向南北两头延伸。北边是北城门通向城外。
南边显得很繁忙。东边是一座两层的楼阁，挂着“太白遗风”的招帘，门额上悬
挂一方横匾，“醉仙楼”三字擦得闪闪发亮，乃是苏学士的手笔。阵阵酒肉香酒
香让你垂涎欲滴。西边是一座古朴的庙宇，香火缭绕，那就是天下学武之人所共
同敬仰的武庙了。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"beimen",
  "west" : __DIR__"wumiao",
  "south" : __DIR__"beidajie1",
  "east" : __DIR__"zuixianlou",
]));
	set("outdoors", "city");
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/scavenger" : 1,
  "/d/npc/guojing" : 1,
]));
	setup();
	replace_program(ROOM);
}

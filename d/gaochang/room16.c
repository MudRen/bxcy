// Room: /u/mei/room16.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "龙门客栈");
	set("long", @LONG
小酒家几乎从不打烊，酒铺看起来不差，老板娘长得很不错，但不知为
什么，里边冷冷清清，看不见一个客人。屋子里布置得精雅而别致，每一样
东西都是精心挑选的，正好摆在最恰当的地方，厅当中供着一个手捧金元宝
的财神爷，上面还贴着张斗大的红“喜”字，无论谁走进这里，都可以看得
出这地方的主人，一定是整天在做着发财梦的穷小子。
LONG
);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/jinxiangyu" : 1,
]));
	set("no_new_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room2",
]));

	setup();
	replace_program(ROOM);
}

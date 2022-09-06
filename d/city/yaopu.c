// Room: /d/city/yaopu.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "药铺");
	set("long", @LONG
	这是一家药铺，一股浓浓的药味让你几欲窒息，那是从药柜上的几百个小
抽屉里散发出来的。神医平一指坐在茶几旁，独自喝着茶，看也不看你一眼。一名
小伙计站在柜台后招呼着顾客。柜台上贴着一张发黄的广告(guanggao)。
LONG
	);
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "guanggao" : "本店出售以下药品：
金创药：	五十两白银
其他神药与老板面议。
",
]));
	set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/ping" : 1,
  __DIR__"npc/huoji2" : 1,
  __DIR__"npc/huoji" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dongdajie2",
  "up" : __DIR__"chanfang",
"north" : __DIR__"yaopuls",
]));
	setup();
	replace_program(ROOM);
}

// Room: /u/aplio/ltsh/jyt.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "聚英堂");
	set("long", @LONG
一进去，首先映入眼帘就是横梁一块黑漆金字牌匾：
　　　　　　　乱世风云，鬼哭神嚎。
　　　　　　　翻云覆雨，唯我独尊。
旁边便是花梨木几椅，用来招呼群雄或帮众汇报大小事务的休息地方。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"tst",
  "out" : __DIR__"shiwai",
]));

	setup();
	replace_program(ROOM);
}

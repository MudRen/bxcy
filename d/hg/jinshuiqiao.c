// Room: /u/cass/hg/jinshuiqiao.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "金水桥");
	set("long", @LONG
一座用汉白玉石打造的石桥，桥身通体洁白，桥的两侧有二百多根
望柱，柱头刻着莲花座，座下为荷叶墩，望柱中间嵌有很多栏板，栏板
内侧与桥面外侧均雕有宝瓶、云纹等图案。每根望柱上还雕刻了好多千
姿百态、生动逼真的石狮。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"wumen",
  "north" : __DIR__"taihemen",
]));
	set("no_new_clean_up", 0);

	setup();
	replace_program(ROOM);
}

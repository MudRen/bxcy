// Room: /u/cass/hg/baohedian.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "保和殿");
	set("long", @LONG
一座单檐鎏金攒尖顶，覆蓝色琉璃瓦的圆殿，穹窿圆顶式天花藻井，层
层收缩，不用横梁，只用柱子支撑和斗拱承托。殿内中央有4 根鎏金雕龙的
龙井柱。四周天花板上布满飞金走彩的各种圆形图案，十分雍容华丽。在殿
的后面，有一座巨大的云龙石雕，上面刻着九龙戏珠于海涛云雾之间。
LONG
);
	set("no_new_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zhonghedian",
  "north" : __DIR__"guangchang",
]));

	setup();
	replace_program(ROOM);
}

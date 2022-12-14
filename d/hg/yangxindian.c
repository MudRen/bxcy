// Room: /u/cass/hg/yangxindian.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "养心殿");
	set("long", @LONG
殿内到处都有用楠木雕刻的龙头，不但藻井每一小格内都有龙，而且梁
枋、雀替也全是楠木雕成的龙，又因不用彩绘，保持原木本色，造成“万龙
聚会，龙口喷香”的气势。若把殿门敞开，楠木香气便会阵阵散发出来，沁
人心肺。
LONG
);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"cining-hy",
  "southeast" : __DIR__"qianqingmen",
  "north" : __DIR__"taijidian",
]));

	setup();
	replace_program(ROOM);
}

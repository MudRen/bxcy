// Room: /u/cass/hg/taijidian.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "太极殿");
	set("long", @LONG
大殿顶部的屋脊，全部是用精致的砖雕和琉璃浮雕，两侧装饰有花样繁多
斗姿争妍的花卉图案和色彩绚丽、造型奇特的五色龙，顶部立有众多的人物和
各种走兽的彩色塑像，形象逼真，生气勃勃。
LONG
);

        set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"yangxindian",
]));

	setup();
	replace_program(ROOM);
}

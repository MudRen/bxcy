// Room: /u/cass/hg/cining-hy.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "慈宁花园");
	set("long", @LONG
园的东部有一个水池，池畔有绕池回廊。回廊粉墙上镶嵌着漏窗。廊中段
的六角亭中，安放着石桌、石凳。廊的尽头有一九脊飞檐的方亭，可以在这儿
倚栏观鱼。园的西部有假山，假山在楼台亭阁的映衬下，加上古树名木点缀其
间，更显得古朴典雅，幽深雄奇。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"cininggong",
  "north" : __DIR__"yangxindian",
]));

	setup();
	replace_program(ROOM);
}

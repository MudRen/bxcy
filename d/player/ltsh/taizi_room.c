// Room: /u/aplio/ltsh/taizi.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "太子竹舍");
	set("long", @LONG
相传太子与正副帮主是幼时好友，情谊至今不变。
又因太子异常爱恋青竹，于是两位帮主特地建造竹舍，
方便太子听琴弄风月。舍中一双鹿角上架着一把当年太子
威震江湖的上古神兵「君临天下」。后面墙上一副对联：
       浮世沧桑远，禅心顿自明。
       万事随缘往，来去若梦行。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"lxg",
]));

	setup();
	replace_program(ROOM);
}

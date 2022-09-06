// Room: /d/quanzhen/jiangbmt.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "江边码头");
	set("long", @LONG
几条青石板搭在一起，就成了一个简陋的小码头了。一个老渔夫
正坐在青石上，手持钓竿正在钓鱼。滚滚江流奔腾而下，无数的旋涡
此起彼伏，但那江中的钓丝却纹丝不动。
LONG
);
	set("outdoors", "quanzhen");
	set("exits", ([ /* sizeof() == 1 */
  "northup" : __DIR__"nanjie1",
]));
        set("objects", ([
                __DIR__"npc/laoyufu" : 1,
        ]));


	setup();
	replace_program(ROOM);
}

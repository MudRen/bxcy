// Room: /d/quanzhen/mengjin/guandao4.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这是一条大道，北面通往孟津渡。道上的行人很多，大多是低
着头自己赶自己的路。忽然在你的身后响起得得的马蹄声，不一会
儿，几匹骏马从你身边飞驰而过，掠起了一片黄沙。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hulao",
  "north" : __DIR__"mengjin-dukou1",
]));
	set("outdoors", "mengjin");

	setup();
	replace_program(ROOM);
}

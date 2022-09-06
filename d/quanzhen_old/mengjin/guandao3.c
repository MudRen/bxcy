// Room: /d/quanzhen/mengjin/guandao3.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这是一条大道，南面通往古孟津渡口。道上的行人很多，大多
是低着头自己赶自己的路。忽然在你的身后响起得得的马蹄声，不
一会儿，几匹骏马从你身边飞驰而过，掠起了一片黄沙。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"guandao2",
  "south" : __DIR__"mengjin-dukou2",
]));
	set("outdoors", "mengjin");

	setup();
	replace_program(ROOM);
}

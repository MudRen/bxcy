// Room: /d/player/garden.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
        set("short", "晚霞大路");
	set("long", @LONG
这里是晚霞的玩家村入口，入口的右边竖着一块用白玉做成的石碑
(stela)左边有一间小房子，房子的上面挂着几个大字“晚霞玩家村治安
亭”。
LONG
);

    set("item_desc", ([
        "stela" : "入村者纳税一百两黄金，手执兵器者不的入内。\n",


    ]));

	setup();
	replace_program(ROOM);
}

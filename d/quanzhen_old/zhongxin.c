// zhongxin.c 中心广场
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "中心广场");
        set("long", @LONG
这里是荆州府的中心广场，荆州府是个小镇，只有四条大街--
分别是东街，西街，南街和北街，都在这里汇合。走到这里，路上
的行人多了些，见了你都和和气气地拱手为礼。
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "east" : __DIR__"dongjie",
                "west" : __DIR__"xijie",
                "north" : __DIR__"beijie",
                "south" : __DIR__"nanjie",
        ]));

        set("objects", ([
                __DIR__"npc/liumang" : 2,
        ]));

        setup();
        replace_program(ROOM);
}

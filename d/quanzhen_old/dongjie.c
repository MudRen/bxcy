// dongjie.c 东街
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "东街");
        set("long", @LONG
这里是荆州府的东街，往东走就是荆州东门了。荆州府是个小
城镇，不算繁华，街上的行人也很稀少。南面是一座大宅院，朱红
大门上布满铜钉。从这里往西走，就是荆州府的中心了。
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "east" : __DIR__"dongmen",
                "west" : __DIR__"zhongxin",
                "south" : __DIR__"fu-damen",
        ]));
        set("objects", ([
                __DIR__"npc/seller" : 1,
        ]));
        setup();
        replace_program(ROOM);
}

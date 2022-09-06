#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","后院");
         set ("long",@long
穿过一个半月形的拱门, 你来到一座小楼之前。小楼檐下一块匾额, 写
着: "云锦楼" 三个墨绿毫字, 楼下前后左右种的都是茶花。但这些茶花
都不过是三四流货色, 和这精致的楼阁亭榭相比, 未免不衬。左右面是
一条长廊，南面是云锦楼。
long);
         set("outdoors","mr");
         set("exits",([
             "south" : __DIR__"yunjinlou",
             "west" : __DIR__"c13",
             "east" : __DIR__"c14-2",
             "north" : __DIR__"xiaojing8",
]));
         setup();
         replace_program(ROOM);
}

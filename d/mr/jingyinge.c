#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","静音阁");
         set("long",@long
这里是修身养性的好场所，这里静悄悄的，没有主人的吩咐，谁也不能
够随便出入这里，在墙上挂着一幅图。
long);
       
       set("valid_startroom", "1");
         set("exits",([
             "east" : __DIR__"neitang",
             "west" : __DIR__"c16-2",
             "south" : __DIR__"c16-5",
	]));
          set("objects", ([
	__DIR__"npc/murong-fu" : 1,
        ]));
         setup();
}
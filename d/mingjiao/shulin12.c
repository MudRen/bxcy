// Room: shulin12.c

inherit ROOM;

void create()
{
        set("short", "树林");
        set("long", @LONG
这是一片偌大的树林，古木参天，遮云蔽日。你进来就迷失了方向，
不知道现在自己身在何处。林中不时传来野兽怪异的低吼和啸叫,令你不
禁毛骨悚然，只想早点离开。

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"shulin11",
  "west" : __DIR__"shulin11",
  "south" : __DIR__"shulin6",
  "east" : __DIR__"shulin",
]));
        set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/huo-chan" : 1,
]));
set("no_clean_up", 0);  	

        setup();
//  27          replace_program(ROOM);	
}
void init()
{
add_action("do_use", "use");
}

int do_use(string arg)
{
object me;
me = this_player();
if( !arg || arg=="" ) return 0; 	
if (!present("fire", me))  return 0;
if( arg=="fire" ) {
write(
"你点燃了火折，隐隐发现东北方有条蜿蜒的小路，不知通向何处。\n");
set("exits/northeast", __DIR__"xuanya");         	
remove_call_out("close");
call_out("close", 20, this_object());
return 1;
}
}

void close(object room)
{
message("vision","火折子的光线渐渐暗了下来。\n", room);
room->delete("exits/northeast");
}


// yadi.c 崖底

#include <room.h>
void init();
int do_dive();
inherit ROOM;

void create()
{
	set("short", "山崖底");
	set("long", @LONG
眼前突然一亮，你看到自己站在山崖底，只见崖底的四周都被高山所包围，无
路可寻。不要说人，就算是鸟也飞不出去。东边有一个只能容一人通过的山洞。
西边有一个小湖（dive），湖水黑黑的，深不见底，给人一种不祥的感觉。
LONG
	);
        set("outdoors", "quanzhen");

         set("objects", ([
                  "/u/brave/obj/qilin":1,
                          ]) );
	set("exits", ([
		"east" : __DIR__"yuxudong",
	]));
	setup();
}

void init()
{
        add_action("do_dive","dive");
}

int do_dive()
{
        object me = this_player();
        message_vision("$N纵身跃起，空中一个浪里翻花，头下脚上，咚的一声潜入湖中不见了.\n", me);
        me->move("/d/quanzhen/hudi1");
        return 1;
}

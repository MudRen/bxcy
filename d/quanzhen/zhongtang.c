// zhongtang.c 中堂 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "中堂");
	set("long", @LONG
这里是掌教待客的地方，靠墙左右两侧摆着一溜太师椅。北
面墙上挂了一付对联。墙角一几，放着几个茶壶。有个茶壶壶身
上题了“碧螺春”三个篆字，壶嘴热气腾腾，似乎是刚沏的新茶。
LONG
	);
        
	set("exits", ([
		"east" : __DIR__"waishi",
		"west" : __DIR__"neishi",
        ]));
	create_door("west", "竹门", "east", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}




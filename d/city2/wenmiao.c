
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "文庙");
	set("long", @LONG
这里是文庙正殿，内有孔夫子像。历代皇帝都懂得利用儒教思想来巩固
自己的江山社稷，当朝皇帝自然也不例外。不论何人到此，都毕恭毕敬地上
香礼拜。
LONG
	);
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("objects", ([
		"/d/city/obj/box" : 1,
		"/d/taishan/npc/shu-sheng" : 1,
"/d/city2/npc/lwshizhe" : 1,       	
	]));
	set("exits", ([
		"west" : __DIR__"xisi",
	]));
	setup();
	replace_program(ROOM);
}

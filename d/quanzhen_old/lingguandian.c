// lingguandian.c 灵官殿

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "灵官殿");
	set("long", @LONG
这里是全真教的灵官殿，走进大殿，迎面见一神将，赤面三目，背
甲持鞭，威风凛凛，他就是民间赫赫有名的道教护法神王灵官。转到神
像背后，财神赵公明，怒目圆睁。岳、马、温、殷四位元帅分立两旁。
LONG
	);
        
	set("exits", ([
		"northeast" : __DIR__"donglang2",
		"south" : __DIR__"donglang1",
       ]));

	set("objects", ([
"/d/quanzhen/npc/sunbuer" : 1]));

	setup();
	replace_program(ROOM);
}




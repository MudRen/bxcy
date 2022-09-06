// Room: chufang.c

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
炊烟缭绕，蒸汽腾腾，香味扑鼻而来。靠墙是一排数丈长的
灶台，支着十来口大锅，最大的一口饭锅上方竟有人从梁上悬空
而下，手持木棍在搅拌。除了烧饭的道士外，几位道童忙着劈柴
运薪，灶下炉火熊熊。一位中年道士正来回催促着。
LONG
	);

	set("exits", ([
		"south" : __DIR__"shitang",
		"northwest" : __DIR__"chufang2",
	]));

//	set("objects",([
//		__DIR__"npc/shaofan-seng" : 2,
//	]));
	setup();
	replace_program(ROOM);
}




// Room: /new/dongdajie3.c
inherit ROOM;
void create()
{
	set("short", "东大街");
	set("long", @LONG
你走在帮内的繁华大街上，看着身着不同服饰各色各样的帮众个个摩拳擦掌、			
兴致高然，谈论着江湖上发生的奇文轨事，禁不住热血沸腾、意气高扬，暗自下
定决心要在江湖上好好作为一番，扬名立万，以树立本帮在江湖上的威望。      
LONG
	);
	set("exits", ([
		"east" : __DIR__"dongdajie4",
		"south" : __DIR__"liangong38",
		"west" : __DIR__"dongdajie2",
		"north" : __DIR__"liangong39",
	]));
	
 setup();
 replace_program(ROOM);
}

// wenwu 2003/8/4 	

inherit ROOM;

void create()
{
	set("short", "会客室");
set("long", "这里就是宫主招待客人的地方，四周金碧辉煌，中间一个桌子上摆放了几色点心，一壶香茶。\n");	

	set("exits", ([
                "north" : __DIR__"jyt",
                "south" : __DIR__"zly",
                "west" : __DIR__"fzws",
                "east" : __DIR__"fzsf",
	]));
	setup();
	replace_program(ROOM);
}


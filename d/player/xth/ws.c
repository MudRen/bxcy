// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "神风堂堂主卧室");
	set("long", "这里是神风堂堂主的卧室，看起来很简陋只在地上铺了一张烂草席！！\n");
        set("no_fight",1);
        set("no_steal",1);
        set("sleep_room",1);
        
	set("exits", ([
                "northeast" : __DIR__"ft1",

	]));
	setup();
	replace_program(ROOM);
}


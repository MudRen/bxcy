// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "灼日堂堂主卧室");
	set("long", "这里是灼日堂堂主的卧室，看起来很简陋只在地上铺了一张烂草席！！\n");
        set("no_fight",1);
        set("no_steal",1);
        set("sleep_room",1);

	set("exits", ([
                "northwest" : __DIR__"dt1",

	]));
	setup();
	replace_program(ROOM);
}


// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "灼日堂大堂");
	set("long", "这里是啸天会的灼日堂大堂，一进门就会看到墙上龙飞凤
舞的一个“迅”字。灼日堂堂主在这儿广交天下群雄，煮酒论
剑，天下英雄皆以能到此一游为荣。从这儿向东就是灼日堂大
厅，南北两处分别是内阁和外室。\n");

	set("exits", ([
                "north" : __DIR__"ng",
		"south" : __DIR__"wais",
                "east" : __DIR__"dt1",
                "northwest" : __DIR__"sclk1",

	]));
	setup();
	replace_program(ROOM);
}


// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "内处室");
	set("long", "  这里是灼日堂的地下室，两边密密麻麻的本子上记录着
灼日堂处理过的大小事情。\n");

	set("exits", ([
                "southup" : __DIR__"dt1",
	]));
	setup();
	replace_program(ROOM);
}


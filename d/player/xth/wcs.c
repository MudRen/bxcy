// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "外处室");
	set("long", "  这里是灼日堂的底下室，两边密密麻麻的本子上记录着
灼日堂外室处理过的大小事情。这里唯一的出路是。\n");

	set("exits", ([
                "northup" : __DIR__"dt1",

	]));
	setup();
	replace_program(ROOM);
}


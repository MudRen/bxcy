// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "采莲池");
	set("long", "这里是府内的一个莲花池，池内开满了莲花，忍
不住想伸手去摘一朵。不过这个池内传言淹死过无数的人！\n");
       
	set("exits", ([
                "west" : __DIR__"yyt",

	]));
	setup();
	replace_program(ROOM);
}


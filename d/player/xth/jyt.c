// wenwu 2003/8/4 	

inherit ROOM;

void create()
{
	set("short", "聚义厅");
set("long", "这里是幽云星宫聚集开会的地方,别看现在空旷的很,只要一有大事发生，就立刻人山人海，水泄不通。\n");	

	set("exits", ([
                "north" : __DIR__"zt",
                "south" : __DIR__"hks",
                "west" : __DIR__"ywt",
                "east" : __DIR__"yyt",
	]));
	setup();
	replace_program(ROOM);
}


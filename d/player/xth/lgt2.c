// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "练功厅");
	set("long", "这里是会中弟子练功的地方，放置了不少木桩木人和铜人
像。四下里还有不少架子放着练功时用的木质兵器。\n");

	set("exits", ([
		"west" : __DIR__"lgf2",
		"north" : __DIR__"lt",
	]));
	setup();
	replace_program(ROOM);
}


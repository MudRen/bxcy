// Room: workroom.c

inherit ROOM;

void create()
{
	set("short", "bingwu的家");
	set("long", @LONG
     这里是bingwu的工作室。
LONG
	);

	set("valid_startroom",1);

	set("exits", ([
		"down": "/d/city/guangchang",
	]));

	setup();
	replace_program(ROOM);
}


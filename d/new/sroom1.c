
inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
这是一条宽阔的青石板街道，向南北两头延伸。两边都是练功区。

LONG );
       set("outdoors", "city");
	set("no_clean_up", 0);
	set("exits", ([
		
              "east" : __DIR__"fight8",
		"north" : __DIR__"guangchang",
		"west" : __DIR__"fight7",
		"south" : __DIR__"sroom2",
	]));

	setup();
	replace_program(ROOM);
}


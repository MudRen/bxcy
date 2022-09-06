
inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
这是一条宽阔的青石板街道，向南北两头延伸。两边都是练功区。

LONG );
       set("outdoors", "city");
	set("no_clean_up", 0);
	set("exits", ([
		
              "east" : __DIR__"fight6",
		"south" : __DIR__"guangchang",
		"west" : __DIR__"fight5",
		"north" : __DIR__"nroom2",
	]));

	setup();
	replace_program(ROOM);
}


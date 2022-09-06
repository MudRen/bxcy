
inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
这是一条宽阔的青石板街道，向东西两头延伸。两边都是练功区。

LONG );
       set("outdoors", "city");
	set("no_clean_up", 0);
	set("exits", ([
		
              "east" : __DIR__"eroom2",
		"south" : __DIR__"fight1",
		"west" : __DIR__"guangchang",
		"north" : __DIR__"fight2",
	]));

	setup();
	replace_program(ROOM);
}



inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
这是一条宽阔的青石板街道，向东西两头延伸。两边都是练功区。

LONG );
       set("outdoors", "city");
	set("no_clean_up", 0);
	set("exits", ([
		
              "east" : __DIR__"guangchang",
		"south" : __DIR__"fight3",
		"west" : __DIR__"wroom2",
		"north" : __DIR__"fight4",
	]));

	setup();
	replace_program(ROOM);
}


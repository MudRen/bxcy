// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "练功室");
set("long", "这里是府中弟子练功的地方，放置了不少木桩木人和铜人像。四下里还有
不少架子放着练功时用的木质兵器。\n");
       
	set("exits", ([
                "west" : __DIR__"zt",

	]));
   set("objects",([
             "/d/shaolin/npc/mu-ren" : 6,
    ]));
	setup();
	replace_program(ROOM);
}


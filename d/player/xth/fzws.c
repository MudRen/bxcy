// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "会长卧室");
	set("long", "这里是会长的卧室，整个房间给人一种很温馨的感觉，使
人更添睡意。\n");
        set("no_fight",1);
        set("no_steal",1);
        set("sleep_room",1);

	set("exits", ([
                "east" : __DIR__"hks",
                "west" : __DIR__"szl",
	]));
	setup();
	replace_program(ROOM);
}


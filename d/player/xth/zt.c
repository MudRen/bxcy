// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "总堂");
	set("long", "这里是啸天会的总堂，南面便是天下闻名的啸天会聚义厅
了。东面是啸天会演义堂，西面是演武堂。\n");
        set("no_fight",1);
        set("no_steal",1);

	set("exits", ([
                "north" : __DIR__"sclk1",
                "south" : __DIR__"jyt",
                  "east" : __DIR__"lgs2",
                 "west" : __DIR__"lgs1",


	]));
	setup();
	replace_program(ROOM);
}


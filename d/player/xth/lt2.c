// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "冷月寒天");
	set("long", "这里是啸天会冷月堂议事的地方，所有冷月堂重大的决定
都由冷月堂堂主和堂主弟子在这儿开会共同决定。这儿出去就
到了冷月堂大厅。\n");

	set("exits", ([
		"east" : __DIR__"lt1",
	]));
	setup();
	replace_program(ROOM);
}


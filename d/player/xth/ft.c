// qjc 2000/5/3 

inherit ROOM;

void create()
{
        set("short", "神风堂大堂");
        set("long", "这里是啸天神风堂大堂。正中墙上写着一个“风”字，下
面放着一张檀木条案摆放着一些精美的瓷器和古玩。神风堂的
弟子都在这里拜见堂主听候堂主的调遣。往北是神风堂的情报
阁，南边是帐房，去西边就到了神风堂大厅了。\n");

	set("exits", ([
                "north" : __DIR__"qbg",
		"south" : __DIR__"bjg",
                "west" : __DIR__"ft1",
                "northeast" : __DIR__"sclk",

	]));
	setup();
	replace_program(ROOM);
}


// by mayue


inherit ROOM;

void create()
{
	set("short", "小村");
	set("long", @LONG
走在小村的石板路上，两旁都是用青石砌成的房屋。村子里静悄悄的，
看不到行人，偶尔传来一两声狗叫。 
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
		"southwest" : __DIR__"cun4",
		"southeast" : __DIR__"cun7",
//		"west" : __DIR__"cun3",
		"north" : __DIR__"minju4",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
    

	setup();
//	replace_program(ROOM);
}


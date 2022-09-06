// Room: /chengdu/xijie.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "西大街");
	set("long", @LONG
这条街满街的招牌幌子，随风飘扬，两边是鳞立栉比的店铺，
还有一些小摊小贩在路边做生意，偶尔有官兵列队经过。北边一
条小巷，进进出出都是些衣冠楚楚的读书人，南边有个当铺。再
向西则是出城的路。
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "east" : __DIR__"xijie1",
                "north" : __DIR__"xiaoxiang",
                "south" : __DIR__"cddangpu",
                "west" : __DIR__"westchengmen",
	]));

	setup();
	replace_program(ROOM);
}


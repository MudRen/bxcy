// Room: /city/dangpu.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "当铺");
	set("long", @LONG
	这是一家以买卖公平著称的当铺，一个五尺高的柜台挡在你的面前，柜台
上摆着一个牌子(paizi)，柜台后坐着唐老板，一双精明的眼睛上上下下打量着你。
LONG
	);
	set("no_beg",1);
	set("item_desc", ([
		"paizi": @TEXT
    本当铺财力雄厚，童叟无欺，欢迎惠顾，绝对保密。客倌可以在这里
看货(list)、购买(buy)、查询已典当货物(check)、估价(value)、典当(pawn)、赎回(redeem)、卖断(sell)各种货物。	
TEXT
	]) );
	set("objects", ([
"/d/city/npc/tang" : 1,	
	]));
	set("exits", ([
		"west" : __DIR__"nandajie1",
	]));
	setup();
	replace_program(ROOM);
}

// Room: /d/quanzhen/mengjin/dadao1.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时地有人骑着马
匆匆而过。大道两旁有一些小货摊，似乎是一处集市。西边通向长安
府。
LONG
);
	set("outdoors", "mengjin");
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/changan/ca33",
  "north" : __DIR__"qiandao",
]));

	setup();
	replace_program(ROOM);
}

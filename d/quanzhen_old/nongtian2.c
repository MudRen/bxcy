// Room: /d/quanzhen/nongtian2.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "农田");
	set("long", @LONG
一片金黄色的麦田。远处的农夫正在喜气洋洋地收割麦子，田边
插着个稻草人。几只麻雀在田里飞着，正叼吃着麦子。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"nongtian2",
  "north" : __DIR__"nongtian2",
  "south" : __DIR__"guangdao3",
  "east" : __DIR__"nongtian1",
]));
        set("objects", ([
                __DIR__"npc/maque" : 2,
                __DIR__"obj/daocaoren" : 1,
]));
	set("outdoors", "quanzhen");

	setup();
	replace_program(ROOM);
}

// Room: /u/cass/hg/wenyuange.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "文渊阁");
	set("long", @LONG
殿堂周环以回廊，24根丹柱绕堂排立，四壁为雕花窗棂。因为这里是
宫内的图书馆，所以这里也是皇子、公主听讲四书、五经之处。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shangshufang",
  "west" : __DIR__"taihedian",
]));

	setup();
	replace_program(ROOM);
}

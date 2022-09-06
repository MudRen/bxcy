// Room: /d/changan/ca34.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "大官道");
	set("long", @LONG
这是一条宽阔笔直的官道，足可容得下十马并驰。两旁是大小
雁塔，往西北则直达长安城。
LONG
);
	set("no_clean_up", 0);
	set("outdoors", 1);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"ta2",
  "northwest" : __DIR__"ca13",
  "south" : "/d/city3/xiaolu1",
  "east" : __DIR__"ta1",
]));

	setup();
	replace_program(ROOM);
}

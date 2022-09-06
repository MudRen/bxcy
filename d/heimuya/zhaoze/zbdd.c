// Room: /u/mei/zhaoze/zbdd.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "江边大道");
	set("long", @LONG
当下不敢向下再看，双眼望前，一步步的终于挨到了桥头。只见江水荡荡
怒涛汹涌，水流湍急，江岸山石壁立，嶙峋巍峨。一条青石大道直通向西。
LONG
);
	set("outdoors", "zbdd");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"tsq",
  "west" : "/d/tianlongsi/dadao1",
]));

	setup();
	replace_program(ROOM);
}

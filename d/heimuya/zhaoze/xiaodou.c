// Room: /u/mei/zhaoze/xiaodou.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "无量山界");
	set("long", @LONG
只见眼前一列青山，山势非常险要，一条小道沿着山势盘旋而上。
西南有一条青石小道不只通往何方。
LONG
);
	set("outdoors", "xiaodou");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room16",
  "southwest" : "/d/wudujiao/cun9",
  "westup" : __DIR__"xiaodao",
]));

	setup();
	replace_program(ROOM);
}

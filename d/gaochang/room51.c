// Room: /u/mei/room51.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "星星峡");
	set("long", @LONG
远处出现了一抹岗峦。转眼之间，石壁越来越近，一字排开，直伸出去，山
石间云雾瀰漫，似乎其中别有天地，再走近时，忽觉峭壁中间露出一条缝来，沿
山道直走进去，便是甘肃和回疆之间的交通孔道星星峡。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room52",
  "east" : __DIR__"room4",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room51");

	setup();
	replace_program(ROOM);
}

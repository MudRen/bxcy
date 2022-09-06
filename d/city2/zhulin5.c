// Room: /d/city2/zhulin5.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "竹林小道");
	set("long", @LONG
四周都是密密的竹林，一踏进这里你就迷了路。这里人迹罕至，
惟闻足踏草坪之声。偶尔有微风轻拂竹叶，又如簌簌禅唱，令人尘
心为之一涤，真是绝佳的清修所在。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "north" : (: look_door,     "north" :),
]));
	set("exits", ([ /* sizeof() == 5 */
  "southwest" : __DIR__"zhulin5.c",
  "west" : __DIR__"zhulin5.c",
  "northeast" : __DIR__"zhulin5.c",
  "south" : __DIR__"zhulin4",
  "east" : __DIR__"zhulin5.c",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "city2");
	setup();
	replace_program(ROOM);
}

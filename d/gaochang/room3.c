// Room: /u/mei/room3.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "破旧长城");
	set("long", @LONG
昔日雄伟的长城已面目全非，岁月和战争已几乎把它夷为平地。唯一仅
存的一点废墟，都被历代英雄的鲜血染成暗红色。这里虽然是一片萧杀，却
有几株小树从碎石的缝隙中挤出，给人以一线生机的感觉。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"room4",
  "east" : __DIR__"room2",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room3");

	setup();
	replace_program(ROOM);
}

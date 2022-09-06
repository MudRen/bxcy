// Room: /u/mei/room8.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "大漠风光");
	set("long", @LONG
地势到这是豁然开朗，你的西边是一望无际的沙漠。狂风在呼哮，漫天
黄沙在飞舞，飞沙滚滚。沙砾打在你的身上，就像是苍穹怒投下的冰雹。冥
冥中仿佛已有种邪恶的力量，任何人随时都有可能突然像野狗般死在沙砾
上。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room9",
  "east" : __DIR__"room7",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room8");

	setup();
	replace_program(ROOM);
}

// Room: /u/mei/room28.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "小屋");
	set("long", @LONG
这地方极是干燥，草木不生，屋中物品虽然经历了不知多少年月，但大部
仍然完好。厅上有一双女人的花鞋，色泽仍是颇为鲜艳，想拿起来细看，哪知
触手间登时化为灰尘，不由得吓了一跳。
LONG
	);
	set("no_new_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room26",
]));

	setup();
	replace_program(ROOM);
}

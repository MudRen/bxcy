// Room: /u/aplio/ltsh/tst.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "地煞堂");
	set("long", @LONG
龙腾四海一般都在地煞堂由堂主，处理奖罚帮众。再上一层，便是最高荣誉
帮内之才晋见正副帮主的总堂。平庸之人，只怕一生亦无此福分。
LONG
);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/saveme" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"lxg",
  "westdown" : __DIR__"jyt",
]));

	setup();
	replace_program(ROOM);
}

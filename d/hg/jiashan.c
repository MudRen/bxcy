// Room: /u/cass/hg/jiashan.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "假山");
	set("long", @LONG
只见迎面一座翠嶂挡在前面，白石狞狰，或如鬼怪，或如野兽，纵横拱
立，上面苔藓成斑，藤萝掩映，其中微露一条羊肠小径，似乎是通向石洞。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"yuhuayuan",
  "north" : __DIR__"shidong",
]));

	setup();
	replace_program(ROOM);
}

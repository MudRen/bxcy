// Room: /d/huashan/bingqifang.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "兵器房");
	set("long", @LONG
    这里是华山派的兵器房，四周放这几个兵器架，上面是华山派各
弟子平时练剑用的竹剑。
LONG
);
	set("objects", ([ /* sizeof() == 1 */
  "/d/village/obj/zhujian" : 4,
]));
	set("no_new_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"square",
  "east" : __DIR__"liangong1",
]));
	set("no_fight", 1);

	setup();
	replace_program(ROOM);
}

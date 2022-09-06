// Room: /d/quanzhen/mengjin/qiandao.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
在这峰峦拱持、沟壑纵横的险要路途上，有时一边是断崖峭壁
耸入青天，另一边则是可使人马粉身碎骨的万丈深沟，德水在左方
远处脚下轰隆流过。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shanlu",
  "south" : __DIR__"dadao1",
]));
	set("outdoors", "mengjin");

	setup();
	replace_program(ROOM);
}

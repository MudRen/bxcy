// Room: /u/wyz/jingzhou/room6.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "城墙");
	set("long", @LONG
丈许宽的城墙又高又厚，给人一种安全的感觉。遥望城外，绿色的田野一望无垠，
一座座小小的农房星星点点的点缀着宽广的田野，傍晚时，炊烟袅袅，夕阳斜照，美
不胜收。远处连绵的群山更是令人感到威武壮观。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room5",
  "west" : __DIR__"room7",
]));

	setup();
	replace_program(ROOM);
}

// Room: /u/mei/zhaoze/room1.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "小桥");
	set("long", @LONG
这是一座小竹桥，一条清澈的小溪从桥下缓缓流过。不时有顽皮
的小鱼跃出水面，在阳光下划出一条银白色的弧线。
LONG
	);
	set("outdoors", "room1");
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"room2",
  "northeast" : "/d/heimuya/guang",
]));

	setup();
	replace_program(ROOM);
}

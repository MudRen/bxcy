// Room: /u/cass/hg/zhonglou.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "��¥");
	set("long", @LONG
һ��ֱ�����𡢻�ǽ���ߵĸ�¥��¥����һ���ش�ͭ�ӡ�
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wumen",
]));

	setup();
	replace_program(ROOM);
}

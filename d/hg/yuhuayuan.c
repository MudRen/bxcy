// Room: /u/cass/hg/yuhuayuan.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "����԰");
	set("long", @LONG
԰������Ͱ�������ߣ����������񣬽���ϸ�����ʻ������������Ϳ�Σ�
һɫˮĥȺǽ�����ʯ̨����������ݻ���������һ����ѩ�׷�ǽ���滢
Ƥʯ������ȥ����Ȼ���主�����ס�
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"kunninggong",
  "north" : __DIR__"jiashan",
]));

	setup();
	replace_program(ROOM);
}

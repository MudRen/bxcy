// Room: /u/cass/hg/gulou.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "��¥");
	set("long", @LONG
һ�����ܵ�ľ����¥����ǽ�����������������޼����ܣ�������ӳ����
�Ե���ΰ׳����¥����һ��ţƤ��ġ�
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wumen",
]));

	setup();
	replace_program(ROOM);
}

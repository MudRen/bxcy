// Room: /u/cass/hg/wanchunting.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "��ͤ");
	set("long", @LONG
һ��Ρ�������ܵĻ����Ľ��ܼⶥͤ��ͤ����һ�ž���ͤ����������
���и�����������գ���Ӱӳ�뾮�ף����ž�ˮ�ζ����������裬�ʳơ�
������������ͤңң��Եľ���ǧ��ͤ��
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"qianqiuting",
  "northwest" : __DIR__"qinandian",
]));

	setup();
	replace_program(ROOM);
}

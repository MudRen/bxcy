// Room: /u/cass/hg/taihedian2.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "̫�͵�¶̨�㳡");
	set("long", @LONG
¶̨�϶������У�������ʱ�������������ȫ����׼��������ǰ�й㳡��
�м����þ�ʯ�̾͵�������������ĥש�Է�ĺ�ܬ��ש�������������̶�ʯ��
�������Է���ͭ��Ʒ��ɽ�����е���ʱ�����Ǹ�����ݹ���Ʒ��ɽ�ԡ�
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"taihedian",
]));

	setup();
	replace_program(ROOM);
}

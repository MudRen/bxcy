// Room: /u/cass/hg/baohedian.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "���͵�");
	set("long", @LONG
һ�������̽��ܼⶥ������ɫ�����ߵ�Բ����Բ��ʽ�컨�微����
�����������ú�����ֻ������֧�źͶ������С�����������4 ���̽������
�������������컨���ϲ����ɽ��߲ʵĸ���Բ��ͼ����ʮ��Ӻ�ݻ������ڵ�
�ĺ��棬��һ���޴������ʯ��������ž���Ϸ���ں�������֮�䡣
LONG
);
	set("no_new_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zhonghedian",
  "north" : __DIR__"guangchang",
]));

	setup();
	replace_program(ROOM);
}

// Room: /u/cass/hg/taihedian.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "̫�͵�");
	set("long", @LONG
������������׳Ƶġ����ǵ�������İ��е���ʻ�˫���������
�𡣵��ڹ����������������������Լ���׸ߵ�ƽ̨������һ���ľ�����
�����������Ϸ����۽����Σ��κ����۽�������硣���������жԳƵı���
�Ƕˡ��ɺס���Ͳ����Ʒ�������Ϊ�¡Բ�����ֳ��微�����ھ�����ԣ�
���α��飬����ԯ�����������Ա��������������Ž�ש���������ӳ�յ�
��̻Իͣ������ޱȡ�
LONG
);
	set("no_new_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"taihemen",
  "north" : __DIR__"zhonghedian",
  "west" : __DIR__"taihedian2",
]));

	setup();
	replace_program(ROOM);
}

// Room: /u/cass/hg/longtan.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "��̶");
	set("long", @LONG
һ�ɾ�Ө��Ȫˮ����ͷ������ӿ�������ϱ�����ʯ�ۻ���������ˮ��ɽ
ת����������������������
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"quqiao",
  "west" : __DIR__"pubu",
]));

	setup();
	replace_program(ROOM);
}

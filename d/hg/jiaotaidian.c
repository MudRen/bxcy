// Room: /u/cass/hg/jiaotaidian.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "��̩��");
	set("long", @LONG
�������Ъɽ���������Ƴ����ܾ��ﱧ�ã������̼��ߣ������̽ǣ���
�����������ھ�������Ĩ������������������Ķ��໹���м�ʱ��������©
��¥���������ӡ�
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"qianqinggong",
  "north" : __DIR__"kunninggong",
]));

	setup();
	replace_program(ROOM);
}

// Room: /u/cass/hg/kunninggong.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���ڻ���ʯܬ�أ���ʯ���϶�����ɫ���ƣ���ʶ�Ŀ�������ñ�ʯ����
�����ԡ��������ÿ���ƻ�ʱ���ζ��Ŵ����������������������������Ϻ�
��ɫ�����ڻ�ɫ�ذ��Ϲ�����
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"jiaotaidian",
  "north" : __DIR__"yuhuayuan",
]));

	setup();
	replace_program(ROOM);
}

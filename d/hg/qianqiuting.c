// Room: /u/cass/hg/qianqiuting.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "ǧ��ͤ");
	set("long", @LONG
һ��ʮ�ֽἹ���ܷ�ͤ�����������������������Ե�������ۼ��̨ͤ
���ư��磬�������ԡ�ͤ�ڵ�ľ���Ͽ���һ��������
                ��Ӱ��бˮ��ǳ��
                ���㸡���»ƻ衣
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"wanchunting",
  "northeast" : __DIR__"qinandian",
]));

	setup();
	replace_program(ROOM);
}

// Room: /u/cass/hg/huangjidian.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "�ʼ���");
	set("long", @LONG
��̽�ͭ�����ûƽ��̳ɣ����ϰ������������ϣ����£������Ƽ�
�������ıڵĲ�ɫ�ڻ������ݷḻ��ɫ��Ѥ����
LONG
);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"jiulongbi",
  "southwest" : __DIR__"fengxiandian",
  "north" : __DIR__"ningshougong",
]));

	setup();
	replace_program(ROOM);
}

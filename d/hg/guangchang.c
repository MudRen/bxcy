// Room: /u/cass/hg/guangchang.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "�㳡");
	set("long", @LONG
�㳡�������ô���ʯΧ���ɵ�ƽ̨�������˹�������������衣�Ľ�
�������ͷ���ͭ����̳�ϡ���ɫֲ�ﴹ�Ҷ��£�ƽ̨�м����³�ʽ��ˮ�أ�
���ƹ����䣬���������ɾ���ƽ̨����Χ�л���ʯ���ƣ�Ȩ�����ʣ�����
����
LONG
);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"baohedian",
  "northeast" : __DIR__"fengxiandian",
  "northwest" : __DIR__"qianqingmen",
]));

	setup();
	replace_program(ROOM);
}

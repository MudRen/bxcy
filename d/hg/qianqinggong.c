// Room: /u/cass/hg/qianqinggong.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "Ǭ�幬");
	set("long", @LONG
������������ᱦ������������������һ�����С��������������
��ٴ�����������ɺ���̺���������Ŵ���Ǯ��������ʯ���Ǯ��
��������ɫ��Ǯ�������죬�ӵ�������һ��÷��ʽ����С������߼�
��������������У��ұ߼������������----���ڲ���ʱ�ʻ��ܡ�����
����һ���������ϣ����������������δ�����ĸ���̤���ε����ߣ�
Ҳ��һ�Ը߼�����������ƿ�����㡣
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"qianqingmen",
  "north" : __DIR__"jiaotaidian",
]));
	set("no_new_clean_up", 0);

	setup();
	replace_program(ROOM);
}

// Room: /u/cass/hg/fengxiandian.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "���ȵ�");
	set("long", @LONG
���Ϊ�����е���м���������������������ǣ��ر�����עĿ��
���ڻ������������������ʵ�ƽ����ȫ����̲ʻ棬�����Ը�������
�ŵĸо���
LONG
);
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"taihemen",
  "west" : __DIR__"qianqingmen",
  "northeast" : __DIR__"huangjidian",
]));

	setup();
	replace_program(ROOM);
}

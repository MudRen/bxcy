// Room: /u/cass/hg/yangxindian.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "���ĵ�");
	set("long", @LONG
���ڵ����������ľ��̵���ͷ�������微ÿһС���ڶ�������������
�ʡ�ȸ��Ҳȫ���ľ��ɵ����������òʻ棬����ԭľ��ɫ����ɡ�����
�ۻᣬ�������㡱�����ơ����ѵ��ų������ľ�����������ɢ����������
���ķΡ�
LONG
);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"cining-hy",
  "southeast" : __DIR__"qianqingmen",
  "north" : __DIR__"taijidian",
]));

	setup();
	replace_program(ROOM);
}

// Room: /d/xiaoyao/shulin1.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һƬï�ܵ����֡��ܶ�ü�ʮ�ɸߵĴ�������һ�飬��һ�Ѱ�����
��ɡ�������¶����ڱεð�Ȼ�޹⡣�����л���ʱ������������Ȼ���������졣
LONG
);
	set("objects", ([ /* sizeof() == 1 */
  "/d/mengpai/xydizi" : 3,
]));
	set("outdoors", "xiaoyao");
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"xiaodao4",
  "north" : __DIR__"shulin1",
  "east" : __DIR__"shulin2",
  "south" : __DIR__"shulin1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

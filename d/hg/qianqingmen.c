// Room: /u/cass/hg/qianqingmen.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "Ǭ����");
	set("long", @LONG
Ǭ��������͢�����ţ��ʵ���ʱ�ڴ��������ơ����������������ھ�
�Ǻ������ˡ�
LONG
);
	set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"yangxindian",
  "east" : __DIR__"fengxiandian",
  "southeast" : __DIR__"guangchang",
  "north" : __DIR__"qianqinggong",
]));

	setup();
	replace_program(ROOM);
}

// Room: /d/quanzhen/nanjie.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "�Ͻ�");
	set("long", @LONG
�����Ǿ��ݵ��Ͻ֣�˵�ǽ֣�������һ��С��ͬ���ѡ�·��һ��
��Ҳû�С��ֵ�������һ��С�š������������������书��������ˡ�
LONG
);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"nanjie1",
  "southeast" : __DIR__"fu-cemen",
  "north" : __DIR__"zhongxin",
]));
	set("outdoors", "quanzhen");

	setup();
	replace_program(ROOM);
}

// Room: /d/quanzhen/nanjie1.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "�Ͻ�");
	set("long", @LONG
�����Ǿ��ݵ��Ͻ֣�˵�ǽ֣�������һ��С��ͬ���ѡ�·��һ��
��Ҳû�С��ֵ��϶���һС���ţ�͸�����ţ��ɼ������Ľ�����
LONG
);
	set("outdoors", "quanzhen");
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"jiangbmt",
  "north" : __DIR__"nanjie",
]));

	setup();
	replace_program(ROOM);
}

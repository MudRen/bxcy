// Room: /d/quanzhen/nongtian5.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "ũ��");
	set("long", @LONG
һƬ���ɫ�����Զ����ũ������ϲ��������ո����ӣ����
���Ÿ������ˡ���ֻ��ȸ��������ţ�����������ӡ�
LONG
);
	set("outdoors", "quanzhen");
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"nongtian4",
  "north" : __DIR__"nongtian5",
  "south" : __DIR__"nongtian5",
  "east" : __DIR__"nongtian5",
]));

	setup();
	replace_program(ROOM);
}

// Room: /u/cass/hg/cininggong.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�Ͳ���߸��ǣ�����ɫ�������ߣ�������һ�����ӣ���������������
һ�ܳ��е����������װ��ϸ�¾��ɵ��������޺ͻ��ܣ���������һȦ��
�񸡵�����һΧ��������������ڵ�ů���ǻ�̫���ס�ĵط���
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"neishi",
  "north" : __DIR__"cining-hy",
]));

	setup();
	replace_program(ROOM);
}

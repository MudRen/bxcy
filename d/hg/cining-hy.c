// Room: /u/cass/hg/cining-hy.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "������԰");
	set("long", @LONG
԰�Ķ�����һ��ˮ�أ��������Ƴػ��ȡ����ȷ�ǽ����Ƕ��©�������ж�
������ͤ�У�������ʯ����ʯ�ʡ��ȵľ�ͷ��һ�ż����ܵķ�ͤ�����������
�������㡣԰�������м�ɽ����ɽ��¥̨ͤ���ӳ���£����Ϲ�����ľ��׺��
�䣬���Եù��ӵ��ţ��������档
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"cininggong",
  "north" : __DIR__"yangxindian",
]));

	setup();
	replace_program(ROOM);
}

// Room: /u/mei/zhaoze/tsq.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���·���������̤���Ű塣���Ź��������������������£�����ľ�壬��
�����ߣ�����������Ϊ���֡�һ̤���ţ����������㼴�϶����е����ģ�����
�εø���������һƳ�ۼ䣬������ˮ����������������ĭ����������ڰ�ӽ�
�׷ɹ���ֻҪһ��ʧ�㣬���뽭ˮ�������õ�ˮ��Ҳ�ѻ�����
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lczb1",
  "west" : __DIR__"zbdd",
]));
	set("outdoors", "tsq");

	setup();
	replace_program(ROOM);
}
// Room: /d/quanzhen/mengjin/qiandao.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������͹��֡������ݺ����Ҫ·;�ϣ���ʱһ���Ƕ����ͱ�
�������죬��һ�����ǿ�ʹ���������ǵ����������ˮ����
Զ�����º�¡������
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shanlu",
  "south" : __DIR__"dadao1",
]));
	set("outdoors", "mengjin");

	setup();
	replace_program(ROOM);
}

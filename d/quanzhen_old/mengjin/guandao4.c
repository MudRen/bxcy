// Room: /d/quanzhen/mengjin/guandao4.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
����һ�����������ͨ���Ͻ�ɡ����ϵ����˺ܶ࣬����ǵ�
��ͷ�Լ����Լ���·����Ȼ������������õõ�����������һ��
������ƥ���������߷ɳ۶�����������һƬ��ɳ��
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hulao",
  "north" : __DIR__"mengjin-dukou1",
]));
	set("outdoors", "mengjin");

	setup();
	replace_program(ROOM);
}

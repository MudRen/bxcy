// Room: /d/quanzhen/mengjin/guandao3.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
����һ�����������ͨ�����Ͻ�ɿڡ����ϵ����˺ܶ࣬���
�ǵ���ͷ�Լ����Լ���·����Ȼ������������õõ�����������
һ�������ƥ���������߷ɳ۶�����������һƬ��ɳ��
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"guandao2",
  "south" : __DIR__"mengjin-dukou2",
]));
	set("outdoors", "mengjin");

	setup();
	replace_program(ROOM);
}

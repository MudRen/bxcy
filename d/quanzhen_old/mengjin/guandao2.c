// Room: /d/quanzhen/mengjin/guandao2.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
����һ�����������ͨ�����ݸ������ϵ����˺ܶ࣬����ǵ�
��ͷ�Լ����Լ���·����Ȼ������������õõ�����������һ��
������ƥ���������߷ɳ۶�����������һƬ��ɳ��
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"guandao3",
  "east" : __DIR__"guandao1",
]));
	set("outdoors", "mengjin");

	setup();
	replace_program(ROOM);
}

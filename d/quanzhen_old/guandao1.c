// Room: /d/quanzhen/guandao1.c
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
	set("no_clean_up", 0);
	set("outdoors", "quanzhen");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"guandao2",
  "east" : __DIR__"guangdao4",
]));

	setup();
	replace_program(ROOM);
}

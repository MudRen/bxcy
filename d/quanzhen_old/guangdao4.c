// Room: /d/quanzhen/guangdao4.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
���������ڴ���ϵĹٵ���һ���Ǵ�����Ϣ�Ĺ���������һ����
���ֵ�ũ�ũ������������æ���ո�ӡ��ٵ�������������ʮ��
���֡�
LONG
);
	set("outdoors", "quanzhen");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"guandao1",
  "east" : __DIR__"guangdao3",
]));

	setup();
	replace_program(ROOM);
}

// Room: /d/quanzhen/guangdao2.c
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
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"nongtian1",
  "west" : __DIR__"guangdao3",
  "east" : __DIR__"guangdao1",
]));

	setup();
	replace_program(ROOM);
}

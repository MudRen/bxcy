// Room: /d/quanzhen/guangdao1.c
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
  "west" : __DIR__"guangdao2",
  "east" : "/d/nanyang/hanshui2",
]));

	setup();
	replace_program(ROOM);
}

// Room: /u/aplio/ltsh/tnt_room.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "���Ǻ���");
	set("long", @LONG
������Ȼ���壬���ò��Ὥ�������������ѧ��ʦ��С����
������ӵ�и߳����书���Ƕ�Ϥ������츳���ܲ����˲���˼�顣
����Ȼ��Ȼ��������Ϊ�ϱ������Ǻ��������רΪ��λ��ʦ����
�ľ��ᡣ
�����������������������ң�
������������ӹ�������ѿ��ѡ�
������������ÿ�Ǹ�͸�����ˣ�
������������Ը���������ɻ�
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"lxg",
]));

	setup();
	replace_program(ROOM);
}

// Room: /u/cass/hg/jiulongbi.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
ȫ������ɫ�������ɣ�˫�����������о�����Ϸ���ڲ��κ���֮�У�
��̬���죬�������������ϣ��������桢�������༰��Ͳ�ߡ���ש�ϻ�
�����������ڶ���ɽ��Ƕ�к�ˮ�����ơ��ճ�ͼ��������ɽ��Ƕ�к�ˮ��
���ơ�����ͼ���������ɫ��
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"huangjidian",
]));

	setup();
	replace_program(ROOM);
}

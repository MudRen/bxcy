// Room: /u/cass/hg/taijidian.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "̫����");
	set("long", @LONG
�������ݼ���ȫ�����þ��µ�ש���������������װ���л�������
���������Ļ���ͼ����ɫ��Ѥ�����������ص���ɫ�������������ڶ�������
�������޵Ĳ�ɫ����������棬����������
LONG
);

        set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"yangxindian",
]));

	setup();
	replace_program(ROOM);
}

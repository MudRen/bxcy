// Room: /d/new/liangong37.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ǹ������ֵ�����ϰ��ĵط����м�����������ר�����µ�����
���м����ֱֳ���,�ڻ������,���鶯������������ڵ��ϵ�������
����������
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dongdajie2",
]));
	set("objects", ([ /* sizeof() == 1 */
"/d/new/npc/tong-ren" : 4,	
]));
	set("no_new_clean_up", 0);

	setup();
	replace_program(ROOM);
}

// Room: /u/cass/hg/yanyuhu.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
��ˮ�����峺������һ�ž�Ө�貵��̱�ʯ�������ϻ���ֲ�˸��ֺɻ���
������һ��������Χ�ƵĹۺ�С¥����������Զ�������н�����Ҷ����̣�
����ϸ���������������������ʣ���ɫȫ������֮�С�����ҹ�����µ��գ�
��������ʫ�黭�⡣
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"quqiao",
]));
set("objects", ([	
"/d/hg/npc/queen" : 1,          	
]));	

	setup();
	replace_program(ROOM);
}

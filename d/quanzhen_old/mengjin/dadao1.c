// Room: /d/quanzhen/mengjin/dadao1.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ������������
�ҴҶ��������������һЩС��̯���ƺ���һ�����С�����ͨ�򳤰�
����
LONG
);
	set("outdoors", "mengjin");
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/changan/ca33",
  "north" : __DIR__"qiandao",
]));

	setup();
	replace_program(ROOM);
}

// Room: /u/mei/zhaoze/xiaodao.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
ֻ����ˮ�����ȣ�ǰ������ɽϪ��Ѱ������Ϫ�ԣ��¹���Ϫˮ�峺��
����Բ������Ӱ��ӳϪ�У��Ե������ޱȡ�
LONG
);
	set("outdoors", "xiaodao");
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"xiaodou",
  "northup" : __DIR__"pubu",
]));

	setup();
	replace_program(ROOM);
}
